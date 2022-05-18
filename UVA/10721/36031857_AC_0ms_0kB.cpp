#include <bits/stdc++.h>
long long dp[55][55];//dp[i][j] ith bar ends at the jth unit

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k, m;
	while(cin >> n >> k >> m){
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n && i <= m; i++){
			dp[1][i] = 1; //one bar will only be the black one
		}
		for(int i = 2; i <= n; i++){
			for(int j = i; j <= n; j++){
				for(int k = 1; k <= m && j > k; k++){
					dp[i][j] += dp[i-1][j-k];
				}
			}
		}
		cout << dp[k][n] << endl;
	}
	return 0;
}
