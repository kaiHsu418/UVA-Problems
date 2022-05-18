#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        int t;
        cin >> t;
        if(t <= 9) cout << t << endl;
        else{
            string ans = "";
            for(int i = 9; i >= 1; i--){
                if(t%i == 0 && t>1){
                    t/=i;
                    ans = (char)(i+'0')+ans;
                }
            }
            if(t > 1) cout << "-1" << endl;
            else cout << ans << endl;
        }
    }
    return 0;
}
