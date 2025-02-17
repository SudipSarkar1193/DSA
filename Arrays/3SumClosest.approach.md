# Three Sum Closest - Optimization Journey

## 1. Intuition & Problem Understanding
The **Three Sum Closest** problem requires finding the sum of three numbers in a given array that is closest to a target value.

### **Key Observations**
- A brute force solution would involve checking **all possible triplets** (O(N³)), which is inefficient.
- Sorting the array and using a **two-pointer technique** can significantly reduce the time complexity.
- We can **early exit** if we find an exact match (`sum == target`).

---

## 2. Initial (Least Efficient) Approach - Brute Force (O(N³))
### **Core Idea**
- Iterate through all possible triplets using **three nested loops**.
- Compute the sum and track the one closest to the target.

### **Code:**
```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int res = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(sum - target) < abs(res - target)) {
                        res = sum;
                    }
                }
            }
        }
        return res;
    }
};
```
### **Why is this inefficient?**
❌ **Time Complexity:** **O(N³)** – Three nested loops.  
❌ **Space Complexity:** **O(1)** – But slow due to brute-force checking.  

---

## 3. Optimized Approach - Sorting + Two-Pointer (O(N²))
### **Core Idea**
- Sort the array first to enable a two-pointer approach.
- Fix one number and use two pointers to efficiently find the closest sum.
- Reduce unnecessary computations by skipping duplicate values.

### **Code:**
```cpp
class Solution {
    void twoSum(vector<int>& arr, int s , int e,int target, int fixedNum ,int &res){

        while(s < e){

            int sum = arr[s] + arr[e] + fixedNum ;
            res = abs(res - target) > abs(sum - target) ? sum : res;
            if(sum > target){
                e--;
            }else if(sum < target){
                s++;
            }else{
                res = sum;
                s++;
                e--;

                //Removing duplicate :
                while(s < e && arr[s] == arr[s+1]) s++ ;
                while(s < e && arr[e] == arr[e-1]) e--;
            }
        }
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        
        //SORT
        sort(nums.begin(),nums.end());

        int n = nums.size() ;
        if (n < 3) {
            throw invalid_argument("Array must contain at least 3 elements.");
        }
        int res = nums[0] + nums[1] + nums[2] ;
        
        for(int i = 0 ; i< n -2 ; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue ;
            }
            twoSum(nums,i+1,n-1,target,nums[i],res);
            
        }

        return res ;
    }
};
```
### **Why is this better?**
✅ **Time Complexity:** **O(N²)** – Sorting takes **O(N log N)** and two-pointer search takes **O(N)** for each fixed number.  
✅ **Space Complexity:** **O(1)** – No extra space used.  
✅ **Early Termination:** If `sum == target`, return immediately.  
✅ **Skipping Duplicates:** Prevents redundant calculations.  

---

## 4. Further Optimization - Using Boolean Flag for Early Exit
### **Core Idea**
- Introduce a boolean flag to break out of loops **immediately** when an exact match is found.
- Avoid redundant calculations by reducing unnecessary comparisons.

### **Code:**
```cpp
class Solution {
    bool twoSum(vector<int>& arr, int s , int e, int target, int fixedNum, int &res) {
        while (s < e) {
            int sum = arr[s] + arr[e] + fixedNum;
            res = abs(res - target) > abs(sum - target) ? sum : res;
            if (sum > target) {
                e--;
            } else if (sum < target) {
                s++;
            } else {
                return true; // Exact match found, exit early
            }
        }
        return false;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        if (n < 3) {
            throw invalid_argument("Array must contain at least 3 elements.");
        }

        int res = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (twoSum(nums, i + 1, n - 1, target, nums[i], res)) {
                return target; // Early exit
            }
        }
        return res;
    }
};
```
### **Why is this the most optimized?**
✅ **Early Exit Strategy:** If an exact match is found, we exit immediately.  
✅ **Code Modularity:** The `twoSum()` function keeps things clean and reusable.  
✅ **Time Complexity:** Still **O(N²)** but with **faster execution** due to early exits.  

---

## 5. Summary of Optimizations
| Approach | Time Complexity | Space Complexity | Key Improvements |
|----------|----------------|------------------|------------------|
| **Brute Force (O(N³))** | O(N³) | O(1) | Checks all triplets |
| **Sorting + Two Pointers (O(N²))** | O(N²) | O(1) | Reduces loops, skips duplicates |
| **Boolean Flag + TwoSum Function (O(N²))** | O(N²) | O(1) | Early exit on exact match, modular code |

**Final Verdict:** The **last solution** is the most optimized version with efficient execution. 🚀
```

