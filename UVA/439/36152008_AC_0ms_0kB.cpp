#include <iostream>
#include <queue>
#include <utility>
#include <string.h>
#define pa pair<int, int>


using namespace std;

int dir1[8] = {-2, -2, -1, 1, 2, -1, 1, 2};
int dir2[8] = {1, -1, 2, 2, 1, -2, -2, -1};
int vis[9][9];


int bfs(pa s, pa d){
    memset(vis, -1, sizeof(vis));
    queue<pa> q;
    pa u, v;
    vis[s.first][s.second] = 0;
    q.push(s);
    while(!q.empty()){
        pa u = q.front(); q.pop();
        for(int i = 0; i < 8; i++){
            int x = u.first+dir1[i];
            int y = u.second+dir2[i];
            if(x >= 1 && x <= 8 && y >= 1 && y <= 8 && vis[x][y] == -1){
                vis[x][y] = vis[u.first][u.second]+1;
                v.first = x; v.second = y;
                q.push(v);
            }
            if(v == d) break;
        }
    }
    return vis[d.first][d.second];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b;
    while(cin >> a >> b){
        pa s, d;
        int sx = a[0]-'a'+1, sy = a[1]-'0';
        int dx = b[0]-'a'+1, dy = b[1]-'0';
        //cout << sx << " " << sy << " " << dx << " " << dy << endl;
        s.first = sx; s.second = sy;
        d.first = dx; d.second = dy;
        int ans = bfs(s, d);
        cout << "To get from " << a << " to " << b << " takes " << ans <<" knight moves." << endl;
    }
    return 0;
}