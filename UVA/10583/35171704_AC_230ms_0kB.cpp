#include <iostream>
#define M 500005
using namespace std;

int rep[M];

void Make_Set(int num){
    for(int i = 1; i <= num; i++){
        rep[i] = i;
    }
}

int Find_Set(int x){
    if(rep[x] == x) return x;
    else return Find_Set(rep[x]);
}

void Union(int x, int y){
    int rep_x = Find_Set(x);
    int rep_y = Find_Set(y);
    if(rep_x != rep_y) rep[rep_y] = rep_x; 
}

int main(){

    int n, m, k = 0;
    while(cin >> n >> m, n, m){
        Make_Set(n);
        for(int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            Union(x, y);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(rep[i] == i) cnt++;
        }
        printf("Case %d: %d\n", ++k, cnt);
    }
    return 0;
}
