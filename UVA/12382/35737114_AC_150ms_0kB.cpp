#include <bits/stdc++.h>

using namespace std;

int row[1005], col[1005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n, m, ans = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> row[i];
        }
        for(int i = 0; i < m; i++){
            cin >> col[i];
        }
        sort(row, row+n, greater<int>());
        sort(col, col+m, greater<int>());
        for(int i  = 0; i < m; i++){
            if(col[i]){
                for(int j = 0; j < n; j++){
                    if(row[j]){
                        ans++;
                        col[i]--;
                        row[j]--;
                    }
                    if(!col[i]) break;
                }
            }
            ans+=col[i];
            sort(row, row+n, greater<int>());
        }
        for(int i = 0;i < n ;i++){
            ans+=row[i];
        }
        cout << ans << endl;
    }

    return 0;
}