---
name: 'Task 4: Implement `digitAtPosition()` Member Function'
about: Task 4 for Students
title: 'Task 4: Implement `digitAtPosition()` Member Function'
labels: enhancement
assignees: ''

---

**Description**

The purpose of `digitAtPosition()` is to index into the `LargeInteger` and return the digit at a particular location (digit place) of the instance.


**Suggested Solution**

This function needs to be safe from making an illegal array bounds reference.  This is done for two reasons.  Of course to be safe, you should never access memory beyond the bounds that was allocated to you for your use.  But also, by returning 0 if a reference is made beyond the bounds of the `digit[]` array, we simplify the `add()` operation we want to implement for this class.  You need to test the `numDigits` before accessing the `digit[]` array to determine if the request is within bounds or not.

**Additional Requirements**

- This member method does not modify the instance, so it needs to be declared as a `const` member method.
- It is required that your method returns 0 for request that is greather than the biggest most significant digit, or that are less than 0.

