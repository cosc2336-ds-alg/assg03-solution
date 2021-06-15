---
name: 'Task 3: Implement `maxDigits()` Member Function'
about: Task 3 for Students
title: 'Task 3: Implement `maxDigits()` Member Function'
labels: enhancement
assignees: ''

---

**Description**

The purpose of the `maxDigits()` member function is to compare two `LargeInteger` instances (this instance and another instance) and determine and return the number of digits in the larger of the two.  This method has a slightly complex signature.  You need to pass in a reference to another `LargeInteger` as the paramter input into this member function.

**Suggested Solution**

You should be aware that you can access private member variables not only of `this` instance, but of other instances of `LargeInteger` passed in to a member function.  This is useful because you need to compare the `numDigits` of `this` and the other instance to determine which has the larger number of digits.

**Additional Requirements**

- You are required to pass in the other `LargeInteger` as a `const` parameter.
- You are required to pass in the other `LargeInteger` by reference rather than by value, so we avoid copying if the `LargeInteger` is really large.
- You are required to make sure this function is a `const` member function since calling it changes neither `this` instance nor the other instance used in the function.


