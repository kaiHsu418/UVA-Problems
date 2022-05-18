#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int pre[1005];

int Find(int x){
    if(pre[x] == x) return x;
    else return Find(pre[x]);
}

void Union(int x, int y){
    int pre_x = Find(x);
    int pre_y = Find(y);
    if(pre_x != pre_y){
        pre[pre_y] = pre_x;
    }
}

void initial(int n){
    for(int i = 0; i < n; i++){
        pre[i] = i;
    }
}


struct Node{
    int u;
    int v;
    int w;
};

bool cmp(Node a, Node b){
    return a.w < b.w;
}


//int node[3][1005];
vector <Node> Weights;
vector <int> ans;

int main(){

    int n, m; // n is the number of nodes; m is the number of edge
    while(cin >> n >> m, n, m){
        memset(pre, 0, sizeof(pre));
        Weights.clear();
        ans.clear();

        initial(n);
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            Node cur = {u, v, w};
            Weights.push_back(cur);
        }
        sort(Weights.begin(), Weights.end(), cmp);
        
        for(auto i:Weights){
            if(Find(i.u) == Find(i.v)){
                ans.push_back(i.w);
            }
            else{
                Union(i.u, i.v);
            }
        }
        if(ans.size() == 0) cout << "forest" << endl;
        else{
            for(int i = 0; i < ans.size(); i++){
                if(i == ans.size()-1) cout << ans[i];
                else cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}