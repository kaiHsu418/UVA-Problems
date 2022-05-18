#include <stdio.h>


int main(){

    int a1, a2;

    while(scanf("%d%d", &a1, &a2) == 2){
        int max = 0;
        int start, end;
        if(a1 < a2){
            start = a1;
            end = a2;
        }
        else{
            start = a2;
            end = a1;
        }
        for(int i = start; i <= end; i++){
            int tmp = i;
            int cnt = 0;

            while(1){
                //cout << tmp << " " ;
                if(tmp == 1){
                    cnt++;
                    break;
                }
                else if(tmp%2 == 1){
                    tmp = 3*tmp+1; 
                    cnt++;
                }
                else{
                    tmp/=2;
                    cnt++;
                }
            }
            if(max < cnt) max = cnt;
        }
        printf("%d %d %d\n", a1, a2, max);
    }
    return 0;
}