#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
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
};