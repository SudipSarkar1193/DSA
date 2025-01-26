# Problem Statement

Given an array `heights` representing the heights of bars in a histogram, find the area of the largest rectangle that can be formed by using these bars. Each bar has a width of `1`.

---

## Intuition

To find the largest rectangular area in a histogram, the critical insight is to calculate the width of the rectangle that each bar can contribute to, based on its height. This width is determined by the nearest smaller element (NSE) to the left and right of each bar. Once these bounds are identified for every bar, we can compute the rectangle area for each bar and track the maximum.

---

## Solution

The solution involves two main steps:

1. **Calculate NSE and PSE indices:**
   - For each bar, find the index of the nearest smaller element on the left (PSE - Previous Smaller Element) and on the right (NSE - Next Smaller Element).
   - Use stacks to efficiently calculate these indices.

2. **Calculate Maximum Area:**
   - For each bar, use the PSE and NSE indices to calculate the width of the rectangle the bar contributes to.
   - Use the formula: `width = NSE[i] - PSE[i] - 1`, and the area is `width * heights[i]`.
   - Track the maximum area across all bars.

### Code Implementation

```cpp
class Solution {
private:
    // Function to compute the Next Smaller Element (NSE) index for each element in the array
    int* nseIndex(vector<int>& arr) {
        int* ans = new int[arr.size()];  // Array to store the NSE indices
        stack<int> st;  // Stack to help find the NSE

        // Traverse the array from the end to the beginning
        for (int i = arr.size() - 1; i >= 0; i--) {
            int e = arr[i];

            // Pop elements from the stack that are greater than or equal to the current element
            while (!st.empty() && arr[st.top()] >= e) {
                st.pop();
            }

            // If the stack is empty, there is no NSE for the current element
            if (st.empty()) {
                ans[i] = -1;  // -1 indicates no NSE
            } else {
                ans[i] = st.top();  // The top of the stack is the NSE index
            }
            st.push(i);  // Push the current index onto the stack
        }

        return ans;  // Return the array of NSE indices
    }

    // Function to compute the Previous Smaller Element (PSE) index for each element in the array
    int* pseIndex(vector<int>& arr) {
        int* ans = new int[arr.size()];  // Array to store the PSE indices
        stack<int> st;  // Stack to help find the PSE

        // Traverse the array from the beginning to the end
        for (int i = 0; i < arr.size(); i++) {
            int e = arr[i];

            // Pop elements from the stack that are greater than or equal to the current element
            while (!st.empty() && arr[st.top()] >= e) {
                st.pop();
            }

            // If the stack is empty, there is no PSE for the current element
            if (st.empty()) {
                ans[i] = -1;  // -1 indicates no PSE
            } else {
                ans[i] = st.top();  // The top of the stack is the PSE index
            }
            st.push(i);  // Push the current index onto the stack
        }

        return ans;  // Return the array of PSE indices
    }

public:
    // Function to compute the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& arr) {
        int* nse = nseIndex(arr);  // Get the NSE indices
        int* pse = pseIndex(arr);  // Get the PSE indices
        int maxArea = INT_MIN;  // Initialize the maximum area to the smallest possible integer

        // Traverse the array to compute the area for each bar
        for (int i = 0; i < arr.size(); i++) {
            int gap;
            int next = nse[i];  // Index of the next smaller element
            int prev = pse[i];  // Index of the previous smaller element

            // If there is no next smaller element, set it to the size of the array i.e index is JUST right side of the array!
            if (next == -1) {
                next = arr.size();
            }

            // If there is no previous smaller element, set it to -1 i.e index is JUST left side of the array!
            if (prev == -1) {
                prev = -1;
            }

            // Calculate the width of the rectangle (gap between next and previous smaller elements)
            gap = next - prev - 1;

            // Calculate the area of the rectangle and update the maximum area if necessary
            maxArea = max(maxArea, gap * arr[i]);
        }

        return maxArea;  // Return the largest rectangle area
    }
};
```

---

## Time Complexity

1. **Finding PSE and NSE:**
   - Using a stack to find the nearest smaller elements for each bar takes `O(n)` time.
   - Since this process is performed twice (once for PSE and once for NSE), the total time complexity for these steps is `O(2n) = O(n)`.

2. **Calculating the Maximum Area:**
   - Iterating through the array to compute the area for each bar takes `O(n)` time.

Thus, the overall time complexity is:

**`O(n)`**

---

## Space Complexity

1. **Stack Space:**
   - The stack used to find PSE and NSE requires space proportional to the number of elements, i.e., `O(n)`.

2. **Auxiliary Arrays:**
   - Two arrays (`nse` and `pse`) of size `n` are used.

Thus, the total space complexity is:

**`O(n)`**

