#include <bits/stdc++.h>

using namespace std;

int queenBoard[100][8]; //92 types queens
int q[8];
int cnt = 0;

bool valid(int row, int col){
    for (int i = 0; i < col; i++) {
		if (q[i] == row || col-i == row-q[i] || col-i == q[i]-row)
		    return 0;
	}
	return 1;
}

void backtrack(int col){
    if(col == 8){
        for(int i = 0; i < 8; i++){
            queenBoard[cnt][i] = q[i]+1;
        }
        cnt++;
    }
    else{
        for(int i = 0; i < 8; i++){
            if(valid(i, col)){
                q[col] = i;
                backtrack(col+1);
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    backtrack(0);
    int col[8], Case = 0;
    while(scanf("%d", &col[0])!=EOF){
        for(int i = 1; i < 8; i++){
            scanf("%d", &col[i]);
        }
        int ans = INT_MAX;
        for(int i = 0; i < cnt; i++){
            int tmp = 0;
            for(int j = 0; j < 8; j++){
                if(queenBoard[i][j] != col[j]) tmp++;
            }
            ans = min(ans, tmp);
        }
        printf("Case %d: %d\n", ++Case, ans);    
    }
    //cout << cnt << endl;
    return 0;
}