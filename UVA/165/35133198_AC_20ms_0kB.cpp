#include <iostream>
#include <iomanip>
#include <string.h>
#define N 200
using namespace std;

int h, k, MAX, maxvalue[N];
int stamps[N], res[N]; 
bool vis[N];

void check(int n , int cur, int sum){
    vis[sum] = 1;
    if(n == h) return;
    for(int i = 0; i <= cur; i++){
        check(n+1, cur, sum+stamps[i]);
    }
}

void dfs(int cur){
    if(cur >= k){
        if(maxvalue[cur-1] > MAX){
            MAX = maxvalue[cur-1];
            memcpy(res, stamps, sizeof(stamps));
        } 
        return;
    }
    for(int i = stamps[cur-1]; i <= maxvalue[cur-1]+1; i++){
        memset(vis, 0, sizeof(vis));
        stamps[cur] = i;
        check(0, cur, 0);
        int t = 1, num = 0;
        while(vis[t++]) num++;
        maxvalue[cur] = num;
        dfs(cur+1);
    }
}

int main(){

    while(cin >> h >> k, h, k){
        memset(vis, 0, sizeof(vis));
        memset(maxvalue, 0, sizeof(maxvalue));
        memset(stamps, 0, sizeof(stamps));
        memset(res, 0, sizeof(res));

        maxvalue[0] = h;
        stamps[0] = 1;
        MAX = 0;
        dfs(1);
        for(int i = 0; i < k; ++i)
                cout << setw(3) << res[i];
            cout << " ->" << setw(3) << MAX << endl;
    }
    return 0;
}