#include <bits/stdc++.h>
#define MAXN 30005

using namespace std;


/* use the dag to find the longest path, but it will TLE qq
vector<int> G[MAXN];
int dis[MAXN];
vector<int> A(MAXN), B(MAXN), C(MAXN);

void dfs(int u){
    if(dis[u] != -1) return;
    else{
        dis[u] = C[u];
        for(auto v:G[u]){
            dfs(v);
            dis[u] = max(dis[u], dis[v]+C[u]);
        }
    }
}
void construct(){
    for(int i = 0; i < N; i++){
            G[i].clear();
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(i != j && A[i]+B[i]-1 < A[j]) G[i].push_back(j);
            }
        }
        memset(dis, -1, sizeof(dis));
        for(int i = 0; i < N; i++){
            dfs(i);
        }
}*/

struct adv{
    int start;
    int end;
    int cost;
}A[MAXN];

bool cmp(adv &a, adv &b){
    return a.end < b.end;
}
int dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, Case;
    cin >> T;
    while(T--){
        int N, ans = 0;
        cin >> N;
        for(int i = 1; i <= N; i++){
            //cin >> A[i] >> B[i] >> C[i];
            int a, b, c;
            cin >> a >> b >> c;
            A[i].start = a;
            A[i].end = a+b-1;
            A[i].cost = c;
        }
        sort(A+1, A+N+1, cmp);
        memset(dp, 0, sizeof(dp));
        dp[1] = A[1].cost;
        for(int i = 2; i <= N; i++){
            int k = 0;
            for(int j = i-1; j > 0; j--){
                if(A[j].end < A[i].start){
                    k = j;
                    break;
                }
            }
            dp[i] = max(dp[k]+A[i].cost, dp[i-1]);
        }
        cout << "Case " << ++Case << ": ";
        cout << dp[N] << endl;
    }    
    return 0;
}



