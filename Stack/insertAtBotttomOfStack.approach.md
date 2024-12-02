# Push an Element at the Bottom of the Stack

## Problem

Given a stack `st` of integers, the goal is to push a given integer `x` at the bottom of the stack. The problem requires that we should not use any auxiliary data structures such as arrays or lists. The solution should work with the existing stack data structure.

## Approach

We solve this problem using recursion. The idea is to recursively remove elements from the stack until we reach the bottom (when the stack becomes empty), then push the desired element `x` at the bottom, and finally push the previously removed elements back in the reverse order.

### Steps:
1. **Base Case**: If the stack is empty, push the element `x` onto the stack.
2. **Recursive Case**: Pop the top element from the stack, and recursively call the helper function to reach the bottom of the stack.
3. Once the stack becomes empty, push the element `x` at the bottom.
4. After the element is placed at the bottom, push the previously popped elements back into the stack in the same order.

### Function Breakdown:
- **helper function**: This recursive function handles the process of pushing the element `x` at the bottom of the stack.
- **pushAtBottom function**: This function calls the helper function and returns the modified stack.

## Time Complexity

Let `n` be the number of elements in the stack:
- In each recursive call, we pop one element from the stack and push it back after the recursion completes.
- The recursion depth is `O(n)` (since we need to pop all `n` elements before pushing `x` at the bottom).
- Therefore, the time complexity of this approach is **O(n)**.

## Space Complexity

Since we are using recursion, the maximum depth of the recursion stack is `n`, and no additional space (other than the call stack) is used. Therefore, the space complexity is **O(n)** due to the recursion stack.

## Example

**Input:**
- Stack: `1 2 3 4`
- Element to be pushed at the bottom: `5`

**Output:**
- Modified Stack: `5 1 2 3 4`
