---
name: 'Task 1: Implement `tostring()` Member Method'
about: Task 1 for Students
title: 'Task 1: Implement `tostring()` Member Method'
labels: enhancement, good first issue
assignees: ''

---

**Description**

The first task is to implement the `tostring()` member function for  your `LargeInteger` class.  We need this method for testing purposes, so we have to implement it first so we can test other methods.

This method should return a C++ `string` as its result.  You have to construct a string representation of the digits of the `LargeInteger` and return this string.

**Suggested Solution**

You are required to use string stream objects to construct your string to be returned. There are examples of using string streams in this units lecture and written materials.

Also make sure you understand the representation being used of the digits in the `LargeInteger` instances.  The least significant digit will be at index 0 of the `digit[]` array, and the most significant digit will be in the highest index of the array.  You will probably need to iterate through the `digit[]` array in reverse order to correctly construct the string representation to return.

**Additional Requirements**

- Use output string streams to construct the string to be returned.
- You are required to correctly identify `const` member functions for your class members in this assignment.  `tostring()` needs to be a `const` function because the `LargeInteger` should not be modified as a result of calling this function.

