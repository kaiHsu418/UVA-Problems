#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

string S1, S2;
int x, y;

int MIN(int a, int b, int c){
    return min(min(a, b), c);
}

int Edit_Dist(int x, int y){
    if(x == 0) return y;
    if(y == 0) return x;

    if(S1[x-1] == S2[y-1]) return Edit_Dist(x-1, y-1);
    else return 1+MIN(Edit_Dist(x-1, y-1), Edit_Dist(x-1, y), Edit_Dist(x, y-1));
}



int main(){
    while(cin >> x >> S1 >> y >> S2){
        int dp[x+1][y+1];
        //memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= x; i++){
            for(int j = 0; j <= y; j++){
                //dp[i][j]: pick the 1 to i and 1 to j in the S1 and S2
                if(i == 0) dp[i][j] = j;
                else if(j == 0) dp[i][j] = i;
                else if(S1[i-1] == S2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1+MIN(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }
        }
        //cout << Edit_Dist(x, y) << endl;
        cout << dp[x][y] << endl;
        /*
        for(int i = 0; i <= x; i++){
            for(int j = 0; j <= y; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
    }    
    return 0;
}