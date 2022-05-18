#include <iostream>
#include <vector>
#include <string.h>


using namespace std;

vector<int> G[1005];
int match[1005];
int vis[1005];
int S[1005], T[1005];//source and target

bool solve(int u){
    S[u] = 1;
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(!T[v]){
            T[v] = 1;
            if(!match[v] || solve(match[v])){
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int R, C, N;
    while(cin >> R >> C >> N, R, C, N){
        for(int i = 0; i <= R; i++) G[i].clear();
        for(int i = 0; i < N; i++){
            int r, c;
            cin >> r >> c;
            G[r].push_back(c);
        }
        int ans = 0;
        memset(match, 0, sizeof(match));
        for(int i = 1; i <= R; i++){
            memset(S, 0, sizeof(S));
            memset(T, 0, sizeof(T));
            if(solve(i)) ans++;
        }
        cout << ans;
        memset(S, 0, sizeof(S));
        memset(T, 0, sizeof(T));
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= C; i++) vis[match[i]] = 1;
        for(int i = 1; i <= R; i++){
            if(!vis[i]) solve(i);
        }
        for(int i = 1; i <= R; i++){
            if(!S[i]) cout << " r" << i;
        }
        for(int i = 1; i < C; i++){
            if(T[i]) cout << " c" << i;
        }
        cout << endl;
    }
    return 0;
}

/*
4 4 3
1 1
1 4
3 2
4 4 2
1 1
2 2
0 0 0
*/