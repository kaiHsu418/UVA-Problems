#include <iostream>
#include <string.h>

using namespace std;
long long f[50];
/*
string bfs(int N){
    string s;
    if(N == 0) s = "0";
    else if(N == 1) s = "1";
    else s = bfs(N-2)+bfs(N-1);
    return s;
}*/
void search(int n, long long l, long long r){
    if(l > r) return;
    if(n == 0) cout << '0';
    else if(n == 1) cout << '1';
    else{
        if(l < f[n-2] && r < f[n-2]) {
            search(n-2, l, r);
        }
        else if(l < f[n-2] && r >= f[n-2]) {
            search(n-2, l, f[n-2]-1);
            search(n-1, 0, r-f[n-2]);
        }
        else search(n-1, l-f[n-2], r-f[n-2]);
    }
}

void init(){
    f[0] = 1, f[1] = 1;
    for(int i = 2; i < 50; i++){
        f[i] = f[i-1]+f[i-2];
    }
}

int main(){
    int T;
    cin >> T;
    init();
    while(T--){
        long long N, I, J;
        cin >> N >> I >> J;
        /*
        string s = bfs(N);
        cout << s << endl;
        cout << s.substr(I, J-I+1) << endl;*/
        if(N >= 48) N = 48-(N%2);//since the 48th length will be larger than 2^32
        search(N, I, J);
        cout << endl;
    }
    return 0;
}
/*
3 
3 1 2 
1 0 0 
9 5 12*/