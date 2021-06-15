/** @file LargeInteger.cpp
 *
 * @brief Implementation file for Assignment Classes and Memory,
 *   practice with classes and dynamic memory allocation.
 *
 * @author Jane Programmer
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Classes and Memory
 * @date   June 1, 2021
 *
 * LargeInteger class.  This is the class implementation file. It
 * contains the implementation of all of the member functions declared
 * in the header file.  Since implementation is separated from the
 * declaration of each member function, you must indicate each
 * function is a member of the LargeIneger class by prepending member
 * function name with LargeInteger::
 */
#include "LargeInteger.hpp"

using namespace std;

// integer to create unique id for new LargeInteger instances
// please set and use this in the same way in the constructor you
// create for this assignment
static int nextLargeIntegerId = 1;

/** @brief LargeInteger default constructor
 *
 * Default constructor for LargeInteger class. By default we construct
 * with a value of 0 being represented.
 */
LargeInteger::LargeInteger()
{
  // set this instance id
  id = nextLargeIntegerId++;

  // only a single digit
  numDigits = 1;

  // allocate an array of the right size
  digit = new int[numDigits];

  // initialize the digit to 0
  digit[0] = 0;
}

/** @brief LargeInteger from int constructor
 *
 * Constructor for LargeInteger class that takes a simple built-in
 * integer to be used as the initial value of the large integer.
 *
 * @param value A regular (32-bit) integer that we will use as the
 *    initial value of this LargeInteger data type.
 */
LargeInteger::LargeInteger(int value)
{
  // set this instance id
  id = nextLargeIntegerId++;

  // first determine number of digits, so we know what size of array
  // to construct dynamically
  // https://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer
  numDigits = (int)log10((double)value) + 1;

  // allocate an array of the right size
  digit = new int[numDigits];

  // iterate through the digits in value, putting them into our
  // array of digits.
  int nextDigit;
  for (int digitIndex = 0; digitIndex < numDigits; digitIndex++)
  {
    // least significant digit
    nextDigit = value % 10;
    digit[digitIndex] = nextDigit;

    // integer division to chop off least significant digit
    value = value / 10;
  }
}

/** @brief LargeInteger array based constructor
 *
 * Constructor for LargeInteger class that takes an array of digits
 * and initializes this large integers digits to the given values.
 *
 * @param numDigits The number of digits being passed in to be
 *   initialized.
 * @param digit An array of integers representing digits of a
 *   large integer to be constructed.
 */
LargeInteger::LargeInteger(int numDigits, int digit[])
{
  // set this instance id
  id = nextLargeIntegerId++;

  // allocate an array to copy the digits into
  this->numDigits = numDigits;
  this->digit = new int[numDigits];

  // copy digits to this array of digits
  for (int position = 0; position < numDigits; position++)
  {
    this->digit[position] = digit[position];
  }
}

/** @brief LargeInteger destructor
 *
 * Destructor for the LargeInteger class.  Make sure we are good
 * managers of memory by freeing up our digits when this object
 * goes out of scope.
 */
LargeInteger::~LargeInteger()
{
  // uncomment following output statement to debug/follow destruction of
  // LargeInteger instances
  // cout << "<LargeInteger::~LargeInteger> destructor entered, freeing my digits" << endl
  //     << "     id = " << id << endl
  //     << "     value=" << tostring() << endl;
  delete[] this->digit;
}

/** @brief LargeInteger tostring
 *
 * Represent this large integer as a string value
 *
 * @returns string The large integer as a string
 */
string LargeInteger::tostring() const
{
  ostringstream out;

  // most significant digit is in highest position, so go
  // backwards through our array of digits
  for (int position = numDigits - 1; position >= 0; position--)
  {
    out << digit[position];
  }

  // convert the ostringstream to a regular string to return it
  return out.str();
}

/** @brief Maximum number of digits
 *
 * Return the larger of the number of digits (numDigits) between
 * this object and the other LargeInteger object.  This might
 * not be so useful to users of this data type, but the first
 * step in addition and subtraction is to determine the size
 * we need for the new result array, which will either be the
 * larger numDigits of the two objects being added, or that value
 * plus 1 if there is cary from the addition.
 *
 * @param other Another LargeInteger object that we are to compare
 *   this object numDigits to
 *
 * @returns int The larger (max) of the numDigits of the two
 *   referenced objects.
 */
