#include <bits/stdc++.h>

using namespace std;

int main()
{
    int M, N, r, c;
    while(scanf("%d%d", &r, &c), r+c){
        int ans, M = r, N = c;
        if(M>N) swap(M, N);
        if (M == 1) ans = N;
        else if (M == 2) ans = 2*((N+3)/4+(N+2)/4);
        else ans = (M*N+1)/2;
        printf("%d knights may be placed on a %d row %d column board.\n", ans, r, c);
    }
    return 0;
}
