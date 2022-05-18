#include <bits/stdc++.h>

using namespace std;

int row, col, level;

struct pos{
    int x, y, z;
};

char maze[32][32][32];
int dis[32][32][32];
pos S;
int xdir[] = {-1, 1, 0, 0, 0, 0};
int ydir[] = {0, 0, -1, 1, 0, 0};
int zdir[] = {0, 0, 0, 0, -1, 1};


int valid(pos v){
    if(v.x < 0 || v.x >= level || v.y < 0 || v.y >= row || v.z < 0 || v.z >= col) return 0;
    return 1;
}

int bfs(){
    queue<pos> q;
    q.push(S);
    pos u, v;
    dis[S.x][S.y][S.z] = 0;
    maze[S.x][S.y][S.z] = '#';
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i = 0; i < 6; i++){
            v.x = u.x+xdir[i];
            v.y = u.y+ydir[i];
            v.z = u.z+zdir[i];
            if(valid(v) && maze[v.x][v.y][v.z] != '#'){
                //cout << v.x << v.y << v.z << " " << dis[v.x][v.y][v.x] << endl;
                if(maze[v.x][v.y][v.z] == '.') dis[v.x][v.y][v.z] = dis[u.x][u.y][u.z]+1;
                else if(maze[v.x][v.y][v.z] == 'E') return dis[u.x][u.y][u.z]+1;
                maze[v.x][v.y][v.z] = '#';
                q.push(v);
            }
        }
    }
    return -1;
}


int main(){
    while(cin >> level >> row >> col){
        if(level == 0 && row == 0 && col == 0) break;
        for(int i = 0; i < level; i++){
            for(int j = 0; j < row; j++){
                scanf("%s", maze[i][j]);
                for(int k = 0; k < col; k++){
                    if(maze[i][j][k] == 'S'){
                        S.x = i, S.y = j, S.z = k;
                    }
                }
            }
        }

        int ans = bfs();
        if(ans == -1) cout << "Trapped!" << endl;
        else cout << "Escaped in " << ans << " minute(s)." << endl;
    }
    return 0;
}

/*
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###
0 0 0

*/
