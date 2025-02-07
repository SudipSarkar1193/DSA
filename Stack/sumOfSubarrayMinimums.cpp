#include<bits/stdc++.h>
using namespace std ;

int* nseIndex(vector<int>& arr){
    int n = arr.size();
    int *ptr = new int[n];
    stack<int> st ;
    for(int i = n -1 ; i >= 0 ; i-- ){
        int e = arr[i];

        while(!st.empty() && arr[st.top()] >= e){
            st.pop();
        }

        if(st.empty()){
            ptr[i] = -1;
        }else{
            ptr[i] = st.top();
        }

        st.push(i);
    }
    return ptr ;
}
int* pseoeIndex(vector<int>& arr){
    int n = arr.size();
    int *ptr = new int[n];
    stack<int> st ;
    for(int i = 0 ; i < n ; i++ ){
        int e = arr[i];

        while(!st.empty() && arr[st.top()] > e){
            st.pop();
        }

        if(st.empty()){
            ptr[i] = -1;
        }else{
            ptr[i] = st.top();
        }

        st.push(i);
    }
    return ptr ;
}

int sumSubarrayMins(vector<int>& arr) {
    
}

void printArr(int *arr,int n){
    for(int i = 0 ; i<n;i++){
        if(i==n-1) cout<<arr[i]<<endl;
        else cout<<arr[i]<<",";
    }cout<<endl;
}

int main(){

    vector<int> arr = {1, 3,3, 3, 2, 1};
    int* arr1 = pseoeIndex(arr);
    int* arr2 = nseIndex(arr);
    printArr(arr1,6);
    printArr(arr2,6);

    return 0 ;
}