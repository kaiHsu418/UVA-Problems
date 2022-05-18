#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX 40

using namespace std;

struct node{
    int x;
    int y;
    int z;
};

node v[3*MAX];
int graph[3*MAX][3*MAX];
int n;

void constructGraph(){
    for(int i = 0; i < 3*MAX; i++){
        for(int j =0; j < 3*MAX; j++){
            graph[i][j] = 0;
        }
    }
    //construct DAG
    for(int i = 0; i < 3*n; i++){
        for(int j = 0; j < 3*n; j++){
            if((v[i].x < v[j].x && v[i].y < v[j].y)||(v[i].x < v[j].y && v[i].y < v[j].x)){
                graph[i][j] = 1;
            }       
            //cout << ((graph[i][j]==1)? 1 : 0 ) << " ";
        }
        //cout << endl;
    }

}


int vis[3*MAX], dp[3*MAX];
void dfs(int x){
    if(dp[x] != -1) return;
    else{
        dp[x] = v[x].z;
        for(int i = 0; i < 3*n; i++){
            if(graph[x][i] && !vis[i]){
                dfs(i);
                dp[x] = max(dp[x], dp[i]+v[x].z);
            }
        }
    }
}


int main(){

    int num = 0;
    while(cin >> n, n){
        int curNode = -1;

        memset(v,0,sizeof(v));
        memset(dp,-1,sizeof(dp));
        memset(graph,0,sizeof(graph));
        //memset(vis, 0, sizeof(vis));

        for(int i = 0; i < n; i++){
            int x, y, z;
            cin >> x >> y >> z;
            v[++curNode].x = x;
            v[curNode].y = y;
            v[curNode].z = z;

            v[++curNode].x = y;
            v[curNode].y = z;
            v[curNode].z = x;

            v[++curNode].x = z;
            v[curNode].y = x;
            v[curNode].z = y;
        }
        constructGraph();
        //cout << endl;
        for(int i = 0; i < 3*n; i++){
            dfs(i);
        }
        int ans = 0;
        for(int i = 0; i < 3*n; i++){
            //cout << ans << " " << endl;
            //ans = max(ans, dfs(i));
            ans = max(ans, dp[i]);
        }
        cout << "Case " << ++num << ": maximum height = ";
        cout << ans << endl;
    }
    return 0;
}
