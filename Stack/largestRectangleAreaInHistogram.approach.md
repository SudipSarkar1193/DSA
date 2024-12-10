# Largest Rectangle in Histogram

This project implements a solution to find the **largest rectangle area** in a histogram using stack-based approaches for **Next Smaller Element (NSE)** and **Previous Smaller Element (PSE)**.

## Problem Statement

Given an array `arr` representing the heights of bars in a histogram, find the largest rectangular area that can be formed using consecutive bars.

### Example
Input: `[2, 1, 5, 6, 2, 3]`  
Output: `10`  
Explanation: The largest rectangle is formed using bars of height `5` and `6`, with a width of `2`.

---

## Intuition

The core idea is to determine, for each bar in the histogram:
- **How far it can extend to the left** (until a smaller bar is encountered).
- **How far it can extend to the right** (until a smaller bar is encountered).

These two values are computed using:
1. **Previous Smaller Element (PSE):** The closest bar to the left smaller than the current bar.
2. **Next Smaller Element (NSE):** The closest bar to the right smaller than the current bar.

Once we have PSE and NSE for all bars, the largest rectangle for each bar can be calculated as:
\[
\text{Area}_i = (\text{NSE}[i] - \text{PSE}[i] - 1) \times \text{Height}[i]
\]

---

## Approach

### Steps:
1. **Compute PSE for all bars:**
   - Use a stack to find the index of the closest smaller bar to the left for each bar.
   - If no such bar exists, set `PSE[i] = -1`.

2. **Compute NSE for all bars:**
   - Use a stack to find the index of the closest smaller bar to the right for each bar.
   - If no such bar exists, set `NSE[i] = -1`.

3. **Calculate the largest rectangle:**
   - For each bar `i`, use the formula:
     \[
     \text{Area}_i = (\text{NSE}[i] - \text{PSE}[i] - 1) \times \text{Height}[i]
     \]
   - Keep track of the maximum area across all bars.

---

## Complexity Analysis

1. **Time Complexity:**
   - Computing PSE and NSE both take \(O(n)\), as each element is pushed and popped from the stack once.
   - Calculating the largest rectangle takes \(O(n)\).
   - Total: **\(O(n)\)**.

2. **Space Complexity:**
   - Space used by the stack: **\(O(n)\)**.
   - Space for PSE and NSE arrays: **\(O(n)\)**.
   - Total: **\(O(n)\)**.

---

## Code Explanation

### Functions:
1. **`pseArray`:** Calculates the Previous Smaller Element for each bar.
2. **`nseArray`:** Calculates the Next Smaller Element for each bar.
3. **`largestRectangleArea`:** Uses PSE and NSE to calculate the maximum rectangle area.
4. **`printArr`:** Utility function to print an array.

### Example Run:
For `arr = [2, 1, 5, 6, 2, 3]`:
- PSE: `[-1, -1, 1, 2, 1, 4]`
- NSE: `[1, -1, 4, 4, -1, -1]`
- Largest Rectangle Area: `10`

---

```cpp
#include<bits/stdc++.h>
using namespace std ;
int *nseArray(vector<int>& arr){
    int n = arr.size();
    stack<int>st ;
    int *ans = new int[n];

    for(int i = n-1 ; i>=0 ; i--){
        int e = arr[i];

        while(!st.empty() && arr[st.top()] >= e){
            st.pop();
        }

        if(st.empty()){
            ans[i] = - 1;
        }else{
            int top = st.top();
            ans[i] = top ;
        }

        st.push(i);

    }

    return ans ;
}

int *pseArray(vector<int>& arr){
    int n = arr.size();
    stack<int>st ;
    int *ans = new int[n];

    for(int i = 0 ; i<n ; i++){
        int e = arr[i];

        while(!st.empty() && arr[st.top()] >= e){
            st.pop();
        }

        if(st.empty()){
            ans[i] = - 1;
        }else{
            int top = st.top();
            ans[i] = top ;
        }

        st.push(i);

    }

    return ans ;
}

int largestRectangleArea(vector<int>& arr) {
    int 
    *pse = pseArray(arr),
    *nse = nseArray(arr);
    int ans = INT_MIN ;
    for (int i = 0; i < arr.size(); i++){
        int prev = pse[i] == -1 ? 0 : pse[i] + 1; // If no previous smaller, extend to start
        int next = nse[i] == -1 ? arr.size() : nse[i]; // If no next smaller, extend to end
        
        // Calculate area for the current bar
        ans = max(ans, (next - prev) * arr[i]);
    }

    delete[] pse; 
    delete[] nse; 

    return ans ;
}
```

## Note :

```cpp
    int prev = pse[i] == -1 ? 0 : pse[i] + 1; // If no previous smaller, extend to start
    int next = nse[i] == -1 ? arr.size() : nse[i]; // If no next smaller, extend to end

    // Calculate area for the current bar
    ans = max(ans, (next - prev) * arr[i]);
```

Try to analyze this two lines with examples :
1. `arr = [2, 1, 5, 6, 2, 3]`
1. `arr = [1,1]`
1. `arr = [2,2,3]`
