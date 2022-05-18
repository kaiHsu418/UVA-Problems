#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

long long D[32];

long long count1(long long n){
    long long ans = 0; 
    int highest;
    if(n < 1) return 0;
    else if(n == 1) return 1;
    highest = log2(n);
    //long long left = n - (1LL<<highest);
    if(highest) ans += D[highest-1];
    return ans+count1(n-(1LL<<highest))+(n-(1LL<<highest)+1);
}   

void init(){
    //this initial is use for recording the 
    //frequence of the bit i-th that is one
    D[0] = 1;
    for(int i = 1; i < 32; i++){
        D[i] = (D[i-1]<<1) + (1<<i);
    }
}


int main(){
    
    int Case = 0;
    long long a, b;
    memset(D, 0, sizeof(D));
    init();
    while(scanf("%lld %lld", &a, &b) != EOF){
        if(a == 0 && b == 0) break;
        long long int ans = 0;/*
        for(long long int i = a; i <= b; i++){
            ans+=__builtin_popcountll(i);
        }*/
        printf("Case %d: %lld\n", ++Case, count1(b)-count1(a-1));
    }
    return 0;
}
