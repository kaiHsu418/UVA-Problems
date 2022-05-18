#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int N;
    
    while(cin >> N){
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        int MAXK = min(A[0], A[N-1]);
        for(int i = MAXK; i >= 1; i--){
            vector<int> s = A;
            int l = 0, r = N-1, k = i;
            while(l <= r && s[l] >= k && s[r] >= k){
                s[l]-=k;
                s[r]-=k;
                if(s[l] == 0) l++;
                if(s[r] == 0) r--;
                k--;
                if(k == 0){
                    int sum = 0;
                    for(int j = l; j <= r; j++){
                        sum+=s[j];
                    }
                    if((sum%2 == 0 && i > 1) || (sum == 0 && i == 1)) cout << i << endl;
                    else cout << "no quotation" << endl;
                    break;
                }
            }
            if(k == 0) break;
        }
    }

    return 0;
}