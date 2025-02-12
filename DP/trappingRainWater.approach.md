# Trapping Rain Water Problem - Intuition & Approach

## Interview answer :

This approach works because, `at any given index, we're always processing the smaller boundary first. That’s the key reason why it never fails.`

Think about it this way— **if we’re moving the left pointer, it means the `left side is currently the limiting factor`.** And **because we always move the smaller side first, we can be absolutely sure that `there won’t be a smaller boundary on the right at this moment`. If there was, we wouldn’t have moved in the first place!**

The same logic applies in the other direction — **when we move the right pointer, `we know the right boundary is in control, and there’s no smaller boundary on the left that we haven’t already considered.`**

So, in simple terms, we’re always making the right decision at the right time. That’s why this approach works so well!



## Intuition
The problem requires us to calculate how much rainwater can be trapped between bars of different heights after raining.

To solve this efficiently, we need to understand the following observations:
- Water can only be trapped at an index **if there is a taller boundary on both sides** (left and right).
- The amount of water stored at an index is determined by the **minimum of the tallest bars on its left and right**, minus the height of the bar at that index.
- Instead of using extra space for storing left and right maximums, we can optimize the approach using **two pointers**.

## Approach (Two Pointers)
### **1. Initialize Pointers and Variables**
- Use two pointers: `l` (left) starting at index `0`, and `r` (right) starting at the last index.
- Maintain two variables `lmax` and `rmax` to track the maximum height encountered from the left and right, respectively.
- Initialize `total = 0` to store the trapped water.

### **2. Traverse the Array Using Two Pointers**
- If `arr[l]` is smaller than or equal to `arr[r]`, we process the left pointer (`l`):
  - If `arr[l] < lmax`, then water can be trapped at `l` (i.e., `lmax - arr[l]`).
  - Otherwise, update `lmax = arr[l]`.
  - Move `l` to the right (`l++`).
- Otherwise, we process the right pointer (`r`):
  - If `arr[r] < rmax`, then water can be trapped at `r` (i.e., `rmax - arr[r]`).
  - Otherwise, update `rmax = arr[r]`.
  - Move `r` to the left (`r--`).

### **3. Return the Result**
- Once `l` and `r` meet, return `total`, which contains the amount of trapped water.

## **Complexity Analysis**
- **Time Complexity:** `O(n)`, since each element is processed at most once.
- **Space Complexity:** `O(1)`, as we use only a few extra variables.

## **Code Implementation (C++)**
```cpp
class Solution {
public:
    int trap(vector<int>& arr) {
        int lmax = 0, rmax = 0, l = 0, r = arr.size() - 1, total = 0;

        while (l < r) {
            if (arr[l] <= arr[r]) {
                if (arr[l] < lmax) {
                    total += (lmax - arr[l]);
                } else {
                    lmax = arr[l];
                }
                l++;
            } else {
                if (arr[r] < rmax) {
                    total += (rmax - arr[r]);
                } else {
                    rmax = arr[r];
                }
                r--;
            }
        }

        return total;
    }
};
```

## **Why This Approach?**
- It avoids the extra space required for prefix and suffix arrays (`O(n) → O(1)`).
- It processes each element only once, making it optimal (`O(n)`).
- Simple to implement and easy to understand using the **two-pointer** method.

This is an efficient way to solve the **Trapping Rain Water** problem with minimal time and space complexity. 🚀

