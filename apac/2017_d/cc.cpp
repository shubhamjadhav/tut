#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;


#define foi(x) for (int i = 0; i < x; ++i)
#define foj(x) for (int j = 0; j < x; ++j)
#define si size()
#define le length()

int toDec(string s){
    int a=0;
    int k =1;
    foi(s.le){
        if(s[i]=='1')
            a+=k;
        k<<=1;
    }
    return a;
}
 
int BitReversal(int x) {
    string s = bitset<32>(x).to_string();
    // cout<<s<<endl;
    // reverse(s.begin(), s.end());
    if(s[31]=='0'){
        int a = toDec(s);
        return a;
    }
    foi(32){
        if(s[i] == '0')
            s[i] = '1';
        else
            s[i] = '0';        
    }
    // bool done =0;
    foi(32){
        if(s[i]=='1')
            s[i] = '0';
        else{
            s[i] = '1';
            break;
        }
    }
    return -1 * toDec(s);
    // return s;
    // return stoi(rev);
}


int main(int argc, char const *argv[])
{
    string a;
    cin>>a;
    cout<<stoi(a)<<endl;
    return 0;
}
