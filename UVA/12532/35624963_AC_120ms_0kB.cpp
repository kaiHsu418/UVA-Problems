#include <bits/stdc++.h>

using namespace std;

int X[100005], BIT[100005];
int ST[400100];
int N, K;
/*
void buildBIT(){
    for(int i = 0; i < N; i++){
        BIT[i+1] = X[i]; 
    }
    for(int i = 1; i <= N; i++){
        int j = i+(i & -i);
        if(j <= N) BIT[j] += BIT[i];
    }
}

void update(int id, int delta){
    while(id <= N){
        BIT[id] += delta;
        id += (id & -id);
    }
}

int prefixSum(int id){
    int ans=1;
    while(id > 0){
        ans += BIT[id];
        id -= (id & -id);
    }
    return ans;
}*/
//index of segment tree: idx
// left, right: l, r
//update value, the update position: v, pos
void update(int id, int l, int r, int pos, int v){
    if(l > pos || r < pos) return;
    if(l == pos && r == pos){
        ST[id] = v;
        return;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, pos, v);
    update(id*2+1, mid+1, r, pos, v);
    ST[id] = ST[id*2]*ST[id*2+1];
}
//target segment l to r
int query(int id, int l, int r, int x, int y){
    if(l > y || r < x) return 1;
    if(l >= x && r <= y) return ST[id];
    int mid = (l+r)/2; //combine the two segment value
    return query(2*id, l, mid, x, y)*query(2*id+1, mid+1, r, x, y);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while(cin >> N >> K){
        memset(ST, 0, sizeof(N+5));
        for(int i = 0; i < N; i++){
            int x;
            cin >> x;
            x = x ? (x>0 ? 1 : -1) : 0;
            update(1, 1, N, i+1, x);
        }
        for(int i = 0; i < K; i++){
            char op;
            cin >> op;
            if(op == 'C'){
                int pos, x;
                cin >> pos >> x;
                x = x ? (x>0 ? 1 : -1) : 0;
                update(1, 1, N, pos, x);
            }
            else{
                int l, r;
                cin >> l >> r;
                int ans = query(1, 1, N, l, r);
                char out = ans? ((ans == 1) ? '+' : '-') : '0';
                cout << out;
            }
        }
        cout << endl;

    }
    return 0;
}