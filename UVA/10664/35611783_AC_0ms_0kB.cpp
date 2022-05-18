#include <bits/stdc++.h>
#define MAXN 205

using namespace std;


bool dp[MAXN];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> m;
    string line;
    getline(cin, line);
    while(m--){
        getline(cin, line);
        stringstream ss(line);
        int weight, sum = 0;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        while(ss >> weight){
            sum += weight;
            for(int i = sum; i >= 0; i--) 
                if(dp[i]) dp[i+weight] = 1;
        }
        if(sum%2) cout << "NO" << endl;
        else cout << (dp[sum/2]?"YES":"NO") << endl;

    }
    return 0;
}
/*
3
1 2 1 2 1
2 3 4 1 2 5 10 50 3 50
3 5 2 7 1 7 5 2 8 9 1 25 15 8 3 1 38 45 8 1
*/

