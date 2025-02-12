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




int printMaxSubArray(vector<int>& nums) {
    int max_sum = nums[0]; // Initialize with first element
    int current_sum = nums[0];
    int l = 0, r = 0 , start = 0;

    for (int i = 1; i < nums.size(); i++) {
         // Start fresh or continue
        if(nums[i]>current_sum + nums[i]){
            start = i;
            current_sum = nums[i];
        }else{
            current_sum += nums[i];
        }
       
        if(current_sum>max_sum){
            max_sum = current_sum ;
            l = start ;
            r=i;
        }
    }

    for(int i = l;i<=r;i++){
        cout<<nums[i]<<" ";
    }cout<<endl;

    return max_sum;
}


int main(){
    vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<printMaxSubArray(vec)<<endl ;
}