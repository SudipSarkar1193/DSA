#include<bits/stdc++.h>
using namespace std;

int minIndex(int a,int b,int* arr){
    return arr[a]<arr[b]?a:b;
}

int maxIndex(int a,int b,int* arr){
    return arr[a]>arr[b]?a:b;
}


int trap(vector<int> &arr){
    int l = 0 ,
    r = arr.size() - 1 ,
    leftMax = 0 , 
    rightMax = 0 ,
    sum = 0 ;

    while(r >= l){
        cout<<"Hitt"<<endl;
        if(arr[l] < arr[r]){
            //if can hold water
            if(arr[l] < leftMax && arr[l] < arr[r]){
                sum += leftMax - arr[l];
            }else{
                if(arr[l] > leftMax)leftMax =arr[l]; 
            }
            l++;
        }else{
            //if can hold water
            if(arr[r] < rightMax && arr[r] < arr[l]){
                sum += rightMax - arr[r];
            }else{
                if(arr[r] > rightMax) rightMax = arr[r];
            }
            r--;
        }
    }


    return sum ;

}

int main(){
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"Hey"<<endl;
    cout<<"Sum "<<trap(v)<<endl;
}