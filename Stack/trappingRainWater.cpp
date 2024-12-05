#include <bits/stdc++.h>

using namespace std;

int* prefixMax(const vector<int>& arr) {
    int* ans = new int[arr.size()];
    int maxTill = -1;
    for (int i = 0; i < arr.size(); i++) {
        int e = arr[i];
        ans[i] = maxTill;
        if (e > maxTill) {
            maxTill = e;
        }
    }
    return ans;
}

int* sufixMax(const vector<int>& arr) {
    int* ans = new int[arr.size()];
    int maxTill = -1;
    for (int i = arr.size() - 1; i >= 0; i--) {
        int e = arr[i];
        ans[i] = maxTill;
        if (e > maxTill) {
            maxTill = e;
        }
    }
    
    return ans;
}

int min(int a,int b){
    return a<b?a:b;
}
int trapWater(vector<int> arr){
    int *s = sufixMax(arr);
    int *p = prefixMax(arr);
    int sum =0;
    for(int i = 0;i<arr.size();i++){
        if(arr[i]<p[i] && arr[i]<s[i]){
            int mini = min(p[i],s[i]);
            sum += (mini - arr[i]);
        }
    }
    delete[] s;
    delete[] p;
    return sum;
}

int main() {
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout<<trapWater(v)<<endl;

    return 0;
}
