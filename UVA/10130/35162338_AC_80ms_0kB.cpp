//easy1

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int Price[1005], Weight[1005];
int People[105]; 
int dp[1005][35];


int knapsack(int N, int target){
    //i from 1 to N
    //j from 0 to target
    //dp[i][j] = max(dp[i-1][j], dp[i-1][j-Weight[i]]+Price[i]) while j-weight[i] > 0
    //if there is no item => d[0][j] = 0;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= target; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else{
                if(j-Weight[i] >= 0)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-Weight[i]]+Price[i]);
                else dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][target];
}


int main() {

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;//N is the number of the item
        memset(Price, 0, N+5);
        memset(Weight, 0, N+5);
        for(int i = 1; i <= N; i++){
            cin >> Price[i] >> Weight[i];
        }
        int G;//number of G
        cin >> G;
        memset(People, 0, G+5);
        for(int i = 1; i <= G; i++){
            cin >> People[i];
        }
        int sum = 0;
        for(int i = 1; i <= G; i++){
            sum += knapsack(N, People[i]);
        }
        cout << sum << endl;
    }
    return 0;
}