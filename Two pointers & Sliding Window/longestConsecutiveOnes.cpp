#include<bits/stdc++.h>
using namespace std ;

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