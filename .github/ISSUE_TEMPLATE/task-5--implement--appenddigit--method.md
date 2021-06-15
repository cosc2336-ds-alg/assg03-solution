---
name: 'Task 5: Implement `appendDigit` Member Function'
about: Task 5 for Students
title: 'Task 5: Implement `appendDigit` Member Function'
labels: enhancement
assignees: ''

---

**Description**

The `appendDigit()` member function is again mainly useful to support implementation of the `add()` operation.  This function should append a new digit as the new most significant digit of the `LargeInteger` instance.


**Suggested Solution**

This method requires more practice and use of pointers and dynamic memory allocation.  You need to create a new block of integers that is 1 size bigger than the current `digit[]` array so it can hold the new digit being appended.  You then need to copy over all of the digits, and repoint the `digit` member pointer to this newly allocated memory.  Don't forget to be a good manager of memory and delte the old array of digits that is no longer needed.

The suggested algorithm you should perform is as follows:

1. Allocate a new array of digits of size numDigits+1 (e.g. enough
   space to hold one more digit).
2. Copy the old digits to the new array of digits you created.
3. Append the new passed in digit to the end of the array.
4. Free up the old original array of digits.
5. Re-point your `digit` member variable to your newly allocated
   space that has grown in size by 1.

**Additional Requirements**

- You must of course correctly allocate a new block of memory and copy over the digits from the old to new block, and repoint the instance to this new block.
- You are also required to correctly free up the old block after it is copied since you will not longer need to reference it.
- You are required to ignore request to append a 0 digit, as the last most significant digit that needs to be kept track of is the last non-zero digit.

