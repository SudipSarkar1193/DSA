# Reverse a Stack using Recursion

## Problem

The task is to reverse a stack using recursion. The stack is initially filled with elements, and the goal is to reverse the stack such that the topmost element becomes the bottommost element and vice versa. We cannot use any additional data structures such as arrays or queues to achieve this; the reversal must happen in-place using recursion.

## Approach

To reverse the stack, we need to recursively remove the top element and reverse the remaining stack. Once the remaining stack is reversed, we can insert the removed element at the bottom of the stack.

### Steps:
1. **Base Case**: If the stack is empty, return. This is the point where the recursion terminates.
2. **Recursive Case**: Pop the top element of the stack, reverse the remaining stack, and then push the popped element to the bottom using another helper function.
3. The helper function `pushAtBottom` is used to insert an element at the bottom of the stack.

### Function Breakdown:
- **helper function**: A recursive helper function that inserts the element `x` at the bottom of the stack.
- **pushAtBottom function**: Calls the helper function to place the element `x` at the bottom.
- **reverseStack function**: Recursively reverses the stack by popping the top element, calling the reverse function on the remaining stack, and then inserting the popped element at the bottom of the stack.
- **main function**: Takes user input for the stack size and elements, and then reverses the stack using `reverseStack`.

## Time Complexity

Let `n` be the number of elements in the stack:
- Each recursive call in the `reverseStack` function removes one element and pushes it to the bottom, which involves a call to `pushAtBottom`. In each call to `pushAtBottom`, we push the element at the bottom of the stack which takes `O(n)` time.
- Therefore, the time complexity of this approach is **O(n^2)** because we are making `n` recursive calls, and each call involves pushing elements at the bottom of the stack.

## Space Complexity

The space complexity is determined by the recursion stack. In the worst case, the recursion stack has a depth of `n` due to the recursive calls. Therefore, the space complexity is **O(n)**.

## Example

**Input:**
Enter the number of elements in the stack: 4 
Enter the elements of the stack: 1 2 3 4


**Output:**
Reversed stack: 4 3 2 1


## Conclusion

This approach successfully reverses the stack by utilizing recursion and helper functions to manipulate the stack in place. While the time complexity is quadratic, the solution is elegant and works within the constraints of the problem.
