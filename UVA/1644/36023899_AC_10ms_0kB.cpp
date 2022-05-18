#include <iostream>
#include <cmath>
#include <string.h>
#define MAXN 1299709

using namespace std;

int P[MAXN+5], n;

void Prime(){
    memset(P, 0, sizeof(P));
    int M = sqrt(MAXN)+1;
    for(int i = 2; i <= M; i++){
        if(!P[i]){
            for(int j = i*i; j <= MAXN; j += i) P[j] = 1;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    Prime();
    while(cin >> n, n){
        if(!P[n]) cout << 0 << endl;
        else{
            int l = n, r = n;
            while(P[l]) l--;
            while(P[r]) r++;
            cout << r-l << endl;
        }
    }
    return 0;
}
//
