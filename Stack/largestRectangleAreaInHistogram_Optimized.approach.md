# Largest Rectangle in Histogram

## Problem Statement
You are given an array of integers `arr` where each element represents the height of a bar in a histogram. Your task is to calculate the area of the largest rectangle that can be formed within the histogram.

### Example
Input: `[3,2,10,11,5,10,6,3]`

Output: `20`

## Intuition
The largest rectangle in a histogram can be calculated by determining the maximum possible area for every bar, treating each bar as the smallest bar in a potential rectangle. For this, we need to calculate:
- The **Previous Smaller Element (PSE)** index for each bar (left boundary of the rectangle).
- The **Next Smaller Element (NSE)** index for each bar (right boundary of the rectangle).

Using a stack, we can efficiently find these indices and calculate the area for each bar.

## Approach
The approach uses a monotonic stack to calculate the largest rectangle:
1. Traverse the histogram from left to right.
2. Use a stack to maintain indices of histogram bars in **non-increasing order** of height.
3. When a bar violates this order, calculate the area for the bar at the top of the stack by treating it as the smallest bar in a rectangle.
4. Continue until all bars are processed.
5. After traversing the array, process remaining bars in the stack.

## Solution Steps
1. Initialize a stack `st` to store indices and a variable `maxArea` to store the largest rectangle area.
2. Iterate through the histogram:
   - For each bar, pop from the stack while the current height is smaller than the height at the top of the stack.
   - For each popped element, calculate the rectangle area using:
     - `height[top]` as the smallest bar.
     - `Next Smaller Element` index as the current index.
     - `Previous Smaller Element` index as the new top of the stack (or `-1` if the stack is empty).
   - Push the current index onto the stack.
3. After the iteration, process all remaining indices in the stack as their Next Smaller Element is the end of the array.
4. Return the maximum area found.

## Time and Space Complexity
### Time Complexity
- **Finding Previous Smaller and Next Smaller:** Each element is pushed and popped from the stack exactly once, resulting in an **O(n)** complexity.
- Overall time complexity: **O(n)**.

### Space Complexity
- The stack stores indices, requiring **O(n)** space in the worst case.

## Dry Run
### Example Input
`arr = [3, 2, 10, 11, 5, 10, 6, 3]`

### Step-by-Step Execution
#### Initialization:
- `st = []` (empty stack)
- `maxArea = 0`

#### Iteration:
1. **i = 0, e = 3:**
   - Stack is empty, push index `0`.
   - `st = [0]`

2. **i = 1, e = 2:**
   - `arr[st.top()] = 3 >= 2`, pop index `0`.
   - Compute area: `arr[0] * (1 - (-1) - 1) = 3 * 1 = 3`.
   - Update `maxArea = 3`.
   - Push index `1`.
   - `st = [1]`

3. **i = 2, e = 10:**
   - Push index `2`.
   - `st = [1, 2]`

4. **i = 3, e = 11:**
   - Push index `3`.
   - `st = [1, 2, 3]`

5. **i = 4, e = 5:**
   - `arr[st.top()] = 11 >= 5`, pop index `3`.
   - Compute area: `arr[3] * (4 - 2 - 1) = 11 * 1 = 11`.
   - Update `maxArea = 11`.
   - `arr[st.top()] = 10 >= 5`, pop index `2`.
   - Compute area: `arr[2] * (4 - 1 - 1) = 10 * 2 = 20`.
   - Update `maxArea = 20`.
   - Push index `4`.
   - `st = [1, 4]`

6. **i = 5, e = 10:**
   - Push index `5`.
   - `st = [1, 4, 5]`

7. **i = 6, e = 6:**
   - `arr[st.top()] = 10 >= 6`, pop index `5`.
   - Compute area: `arr[5] * (6 - 4 - 1) = 10 * 1 = 10`.
   - Push index `6`.
   - `st = [1, 4, 6]`

8. **i = 7, e = 3:**
   - `arr[st.top()] = 6 >= 3`, pop index `6`.
   - Compute area: `arr[6] * (7 - 4 - 1) = 6 * 2 = 12`.
   - Push index `7`.
   - `st = [1, 4, 7]`

#### Final Cleanup:
- Process remaining indices in the stack:
   - Pop `7`: `arr[7] * (8 - 4 - 1) = 3 * 3 = 9`.
   - Pop `4`: `arr[4] * (8 - 1 - 1) = 5 * 6 = 30` (Update `maxArea = 30`).
   - Pop `1`: `arr[1] * (8 - (-1) - 1) = 2 * 8 = 16`.

### Final Output:
`maxArea = 30`



## Code Implementation
```cpp
#include<bits/stdc++.h>
using namespace std ;

int largestRectangleArea(vector<int>& arr) {
    stack<int> st; // Stack to store indices of the array
    int n = arr.size(); // Size of the input array
    int maxArea = 0; // Variable to store the maximum area found

    // Iterate through each element in the array
    for (int i = 0; i < n; i++) {
        int e = arr[i]; // Current element

        // While the stack is not empty and the current element is less than or equal to
        // the element at the index stored at the top of the stack
        while (!st.empty() && arr[st.top()] >= e) {
            int top = st.top(); // Get the index at the top of the stack
            st.pop(); // Pop the top element from the stack

            // The next smaller element (NSE) for the popped element is the current element at index 'i'
            int nseIndex = i;

            // The previous smaller element (PSE) for the popped element is the element at the new top of the stack
            // If the stack is empty, it means there is no previous smaller element, so we use -1
            int pseIndex = st.empty() ? -1 : st.top();

            // Calculate the area of the rectangle with height arr[top] and width (nseIndex - pseIndex - 1)
            int currentArea = arr[top] * (nseIndex - pseIndex - 1);

            // Update maxArea if the currentArea is greater
            maxArea = max(maxArea, currentArea);
        }

        // Push the current index onto the stack
        st.push(i);
    }

    // After processing all elements, there might be some elements left in the stack
    // These elements do not have a next smaller element in the array
    while (!st.empty()) {
        int top = st.top(); // Get the index at the top of the stack
        st.pop(); // Pop the top element from the stack

        // The next smaller element (NSE) for the popped element is beyond the array, so we use 'n'
        int nseIndex = n;

        // The previous smaller element (PSE) for the popped element is the element at the new top of the stack
        // If the stack is empty, it means there is no previous smaller element, so we use -1
        int pseIndex = st.empty() ? -1 : st.top();

        // Calculate the area of the rectangle with height arr[top] and width (nseIndex - pseIndex - 1)
        int currentArea = arr[top] * (nseIndex - pseIndex - 1);

        // Update maxArea if the currentArea is greater
        maxArea = max(maxArea, currentArea);
    }

    // Return the maximum area found
    return maxArea;
}

```

