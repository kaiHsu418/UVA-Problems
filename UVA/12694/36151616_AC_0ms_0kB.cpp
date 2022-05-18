#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct meet{
    int start;
    int end;
}M[21];

bool cmp(meet A, meet B){
    return A.end < B.end;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T, s, e;
    cin >> T;
    while(T--){
        int cnt;
        for(cnt = 0; cnt < 21; cnt++){
            cin >> s >> e;
            if(s == 0 && e == 0) break;
            M[cnt].start = s;
            M[cnt].end = e;
        }
        sort(M, M+cnt, cmp);
        int prev = M[0].end, ans = 1;
        for(int i = 1; i < cnt; i++){
            if(prev <= M[i].start){
                prev = M[i].end;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
3
0 6
5 7
8 9
5 9
1 2
3 4
0 5
0 0
6 10
5 6
0 3
0 5
3 5
4 5
0 0
1 5
3 9
0 0
*/

/*
1
0 6
5 7
8 9
5 9
1 2
3 4
0 5
0 0

*/