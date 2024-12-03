#include <bits/stdc++.h> 
using namespace std;

string removeValidPart(string str, int *o, int *c) {
    string ans = "";
    stack<char> st;

    for (char ch : str) {
        if (ch == '{') {
            st.push(ch);
        } else {
            if (!st.empty()) {
                st.pop();
            } else {
                ans += ch;
                *c = *c + 1;
                
            }
        }
    }
    while (!st.empty()) {
        ans += st.top();
        *o = *o + 1;
        st.pop();
    }

    return ans;
}


int findMinimumCost(string str) {
  if(str.length()%2){
    return -1; //Impossible
  }
  int open = 0, close = 0;
  string invalidPart = removeValidPart(str,&open,&close);
  if(invalidPart.length()%2){
    return -1; //Impossible
  }
  
  if(open%2==0){  
    return open/2 + close/2;
  }else{
    return (open-1)/2 + (close-1)/2 +2;
  }

}


int main() {
    int open = 0, close = 0;
    string str = "}}}{{{" ;
    cout << str.length() <<endl;
    cout << removeValidPart(str, &open, &close) << endl;
    cout << "Open: " << open << " Close: " << close << endl;

    cout<<"findMinimumCost : "<<findMinimumCost(str)<<endl;
    return 0;
}
