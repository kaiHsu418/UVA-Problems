#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(){

    string s1, s2;
    int a[26], b[26];
    while(cin >> s1 >> s2){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i < s1.size(); i++){
            a[s1[i]-'A']++;
            b[s2[i]-'A']++;
        }
        sort(a, a+26);
        sort(b, b+26);
        bool flag = 1;
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i]){
                flag = 0;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}