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
    int* nseIndex(vector<int>& arr) {
        int* ans = new int[arr.size()];
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int e = arr[i];

            while (!st.empty() && arr[st.top()] >= e) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }

    int* pseIndex(vector<int>& arr) {
        int* ans = new int[arr.size()];
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            int e = arr[i];

            while (!st.empty() && arr[st.top()] >= e) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& arr) {
        int* nse = nseIndex(arr);
        int* pse = pseIndex(arr);
        int maxArea = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            int gap;
            int next = nse[i];
            int prev = pse[i];
            if (next == -1) {
                next = arr.size();
            }
            if (prev == -1) {
                prev = -1;
            }

            gap = next - prev - 1;

            maxArea = max(maxArea, gap * arr[i]);
        }

        return maxArea;
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

