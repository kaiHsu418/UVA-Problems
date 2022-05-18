#include <iostream>

using namespace std;


int main(){
    int k;
    cin >> k;

    while(k--){

        int n;
        cin >> n;

        int cur;
        int max = -10000000;
        int max_dis = -10000000;
        //cout << max << " " << max_dis << endl;
        for(int i = 0; i < n; i++){
            cin >> cur;
            //cout << cur  << endl;
            if(max - cur > max_dis) max_dis = max-cur;
            if(cur > max) max = cur;
        }
        cout << max_dis << endl;
    }
    return 0;
}