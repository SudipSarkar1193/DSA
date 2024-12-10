#include<bits/stdc++.h>
using namespace std ;
int *nseArray(vector<int>& arr){
    int n = arr.size();
    stack<int>st ;
    int *ans = new int[n];

    for(int i = n-1 ; i>=0 ; i--){
        int e = arr[i];

        while(!st.empty() && arr[st.top()] >= e){
            st.pop();
        }

        if(st.empty()){
            ans[i] = - 1;
        }else{
            int top = st.top();
            ans[i] = top ;
        }

        st.push(i);

    }

    return ans ;
}

int *pseArray(vector<int>& arr){
    int n = arr.size();
    stack<int>st ;
    int *ans = new int[n];

    for(int i = 0 ; i<n ; i++){
        int e = arr[i];

        while(!st.empty() && arr[st.top()] >= e){
            st.pop();
        }

        if(st.empty()){
            ans[i] = - 1;
        }else{
            int top = st.top();
            ans[i] = top ;
        }

        st.push(i);

    }

    return ans ;
}

int largestRectangleArea(vector<int>& arr) {
    int 
    *pse = pseArray(arr),
    *nse = nseArray(arr);
    int ans = INT_MIN ;
    for (int i = 0; i < arr.size(); i++){
        int p = pse[i] == -1 ? i : pse[i];
        int n = nse[i] == -1 ? i : nse[i];
       
        ans = max(ans,(n-p+1)*arr[i]);
    }

    return ans ;
}

void printArr(int *arr,int n){
    for(int i = 0 ; i < n ; i++ ){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){
    vector<int> arr ={2,1,5,6,2,3};

    int n = arr.size();

    int 
    *pse = pseArray(arr),
    *nse = nseArray(arr);

    printArr(pse,n);
    printArr(nse,n);
    

    return 0;
}