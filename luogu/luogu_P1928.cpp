#include <bits/stdc++.h>
using namespace std;

string fun(){
    int k;
    char ch;
    string s="";
    string str="";
    while(cin>>ch){
        if(ch=='['){
            cin>>k;
            str=fun();
            while(k--){
                s+=str;
            }
        }
        else if(ch==']'){
            return s;
        }else{
            s+=ch;
        }
    }
    return s;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fun();
    return 0;
}