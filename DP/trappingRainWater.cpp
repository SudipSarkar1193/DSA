#include<bits/stdc++.h>
using namespace std ;


    int trap(vector<int>& arr) {
            int lmax = 0 , rmax = 0 , 
            l = 0, r = arr.size() - 1 , 
            total = 0 ;
    
            while(l < r){
                if(arr[l] < arr[r]){
                   // cout<<arr[l]<<" for: "<<l<<endl ;
                    if(lmax > arr[l]){
                        total +=  lmax - arr[l];
                    }else{
                        lmax = arr[l];
                    }
                    l++;
                }else{
                    //cout<<arr[r]<<" "<<" for: "<<r<<endl ; ;
                    if(rmax > arr[r]){
                        total += rmax -arr[r];
                    }else{
                        rmax = arr[r];
                    }
                    r--;
                }
            }
            //cout<<endl;
            return total ;
    }

int main(){
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<< "ANS = "<<trap(v);
    return 0;
}
