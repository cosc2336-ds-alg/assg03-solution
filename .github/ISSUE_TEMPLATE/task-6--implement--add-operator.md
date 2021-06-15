---
name: 'Task 6: Implement `add()` Operation'
about: Task 6 for Students
title: 'Task 6: Implement `add()` Operation'
labels: enhancement
assignees: ''

---

**Description**

The whole purpose of this `LargeInteger` class is to be able to represent large integers so that we could perform normal arithmetic operations, like adding them, subtracting them, multiplying them, etc.  So while we won't implement anything else besides the `add()` operation for this assignment, you should have a general idea of how you might complete this class to support other arithmetic operations like this.

Most all of the previous member functions were created specifically to ease the implementation of the `add()` operation.  You will need to reuse all of the functions you created in your implementation of `add()` here.  `add()` if it is not clear will take 2 `LargeInteger` instances (`this` instance and another instance), and add their digits together, producing a resulting new `LargeInteger` that is returned from this function.


**Suggested Solution**

Here is the suggested algorithm  you should try to implement for the
`add()` operator:

1. Dynamically allocate a new array to hold the resulting sum of this
   and the other `LargeInteger`.  Reuse the `maxDigits()` member
   function to determine the size needed for this new array.  The size
   of the resulting sum will either be equal to the number of digits
   of the larger of the 2 numbers, or this size + 1 if there is a
   carry on the most significant sum.  We handle needing to grow the
   result in the last step of the algorithm.  For example if this
   large integer has the value 4537 (4 digits) and the other has the
   value of 23 (2 digits), the result will fit in 4 digits, which is
   what `maxDigits()` should return.  Only if we have a carry would we
   need an extra digit.  For example if this is 4537 and the other is
   7242 the result of adding them together would be 11779, which needs
   5 digits.  But as mentioned, we will grow to accommodate a final
   carry in the last step of the algorithm.
2. Perform the addition, from least significant digit to most significant
   digit, handling carry as needed.  Use the `digitAtPlace()` member function
   here, as this will determine if each number has a digit, or will return a 0
   if you are beyond the size of each number.  The resulting digits should
   be stored in the new array you allocated in step 1.  Also make sure you
   keep track of the carry, and at the end, you should know if a 0 or 1 was
   carried from the addition of the last most significant digits.
3. Dynamically allocate a new `LargeInteger()` object, using the
   constructor you created that takes an array as its parameter.  You will
   pass in the array of new digits you summed up in step 2 and its size
   that you determined and dynamically allocated in step 1.
4. If there was a carry on the last most significant digit, use the
   `appendDigit()` member function to add the carry value as the new
   most significant digit to the new `LargeInteger()` you created in
   step 3.  Since your 
   `appendDigit()` function should ignore a request to append a '0' digit,
   you can always just append the final carry without checking if it is
   0 or 1, your `appendDigit()` should grow and append if needed, or 
   ignore if the carry was a 0.
5. The array you dynamically allocated is no longer needed, it was copied when
   you created your new result instance.  So free up the array so we don't
   leak memory.
6. Finally the `add()` function should return a reference to the
   new `LargeInteger()` that contains the calculated sum you just
   computed and assigned to it.

**Additional Requirements**

- The input `LargeInteger` instance must be declared correctly, it needs to be a `const` parameter, and passed by reference.
- The return result should also be returned by reference.  Both passing in and returning by reference are done so that we can avoid potentially expensive copying of memory.
- This means it is required you create a new `LargeInteger` instance dynamically in this method to hold the result, and a reference to this resulting instance is what is to be returned.
- In step 1 an array is dynamically created to hold the result of summing up the digits.  This
  array should be freed to avoid memory leaks, once the `LargeInteger` result has been created.
