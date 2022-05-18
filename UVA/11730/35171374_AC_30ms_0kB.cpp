#include <iostream>
#include <string>
#include <queue>
#include <string.h>

using namespace std;

struct queueNode{
    int x;
    int dis;
};

bool prime[1010];
bool vis[1010];

void is_prime(){
    for(int i = 2; i*i < 1005; i++){
        if(!prime[i]){
            for(int j = i*i; j < 1005; j+=i) prime[j] = 1;
        }
    }
}

int bfs(int S, int T){
    memset(vis, 0, 1005);
    queue<queueNode> Q;
    queueNode s = {S, 0};
    Q.push(s);
    while(!Q.empty()){
        queueNode curNode = Q.front();
        Q.pop();
        if(curNode.x == T) return curNode.dis;
        
        for(int i = 2; i < curNode.x; i++){
            if(curNode.x%i == 0 && prime[i] == 0 && curNode.x+i <= T && vis[curNode.x+i] == 0){
                queueNode tmp = {curNode.x+i, curNode.dis+1};
                vis[curNode.x+i] = 1;
                Q.push(tmp);
            }
        }
    }
    return -1;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int S, T, CASE, k = 1;
    is_prime();
    while(cin >> S >> T, S, T){
        printf("Case %d: %d\n", k++, bfs(S,T));
    }
    return 0;
}