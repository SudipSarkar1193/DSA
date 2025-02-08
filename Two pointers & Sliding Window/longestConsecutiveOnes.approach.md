## Intuition and Approach for Longest Consecutive Ones with K Flips

### [leetcode link](https://leetcode.com/problems/max-consecutive-ones-iii/description/)

### **Intuition:**
The problem requires finding the longest contiguous subarray containing only `1`s, allowing at most `k` flips from `0` to `1`. This naturally leads to a **sliding window** approach since we need to find a subarray with constraints while maximizing its length.

- We maintain a **window** (`l, r`) where we count the number of `0`s.
- **If the number of `0`s exceeds `k`, we need to shrink the window from the left (`l`) until the condition is satisfied again.**
- We keep track of the **maximum window size** that satisfies the given condition.

---

### **Approach:**
1. **Initialize Pointers and Variables:**
   - `l = 0`, `r = 0` to represent the sliding window.
   - `zeroCount = 0` to track the number of `0`s within the window.
   - `maxCount = 0` to store the maximum length of valid subarrays.

2. **Expand the Window:**
   - Traverse the array using `r`.
   - If `arr[r] == 0`, increment `zeroCount`.
   - If `zeroCount` exceeds `k`, move `l` to the right until we are back within the allowed limit.

3. **Update Maximum Length:**
   - At each step, compute the window size `r - l + 1` and update `maxCount`.

4. **Continue Until `r` Reaches the End of the Array.**

---

### **Code Implementation:**
```cpp
class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size(), l = 0, r = 0, maxCount = 0, zeroCount = 0;
        
        while (r < n) {
            if (arr[r] == 0) zeroCount++;
            
            while (zeroCount > k) { // Shrink window from the left
                if (arr[l] == 0) zeroCount--;
                l++;
            }
            
            maxCount = max(maxCount, r - l + 1);
            r++;
        }
        
        return maxCount;
    }
};
```

---

### **Time and Space Complexity:**
- **Time Complexity:** \( O(N) \)
  - Each element is processed at most twice (once by `r`, once by `l`).
- **Space Complexity:** \( O(1) \)
  - Uses a few integer variables, so no extra space is needed.

---

### **Why This Works Well?**
- This is an **optimal** approach because it ensures we only scan the array **once**.
- **Instead of recalculating window properties from scratch, we use a sliding window, adjusting only necessary parts dynamically.**
- It efficiently finds the longest valid subarray satisfying the problem constraints.

---

### **Edge Cases Considered:**
- All `1`s (`k` is irrelevant).
- All `0`s (`k` determines max length).
- `k == 0` (find longest consecutive `1`s without flipping).
- `k >= count(0s)` (entire array becomes `1`).

