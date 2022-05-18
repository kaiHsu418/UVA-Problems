#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int T[MAXN][MAXN], R[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int rows, cols;
    while(cin >> rows >> cols, rows, cols){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                cin >> T[i][j];
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int cnt = 0;
                int k = j;
                while(k < cols && T[i][k] == 0){
                    cnt++;
                    k++;
                }
                R[i][j] = cnt;
            }
        }
        int ans = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int tmp = INT_MAX;
                for(int k = i; k < rows; k++){
                    tmp = min(tmp, R[k][j]);
                    ans = max(ans, (k-i+1)*tmp);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}