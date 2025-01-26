#include<bits/stdc++.h>
using namespace std ;
class Solution {
private:
    int * nseIndex (vector<int>& arr){
        int* ans = new int[arr.size()]  ;
        stack<int> st ;
        for(int i = arr.size() - 1 ; i >= 0 ; i--){
            int e = arr[i];

            while(!st.empty() && arr[st.top()] >= e ){
                st.pop();
            }

            if(st.empty()){
                ans[i] = -1; 
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans ;                                                 
    }
    int * pseIndex (vector<int>& arr){
        int* ans = new int[arr.size()] ;
        stack<int> st ;
        for(int i = 0; i < arr.size() ;i++){
            int e = arr[i];

            while(!st.empty() && arr[st.top()] >= e ){
                st.pop();
            }

            if(st.empty()){
                ans[i] = -1; 
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& arr) {
        int *nse = nseIndex(arr);
        int *pse = pseIndex(arr);
        int maxArea = INT_MIN;
        for(int i = 0;i<arr.size();i++){
            int gap ;
            int next = nse[i];
            int prev = pse[i];
            if(next == -1){
                next = arr.size();
            }
            if(prev == -1){
                prev = -1;
            }

            gap = next - prev - 1 ;

            maxArea = max(maxArea,gap*arr[i]);
        }

        return maxArea ;
    }
};