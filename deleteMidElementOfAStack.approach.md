# Delete Middle Element of a Stack

## Overview
This program demonstrates how to delete the middle element from a stack using an auxiliary array. The stack's top-to-bottom order is maintained after the deletion.

## Approach

### 1. **Temporary Array**:
   - Use a temporary array to store the top `n/2 + 1` elements from the stack.
   - Remove these elements from the stack.

### 2. **Remove Middle Element**:
   - Skip the middle element (index `n/2` in the array).

### 3. **Rebuild the Stack**:
   - Push the remaining elements from the temporary array back to the stack in reverse order.

### 4. **Complexity**:
   - **Time Complexity**: O(n), as elements are popped and pushed back once.
   - **Space Complexity**: O(n), due to the auxiliary array.

## Example

### Input:
Stack (top to bottom): `[5, 4, 3, 2, 1]`

### Process:
1. Remove top 3 elements into an array: `[5, 4, 3]`.
2. Skip the middle element `3`.
3. Push remaining elements `[5, 4]` back into the stack.

### Output:
Stack (top to bottom): `[5, 4, 2, 1]`

## Usage

1. Define a stack and populate it with elements.
2. Call the `deleteMid` function, passing the stack and its size.
3. Print the modified stack after the middle element is removed.

## Note
The program dynamically allocates memory for the temporary array, which is later deallocated to prevent memory leaks.
