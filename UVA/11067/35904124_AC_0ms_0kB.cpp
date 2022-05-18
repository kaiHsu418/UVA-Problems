#include <bits/stdc++.h>
#define MAXN 105
#define ll long long
using namespace std;

int w, h, x, y;
int wolf[MAXN][MAXN];
ll ans[MAXN][MAXN];

ll counting(int i, int j){
    if(wolf[i][j] || i < 0 || j < 0) return 0;
    if(i == 0 && j == 0) return 1;
    if(ans[i][j] != -1) return ans[i][j];
    return ans[i][j] = counting(i-1, j)+counting(i, j-1);
}

int main(){
    while(scanf("%d%d", &h, &w)!=EOF && !(h == 0 && w == 0)){
        memset(wolf, 0, sizeof(wolf));
        memset(ans, -1, sizeof(ans));
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &x, &y);
            wolf[x][y] = 1;
        }
        ll cnt = counting(h, w);
        if(cnt == 0) printf("There is no path.");
        else if(cnt == 1) printf("There is one path from Little Red Riding Hood's house to her grandmother's house.");
        else printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.", cnt);
        printf("\n");
    }
    return 0;
}
/*
1 1
0
1 1
2
0 1
1 0
4 4
3
0 1
1 1
3 1
10 10
0
10 10
3
0 1
1 1
1 0
3 3
5
1 0
1 1
1 2
2 2
3 2
0 0*/