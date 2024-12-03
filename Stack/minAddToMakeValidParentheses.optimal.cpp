
#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string str) {
    int open = 0,close=0;
    for(char ch : str){
        if(ch == '('){
            open++;
        }else{
            if(ch == ')'){
                if(open > 0)open--;
                else if(open == 0) close++;
            }
        }
    }

    //Now we have the number of opening and closing tag from  the invalid part of the string

    return open + close ;
       
}