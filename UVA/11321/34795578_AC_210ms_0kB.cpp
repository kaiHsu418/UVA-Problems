#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int m, n;


int isOdd(int a){
    return abs(a%2);
}

bool cmp(int a, int b){
    if(a%m != b%m) return a%m < b%m;
    if(isOdd(a) != isOdd(b)) return isOdd(a);
    if(isOdd(a)) return a > b;
    return a < b;
}



int main(){

    while(cin >> n >> m, n){
        int A[10005];
        cout << n << " " << m << endl;

        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        sort(A, A+n, cmp);
        for(int i = 0; i < n; i++){
            cout << A[i] << endl;
        }
    }
    cout << 0 << " " << 0 << endl;
    return 0;
}