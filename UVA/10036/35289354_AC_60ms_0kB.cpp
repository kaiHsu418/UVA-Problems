#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int M;
int N, K;
//int dp[10005][105], 
//int S[105];

int main(){
    cin >> M;
   for(int l = 1; l <= M; l++){
        cin >> N >> K;
        //memset(S, 0, sizeof(S));
        //memset(dp, 0, sizeof(dp));
        int S[N];
        for(int i = 0; i < N; i++){
            cin >> S[i];
            S[i] = abs(S[i])%K;
        }
        int dp[N+1][100] = {0};
        dp[0][0] = 1;
        for(int i = 1; i <= N; i++){
            for(int j = 0; j < K; j++){
                if(dp[i-1][j]){
                    dp[i][(j+S[i-1]+K)%K] = 1;
                    dp[i][(j-S[i-1]+K)%K] = 1;   
                }
            }
        }
        //cout << ((dp[N][0])? "Divisible":"Not divisible") << endl;
        cout << ((dp[N][0])? "Divisible":"Not divisible") << endl;
    }
    return 0;
}/*
2
4 7
17 5 -21 15
4 5
17 5 -21 15
*/