#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int vis[205][205];
int ans[205];

class node{
    public:
    int v[3], dist;
    //node(int v[], int dist): v(v), dist(dist){}
};

bool operator< (const node& a, const node& b){
    return a.dist > b.dist;
}


void bfs(int a, int b, int c, int d){
    memset(vis, 0, sizeof(vis));
    memset(ans, -1, sizeof(ans));
    int cap[3] = {a, b, c};//compare the current capacity
    node start;
    start.v[0] = 0;
    start.v[1] = 0;
    start.v[2] = c;
    start.dist = 0;
    priority_queue<node, vector<node>, less< vector<node>::value_type> > q;
    q.push(start);
    vis[0][0] = 1;
    while(!q.empty()){
        node cur = q.top();
        q.pop();
        for(int i = 0; i < 3; i++){
            if(ans[cur.v[i]] < 0 || ans[cur.v[i]] > cur.dist) ans[cur.v[i]] = cur.dist;
        }
        if(ans[d] >= 0) return;
        
        for(int i = 0; i < 3; i++){ //from the i cup to the j cup
            for(int j = 0; j < 3; j++){
                if(i != j && cur.v[i] != 0 && cur.v[j] != cap[j]) {//if the j cup is full
                    int amount = min(cap[j], cur.v[i]+cur.v[j]) - cur.v[j];
                    node next;
                    memcpy(&next, &cur, sizeof(cur));
                    next.dist = cur.dist+amount;
                    next.v[i] -= amount;
                    next.v[j] += amount;
                    if(!vis[next.v[1]][next.v[0]]){
                        vis[next.v[1]][next.v[0]] = 1;
                        q.push(next);
                    }
                }
            }
        }
    }
}



int main(){

    int N;
    cin >> N;
    while(N--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bfs(a, b, c, d);
        while(d >= 0){
            if(ans[d] >= 0){
                printf("%d %d\n", ans[d], d);
                break;
            }
            d--;
        }
    }
    return 0;
}

/*
2
2 3 4 2
96 97 199 62
*/