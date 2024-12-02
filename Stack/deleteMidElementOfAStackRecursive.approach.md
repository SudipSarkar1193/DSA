# Delete Middle Element of a Stack (Recursive Approach)

## Overview
This program demonstrates how to delete the middle element from a stack using recursion. Unlike the iterative approach, this version does not use auxiliary storage but relies on the call stack to temporarily store elements.

## Approach

### 1. **Recursive Helper Function**:
   - The helper function keeps track of the current position in the stack (`cnt`).
   - When `cnt` equals `n/2`, the middle element is removed using `pop()`.

### 2. **Recursive Backtracking**:
   - After removing the middle element, the function backtracks and pushes the stored elements back onto the stack, maintaining the original order.

### 3. **Function Workflow**:
   - **Base Case**: If the middle element is reached, remove it.
   - **Recursive Step**: Pop the current top element, call the helper function for the next position, and then push the stored element back.

### 4. **Complexity**:
   - **Time Complexity**: O(n), as elements are popped and pushed back once.
   - **Space Complexity**: O(n), due to recursive call stack usage.

## Example

### Input:
Stack (top to bottom): `[5, 4, 3, 2, 1]`

### Process:
1. Recursively traverse to the middle element `3`.
2. Remove `3` and backtrack, pushing the remaining elements back.

### Output:
Stack (top to bottom): `[5, 4, 2, 1]`

## Usage

1. Define a stack and populate it with elements.
2. Call the `deleteMid` function, passing the stack and its size.
3. Print the modified stack after the middle element is removed.

## Note
The recursive approach eliminates the need for auxiliary arrays, making the implementation cleaner but using additional stack space for recursion.
