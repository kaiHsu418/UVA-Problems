#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T, k;
    string n;
    cin >> T;
    while(T--){
        int cnt = 0;
        cin >> n;
        cin >> k;
        for(int i = 0; i < k; i++){
            int x;
            cin >> x;
            int tmp = 0;
            for(int j = 0; j < n.size(); j++){
                tmp = (tmp*10+n[j]-'0')%x;
            }
            if(tmp == 0) cnt++;
        }
        if(cnt == k) cout << n << " - Wonderful." << endl;
        else cout << n << " - Simple." << endl;
    }
    return 0;
}
/*
4
0
12 1 2 3 4 5 6 7 8 9 10 11 12
379749833583241
1 11
3909821048582988049
1 7
10
3 1 2 9
*/