#include <iostream>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

long long dp[205][205];
string s;


long long convert(int left, int right){    
    long long ans = 0;
    for(int i = left; i <= right; i++){
        ans *= 10;
        ans += (s[i]-'0');
        if(ans > INT_MAX) return 0;
    }
    return ans;
}


int main(){


    int n;
    cin >> n;


    while(n--){
        //string s;
        cin >> s;
        
        //dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]) where i <= k < j

        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                dp[i][j] = convert( i, j);
            }
        }

        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                for(int k = i; k < j; k++){
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
            }
        }
        cout << dp[0][s.size()-1] << endl;
    }
    return 0;
}