int LargeInteger::maxDigits(const LargeInteger& other) const
{
  // max comes from STL algorithms
  return max(this->numDigits, other.numDigits);
}

/** @brief Digit at position
 *
 * Given a position, return the digit at the given index of
 * this LargeInteger.  The digitIndex passed in refers to
 * the place or power of the digit needed.  For example
 * 0 means we want the 10^0 or the 1's place, 1 means we
 * need the 10^1 or the 10s place digit, etc.  If the
 * requested digit index is bigger than the number of places
 * in the LargeInteger then 0 is returned.  For example, if this
 * LargeInteger represents the number 123, and we ask for the
 * 4th place (10^4 or the 1000s place), this function will
 * return 0.
 *
 * @param position The index, interpreted as the place or power,
 *   of the specific digit to be accessed and returned.
 *
 * @returns int The digit in the 10^position place of this
 *   LargeInteger object.
 */
int LargeInteger::digitAtPosition(int position) const
{
  // if digit position is greater than our numDigits, then we have
  // 0 at that position
  if ((position >= numDigits) or (position < 0))
  {
    return 0;
  }
  else // return the indicated place/index
  {
    return digit[position];
  }
}

/** @brief Append digit
 *
 * Append the indicated digit to the most significant place of this
 * digit.  This function is not so useful to users of LargeInteger.
 * However, for arithemetic operations, if there is carry over from
 * the last operations (like carry from adding the most significant
 * place of two integers), then the LargeInteger has to grow in size.
 *
 * @param digit The digit to append to the most significant place
 *   of this object.
 */
void LargeInteger::appendDigit(int digit)
{
  // ignore request to append a 0 to most significant place
  if (digit == 0)
  {
    return;
  }

  // allocate a new array
  int numNewDigits = numDigits + 1;
  int* newDigit = new int[numNewDigits];

  // copy the current digits into new
  // NOTE: we only copy up to the size of the old array, up to numDigits
  for (int position = 0; position < numDigits; position++)
  {
    newDigit[position] = this->digit[position];
  }

  // append/add the new most significat digit to most significnat place
  newDigit[numDigits] = digit;

  // do memory management, free up the unused digits, and start using
  // the newly allocated space as our actual digits
  delete[] this->digit;
  this->digit = newDigit; // they both now point to the new allocated space
  numDigits = numNewDigits;
}

/** @brief Add large integers
 *
 * Add this LargeInteger to the other LargeInteger passed in as
 * a parameter.
 *
 * @param other Another LargeInteger data type.
 *
 * @returns LargeInteger& Returns a reference to a newly created
 *   LargeInteger which contains the value of the this added
 *   with other.
 */
LargeInteger& LargeInteger::add(const LargeInteger& other) const
{
  // how big will result need to be?
  int numNewDigits = maxDigits(other);

  // allocate enough memory to hold result
  int* newDigits = new int[numNewDigits];

  // perform the addition, from least significant to most significant
  // digit, carrying if necessary
  int newDigit;
  int carry = 0;
  for (int position = 0; position < numNewDigits; position++)
  {
    newDigit = this->digitAtPosition(position) + other.digitAtPosition(position) + carry;

    // extract the digit and the value to carry
    carry = newDigit / 10;    // result of integer division, so if result is 15 then 15 / 10 = 1
    newDigit = newDigit % 10; // remainder is value from 0-9, so if result is 15 then 15 % 10 == 5

    // put new digit into the array of digits at the correct
    // index
    newDigits[position] = newDigit;
  }

  // now make the resulting new LargeInteger, and manage our memory
  LargeInteger* res = new LargeInteger(numNewDigits, newDigits);
  delete[] newDigits; // the new LargeInteger allocated its own space, so we can free ours now

  // One last task, if there was a carry from addition of the final
  // most significant digit, we need to grow the new LargeInteger and
  // append the carry result
  res->appendDigit(carry);

  return *res;
}