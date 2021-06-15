---
name: 'Task 2: Implement Array Based `LargeInteger` Constructor'
about: Task 2 for Students
title: 'Task 2: Implement Array Based `LargeInteger` Constructor'
labels: enhancement
assignees: ''

---

**Description**

The second task is to add another class constructor to the `LargeInteger` class.  There are two existing constructors you should examine and understand, they will be useful as models for the constructor you need to create.

This constructor needs to create a `LargeInteger` instance from an existing array of digits.  This method will allow you to practice performing dynamic memory allocation and working with pointers.  You need to dynamically a new array of `int` values in this method to copy the digits from the given array into the `LargeInteger` instance being constructed.

**Suggested Solution**

This method is similar to the provided constructor that constructs the digits by parsing an `int` data type.  You should examine that method for an idea of how to implement your constructor.

**Additional Requirements**

- You must correctly allocate memory dynamically to hold the digits for the instance being constructed.  Make sure you set the `numDigits` size member variable correctly as well in the constructor.
