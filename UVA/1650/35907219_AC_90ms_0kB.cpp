#include <bits/stdc++.h>
#define MAXN 1005
const int M  = 1e9+7;

using namespace std;

int dp[MAXN][MAXN], sum[MAXN][MAXN];

int main(){
    string s;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while(cin >> s){
        int n = s.size()+1;
        dp[1][1] = 1;
        sum[1][1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if(s[i-2] == 'I') dp[i][j] = sum[i-1][j-1];
                else if(s[i-2] == 'D') dp[i][j] = (sum[i-1][i-1]-sum[i-1][j-1]+M)%M;
                else dp[i][j] = sum[i-1][i-1];
                sum[i][j] = (sum[i][j-1]+dp[i][j])%M;
            }
        }
        cout << sum[n][n] << endl;
    }
    return 0;
}