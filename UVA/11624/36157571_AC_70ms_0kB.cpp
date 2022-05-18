#include <iostream>
#include <queue>
#include <string>

using namespace std;

int row, col;
char G[1005][1005];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int jx, jy;

struct pos{
    int x, y, dis;
    bool state; //1 for the fire
}cur, Next, tmp;

int bfs(){
    queue<pos> q;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(G[i][j] == 'F'){
                cur.x = i; cur.y = j; cur.dis = 0; cur.state = 1;
                q.push(cur);
                G[i][j] = '#';
            }
        }
    }
    cur.x = jx; cur.y = jy; cur.dis = 0; cur.state = 0;
    q.push(cur);
    while(!q.empty()){
        cur = q.front(); q.pop();
        //cout << cur.x << " " << cur.y << endl;
        if(cur.state){
            for(int i = 0; i < 4; i++){
                int xx = cur.x+dx[i];
                int yy = cur.y+dy[i];
                if(xx >= 0 && yy >= 0 && xx < row && yy < col && G[xx][yy] != '#'){
                    G[xx][yy] = '#';
                    Next.x = xx; Next.y = yy; Next.dis = cur.dis+1; Next.state = 1;
                    q.push(Next);
                }
            }
        }
        else{
            for(int i = 0; i < 4; i++){
                int xx = cur.x+dx[i];
                int yy = cur.y+dy[i];
                if(xx < 0 || yy < 0 || xx == row || yy == col) return cur.dis+1;
                if(G[xx][yy] != '#'){
                    //cout << cur.x << " " << cur.y << endl;
                    G[xx][yy] = '#';
                    Next.x = xx; Next.y = yy; Next.dis = cur.dis+1; Next.state = 0;
                    q.push(Next);
                }
            }
        }
    }
    return 0;
}

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);
    int T; 
    cin >> T;
    while(T--){
        cin >> row >> col;
        for(int i = 0; i < row; i++){
            scanf("%s", G[i]);
            for(int j = 0; j < col; j++){
                //cout << G[i][j];
                if(G[i][j] == 'J'){
                    jx = i; jy = j; G[i][j] = '#';
                    //cout << i << " " << j << endl;
                }
            }
        }
        int ans = bfs();
        if(ans) printf("%d\n", ans);//cout << ans << endl;
        else printf("IMPOSSIBLE\n");//cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
