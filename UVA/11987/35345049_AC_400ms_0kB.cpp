#include <iostream>
#include <cstdio>
#include <string.h>
#define M 500005
#define SHIFT 100005

using namespace std;

int rep[M], cnt[M], sum[M];

void Make_Set(int num){
    for(int i = 1; i <= num; i++){
        rep[i] = i+SHIFT;
        rep[i+SHIFT] = i+SHIFT;
        sum[i+SHIFT] = i;
        cnt[i+SHIFT] = 1;
    }
}

int Find_Set(int x){
    if(rep[x] == x) return x;
    else return Find_Set(rep[x]);
}

void Change_Set(int x, int y){
    int rep_x = Find_Set(x);
    int rep_y = Find_Set(y);
    rep[x] = rep_y;
    cnt[rep_x]--;
    sum[rep_x]-=x;
    sum[rep_y]+=x;
    cnt[rep_y]++;
}

void Union(int x, int y){
    int rep_x = Find_Set(x);
    int rep_y = Find_Set(y);
    if(rep_x != rep_y) {
        rep[rep_y] = rep_x;
        sum[rep_x]+=sum[rep_y];
        cnt[rep_x]+=cnt[rep_y]; 
    }
}

int main(){

    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
        memset(rep, 0, sizeof(rep));
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
        Make_Set(a);
        for(int i = 0; i < b; i++){
            int mode;
            cin >> mode;
            if(mode == 1){
                int x, y;
                cin >> x >> y;
                Union(x, y);
            }
            else if(mode == 2){
                int x, y;
                cin >> x >> y;
                Change_Set(x, y);
            }
            else if(mode == 3){
                int x; 
                cin >> x;
                int tmp = Find_Set(x);
                cout << cnt[tmp] << " " << sum[tmp] << endl;
            }
        }
    }
    return 0;
}
/*
5 4
1 1 2
2 3 4
1 3 5
3 4
*/
