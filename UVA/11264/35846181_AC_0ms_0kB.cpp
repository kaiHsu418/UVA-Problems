#include <bits/stdc++.h>

using namespace std;

int C[1005];
int main()
{
    int n, T, acc, ans;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &C[i]);
        acc = 0, ans = 0;
        for(int i = 0; i < n-1; i++){
            if(acc+C[i] < C[i+1]){
                acc+=C[i];
                ans++;
            }
        }
        printf("%d\n", ans+1);
    }
    return 0;
}
