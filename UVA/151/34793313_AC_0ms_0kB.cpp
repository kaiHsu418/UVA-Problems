#include <iostream>

using namespace std;

int josph(int i, int m){
    if(i == 1) return 0;
    else return (josph(i-1, m)+m)%(i);
}


int main(){

    int n;
    //int i = 16, m = 5;
    //cout << josph(i, m) << endl;

    while(cin >> n, n){

        for(int i = 1; i < n; i++){
            if(josph(n-1, i) == 11) {
                cout << i << endl;
                break;
            }
        }
        
    }



    return 0;
}