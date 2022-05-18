#include <bits/stdc++.h>
#define MAXN 205
using namespace std;
vector<int> G[MAXN];
int color[MAXN];

bool dfs(int u){
    for(auto v:G[u]){
        if(!color[v]){
            color[v] = -color[u];
            if(!dfs(v)) return false;
        }
        else if(color[u] == color[v]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int M;
    while(cin >> M, M){
        int N;
        cin >> N;
        for(int i = 0; i < MAXN; i++) G[i].clear();
        for(int i = 0; i < N; i++){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(color, 0, sizeof(color));
        color[0] = 1;
        if(dfs(0)) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}