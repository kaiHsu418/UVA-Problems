#include <iostream>
#include <algorithm>

using namespace std;

int dp[105][105], a[105], b[105];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int N, M, Case = 0;
    while(cin >> N >> M, N, M){
        for(int i = 1; i <= N; i++) cin >> a[i];
        for(int i = 1; i <= M; i++) cin >> b[i];

        for(int i = 0; i < N; i++) dp[i][0] = 0;
        for(int i = 0; i < M; i++) dp[0][i] = 0;

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << "Twin Towers #" << ++Case << endl;
        cout << "Number of Tiles : " << dp[N][M] << endl << endl;
    }
    return 0;
}
//