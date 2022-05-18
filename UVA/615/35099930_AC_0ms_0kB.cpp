#include <iostream>
#include <vector>
#include <algorithm>
#define M 100000

using namespace std;

vector<int> graph[M];
vector<int> Unode;// the first node of an edge
int vis[M];
int in[M];
bool Tree = 0;

void dfs(int x){
    vis[x] = 1;
    vector<int>tmp = graph[x];
    for(int i = 0; i < tmp.size(); i++){
        if(vis[tmp[i]]){
            Tree = 0;
            return;
        }
        dfs(tmp[i]);
        if(!Tree) return;
    }
}


int main(){

    int u, v, K = 0;
    while(cin >> u >> v){
        Unode.clear();
        for(int i = 0; i < M; i++){
            graph[i].clear();
            vis[i] = 0;
            in[i] = 0;
        }

        if(u == -1 && v == -1) break;

        while(u >0 && v > 0){
            graph[u].push_back(v);
            if(find(Unode.begin(), Unode.end(), u) == Unode.end()) Unode.push_back(u);
            in[v]++;
            cin >> u >> v;
        }
        Tree = 1;
        for(int i = 0; i < Unode.size(); i++){
            if(in[Unode[i]] == 0) {
                dfs(Unode[i]);
                break;
            }
        }
        for(int i = 0; i < Unode.size(); i++){
            vector<int> tmp = graph[Unode[i]];
            for(int j =0; j < tmp.size(); j++){
                if(!vis[tmp[j]]){
                    Tree = 0;
                    break;
                }
            }
        }
        if(!Tree){
            cout << "Case " << ++K << " is not a tree." << endl;
        }
        else cout << "Case " << ++K << " is a tree." << endl;
    }
    return 0;
}