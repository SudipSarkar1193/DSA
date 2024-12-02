# TwoStack Implementation

## Overview
This repository contains a C++ implementation of a data structure that uses a single array to simulate two stacks. The two stacks share the same array, and each stack grows in opposite directions.

## Approach

### 1. **Array Representation**:
   - The array is dynamically allocated with a fixed size.
   - `top1` is the index representing the top of Stack 1, and `top2` is the index representing the top of Stack 2.
   - `top1` starts at `-1` (indicating an empty stack), and `top2` starts at `n` (the size of the array, indicating the other end of the array).

### 2. **Push Operation**:
   - For `push1(int x)`, the element is added at the `top1` index and then `top1` is incremented.
   - For `push2(int x)`, the element is added at the `top2` index and then `top2` is decremented.
   - Both `push` operations check whether there is enough space between `top1` and `top2` before adding an element. If the space is insufficient (i.e., `top1 >= top2`), it results in an overflow.

### 3. **Pop Operation**:
   - For `pop1()`, if `top1` is valid (i.e., `top1 >= 0`), the element at `top1` is returned, and `top1` is decremented.
   - For `pop2()`, if `top2` is valid (i.e., `top2 < n`), the element at `top2` is returned, and `top2` is incremented.
   - If either stack is empty, the respective pop operation returns `-1` indicating underflow.

### 4. **Overflow and Underflow**:
   - Overflow occurs if there is no space between `top1` and `top2`.
   - Underflow occurs if a pop operation is called on an empty stack.

## Time Complexity
- **Push Operation**: O(1) for both `push1` and `push2`, as each operation involves updating the index pointers (`top1` and `top2`).
- **Pop Operation**: O(1) for both `pop1` and `pop2`, as each operation involves updating the index pointers and returning an element from the array.

Thus, each push and pop operation runs in constant time, O(1).

## Space Complexity
- The space complexity is **O(n)**, where `n` is the size of the array used for storing the stacks. The space is used by the array, which holds the elements of both stacks simultaneously.

## Conclusion
This approach efficiently simulates two stacks within a single array by using two indices (`top1` and `top2`) to manage space in opposite directions. It ensures optimal space usage while providing O(1) time complexity for push and pop operations.
