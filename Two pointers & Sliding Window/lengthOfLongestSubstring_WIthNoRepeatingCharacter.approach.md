# Longest Substring Without Repeating Characters

## Solution Explanation

To solve this problem, we use a **sliding window approach**.  
We keep increasing the window size **until we encounter a repeating character**.  

Whenever we hit a **repeating character** (a character that has already been seen),we `shrink the window** from the left.`  
`This means we move the left pointer so that the previous occurrence of the character is excluded from the window`.  

`We **continue this process** while keeping track of the **maximum length** of a substring without repeating characters.`

There are some edge cases we need to consider. Whenever we hit a repeating character, `the first thing we need to check is whether its previous occurrence is still within our current window.` If the previous occurrence is inside the window, we update the left pointer to exclude it and `then update the character’s latest occurrence.` Otherwise, we don’t need to adjust the left pointer.

Also, we must always increment r++ at every step, no matter what. `Even if we encounter a repeating character, we handle it by shrinking the window, so for the next iteration, we still need to move the right pointer forward.`

## Programmatic Approach
Programmatically, `we need to track whether a character has already been seen.` To do this, `we use an array (acting like a hash map)` `where we store the index of each character’s last occurrence at its corresponding ASCII index.`

We also maintain two pointers:

The left pointer `represents the leftmost index` of our current window.
The right pointer `represents the rightmost index` of our window.
We keep moving the right pointer forward. If we `encounter` a repeating character (`one that has been seen before`), we update the left pointer `to exclude the previous occurrence of that character`. **This ensures that our window always contains `unique` characters**. Throughout this process, we continuously track the maximum length of the substring without repeating characters.

## Conclusion

By following this approach, we efficiently find the **longest substring without repeating characters**.


# Time and Space Complexity Analysis

## **Time Complexity**

The time complexity of this solution is **O(n)**, where `n` is the length of the string.

- We traverse the string **once** using the `right` pointer.
- The `left` pointer **only moves forward** and never reprocesses characters.
- Since each character is processed **at most twice** (once by `r` and at most once by `l`),  
  the overall complexity remains **O(n)**.

## **Space Complexity**

The space complexity is **O(1)** (constant space).

- We use an **array of fixed size (256)** to store character indices.
- Since the total number of possible characters (ASCII) is **bounded**,  
  the extra space used does not depend on `n`, making it **O(1)**.

## **Final Verdict**
- **Time Complexity:** `O(n)` → Each character is processed at most twice.
- **Space Complexity:** `O(1)` → We use a fixed-size array of 256 elements.


## Code :
```cpp
    int lengthOfLongestSubstring(string s) {
        
        int * hash = new int[256];
        for(int i = 0;i<256;i++){
            hash[i] = -1 ;
        }
        int maxLength = 0;
        int l = 0 ,r = 0;
        while(r < s.length()){
            char ch = s[r];
            int ascii = (int)ch;
            if(hash[ascii]==-1){
                maxLength =  max(maxLength, r - l + 1);
                hash[ascii]=r;
                r++; 
               
            }else{
                if(hash[ascii]>=l){
                    l = hash[ascii] + 1 ;
                } 
                maxLength =  max(maxLength, r - l + 1);
                hash[ascii]= r;
                r++;
            }          
        }
        return maxLength ;
    }
```