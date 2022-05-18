#include <iostream>
#include <string.h>

using namespace std;



int main(){

    int mx, my;
    cin >> mx >> my;

    int x, y;
    char dir;
    int grid[105][105];
    memset(grid, 0, sizeof(grid));

    while(cin >> x >> y >> dir){
        int lost = 0;
        string s;
        cin >> s;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(s[i] == 'F'){
                switch(dir) {
                    case 'N': y++; break;
                    case 'E': x++; break;
                    case 'W': x--; break;
                    case 'S': y--; break;
                }
            }
            else if(s[i] == 'R'){
                switch(dir) {
                    case 'N': dir = 'E'; break;
                    case 'E': dir = 'S'; break;
                    case 'W': dir = 'N'; break;
                    case 'S': dir = 'W'; break;
                }
            }
            else{
                switch(dir) {
                    case 'N': dir = 'W'; break;
                    case 'E': dir = 'N'; break;
                    case 'W': dir = 'S'; break;
                    case 'S': dir = 'E'; break;
                }
            }
            if(x < 0 || y < 0 || x > mx || y > my){
                switch(dir) {
                    case 'N': y--; break;
                    case 'E': x--; break;
                    case 'W': x++; break;
                    case 'S': y++; break;
                }
                //cout << "133" << endl;
                if(grid[x][y] != 1){
                    lost = 1;
                    grid[x][y] = 1;
                    //cout << "123" << endl;
                    break;
                }
            }
        }

        if(!lost)
            printf("%d %d %c\n", x, y, dir);
        else {
            printf("%d %d %c LOST\n", x, y, dir);
        }

    }

    return 0;
}