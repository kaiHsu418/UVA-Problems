#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string.h>
const int MAXN  = 65;
using namespace std;

int graph[MAXN][MAXN];
int price[MAXN];
int dp[1<<12][12];
int N, M;

vector< pair<int, int> > MAP;
vector<int> S;

void relax(){
    for(int i = 0; i <= N; i++){
        graph[i][i] = 0;
    }
    for(int k = 0; k <= N; k++){
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= N; j++){
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
}

void init(){
    for(int i = 0; i < (1<<S.size()); i++){
        for(int j = 0; j < S.size(); j++){
            dp[i][j] =  -0x3f3f3f3f;
        }
        MAP.push_back(make_pair(__builtin_popcount(i), i));
    }
    sort(MAP.begin(), MAP.end());
    for(int i = 0; i < S.size(); i++){
        int u = S[i];
        dp[1<<i][i] = -graph[0][u]+price[u];
    }
}

int TSP(){
    int ans =  -0x3f3f3f3f;
    init();
    for(int i = 0; i < MAP.size(); i++){
        int state = MAP[i].second;
        for(int j = 0; j < S.size(); j++){
            if(dp[state][j] ==  -0x3f3f3f3f) continue;//no path
            int u = S[j];
            ans = max(ans, dp[state][j]-graph[S[j]][0]);
            for(int k = 0; k < S.size(); k++){
                if((state>>k)&1) continue;
                int v = S[k];
                dp[state|(1<<k)][k] = max(dp[state|(1<<k)][k], dp[state][j]-graph[u][v]+price[v]);
            }
        }
    }
    return ans;
}

int main(){

    int K;
    cin >> K;

    while(K--){
        cin >> N >> M;
        memset(graph, 0x3f, sizeof(graph));
        memset(price, 0, sizeof(price));
        S.clear();
        MAP.clear();
        for(int i = 0; i < M; i++){
            //input the road information
            int x, y, d1, d2;
            scanf("%d %d %d.%d", &x, &y, &d1, &d2);
            graph[x][y] = min(graph[x][y], d1*100+d2);
            graph[y][x] = min(graph[y][x], d1*100+d2);
        }/*
        cout << endl;
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= N; j++){
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }*/
        int P;
        cin >> P;
        for(int i = 0; i < P; i++){
            //input the price information
            int x, d1, d2;
            scanf("%d %d.%d", &x, &d1, &d2);
            price[x] += 100*d1+d2;
        }
        for(int i = 0; i <= N; i++){
            if(price[i] > 0) S.push_back(i);
        }
        relax();
        int ans = TSP();
        if (ans > 0) printf("Daniel can save $%d.%02d\n", ans/100, ans%100);
        else printf("Don't leave the house\n");
    }
    return 0;
}
/*
2
4 5
0 1 1.00 
1 2 3.00 
1 3 2.00 
2 4 4.00 
3 4 3.25 
3
2 1.50
3 7.00
4 9.00
1 1
0 1 1.50 
1
1 2.99
*/
