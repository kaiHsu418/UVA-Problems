#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int S[2005];
int length1[2005], length2[2005];


int lis(int N){
    int ans = 0;
    for(int i = N; i > 0; i--) length1[i] = 1, length2[i] = 1;
    for(int i = N; i > 0; i--){
        for(int j = N; j > i; j--){
            if(S[i] < S[j]) length1[i] = max(length1[i], length1[j]+1);
            else length2[i] = max(length2[i], length2[j]+1);
        }
        ans = max(ans, length1[i]+length2[i]-1);
    }
    return ans;
}



int main()
{
    int K, N;
    cin >> K;
    while(K--){
        cin >> N;
        for(int i = 1; i <= N; i++){
            cin >> S[i];
        }
        cout << lis(N) << endl;
    }
    return 0;
}
