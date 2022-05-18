#include <iostream>
#include <string.h>

using namespace std;



int main(){

    int n;
    int LUT[1005];

    memset(LUT, -1, sizeof(LUT));

    for(int i = 1; i <= 1000; i++){
        int s = 0;
        for(int j = 1; j <= i; j++){
            if(i%j == 0) s += j;
        }
        if(s <= 1000) LUT[s] = i;
    }

    int k = 1;
    while(cin >> n, n){ 
        cout << "Case " << k << ": " << LUT[n] << endl;
        k++;
    }
    return 0;
}