#include <bits/stdc++.h> 
using namespace std;

vector<int> nextGreaterElementArray(vector<int>& arr){
    stack<int> st;

    st.push(-1);

    vector<int> ans(arr.size()) ;

    for(int i = arr.size() - 1 ; i >=0 ; i--){
        int num = arr[i];
       
        while(st.top() != -1){
            if(st.top()>num){
                ans[i] = st.top();
                st.push(num);
                break;
            }else{
                st.pop();
            }
        }
        if(st.top()==-1){
            ans[i]= -1;
            st.push(num);
        }
    }

    return ans;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v = nextGreaterElementArray(nums2);

        vector<int> ans(nums1.size());
        int index = 0;
        for(int e : nums1){
            for(int i = 0;i<nums2.size();i++){
                if(e == nums2[i]){
                    ans[index++] = v[i];
                }
            }
        } 

        return ans;
}

int main()
{
    // Create a vector containing integers
    vector<int> v(3);
 
    // Add two more integers to vector
    v.push_back(6);
    v.push_back(9);
 
    // Overwrite element at position 2
    v[2] = -1;
 
    // Print out the vector
    for (int n : v)
        std::cout << n << ' ';
    std::cout << '\n';
}