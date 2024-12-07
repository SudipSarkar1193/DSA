#include<bits/stdc++.h>
using namespace std;

vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        
    vector<int> nge(queries) ;
    int ind = 0;
    for(int index : indices){
        int e = arr[index];
        int cnt = 0;
        for(int i = index + 1 ; i < n ; i ++){
            if(arr[i] > e){
                 cnt++ ; 
            }
        }
        nge[ind++] = cnt ;
            
    }
        
    return nge ;
       
}