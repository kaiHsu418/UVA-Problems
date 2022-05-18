#include <iostream>
#include <stdio.h>
#include <algorithm>


using namespace std;

int main(){

    int CASE = 0, t;
    char s[105];
    scanf("%d", &t);
    
    while(t--){

        scanf("%s" , s);
        printf("Case #%d:\n", ++CASE);
        char board[205][205] = {};

        int row = 100, maxrow = 100, minrow = 100;
        
        int i;
        for(i = 0; s[i]; i++){
            if(s[i] == 'R'){
                if(i && s[i-1] == 'R') row++;
                board[row][i] = '/';
                if(s[i+1] == 'C') row++;
            }
            else if(s[i] == 'F'){
                if(i && s[i-1] != 'R') row--;
                board[row][i] = '\\';
            }
            else {
                board[row][i] = '_';
            }
            
            maxrow = max(maxrow, row);
            minrow = min(minrow, row);

        }

        int k, j, len = i;

        for(i = maxrow; i >= minrow; i--) {
            putchar('|'), j = 50;
            putchar(' ');
            while(!board[i][j]) j--;
            for(k = 0; k <= j; k++)
                printf("%c", !board[i][k] ? ' ' : board[i][k]);
            puts("");
        }
        putchar('+');
        for(i = -1; i <= len; i++)
            putchar('-');
        puts("\n");
    }

    return 0;
}