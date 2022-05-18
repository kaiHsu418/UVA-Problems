#include <bits/stdc++.h>

using namespace std;

long long dp[1000005];

int main(){

    long long  n;
    dp[3] = 0;
    for(long long i = 4; i < 1000005; i++){
        dp[i] = dp[i-1] + ((i-1)*(i-2)/2 - (i/2-1))/2;
    }
    while(scanf("%lld", &n) != EOF){
        if(n < 3) break;
        printf("%lld\n", dp[n]);
    }
    return 0;
}//