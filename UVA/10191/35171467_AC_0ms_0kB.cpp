#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Time{
    int start;
    int end;
};

int cmp(Time a, Time b) {
    return a.start < b.start;
}

int main(){
    Time A[100];
    int N, day = 0;
    while(scanf("%d", &N)!=EOF){
        for(int k = 0; k < N; k++){
            int a, b, c, d;
            scanf("%d:%d %d:%d", &a, &b, &c, &d);
            A[k].start = 60*a+b;
            A[k].end = 60*c+d;
            string s; 
            getline(cin, s);
        }
        sort(A, A+N, cmp);
        int nap = 0, cur = 10*60, out = 0;
        for(int i = 0; i < N; i++){
            if(A[i].start-cur > nap){
                nap = A[i].start-cur;
                out = cur;
            }
            cur = A[i].end;
        }
        if(nap < 18*60-cur){
            nap = 18*60-cur;
            out = cur;
        }

        printf("Day #%d: the longest nap starts at ", ++day);
        printf("%02d:%02d and will last for ", out/60, out%60);
        if(nap >= 60) printf("%d hours and ", nap/60);
        printf("%d minutes.\n", nap%60);
    }
    
    return 0;
}

/*
struct TIME{
    int start_hour;
    int start_minute;
    int end_hour;
    int end_minute;
};

bool cmp(TIME a, TIME b){
    if(a.start_hour < b.start_hour) return true;
    else if(a.start_hour == b.start_hour && a.start_minute < b.start_minute) return true;
    return false; 
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N, Case = 1;
    TIME *A;
    while(scanf("%d", &N) != EOF){
        //string line;
        A = new TIME [N+5];
        //getline(cin, line);
        for(int k = 0; k < N; k++){
            //getline(cin, line);
            //const char *t = line.c_str();
            //sscanf(t, "%d:%d %d:%d %*s", &A[k].start_hour, &A[k].start_minute, &A[k].end_hour, &A[k].end_minute);
            int a, b, c, d;
            scanf("%d:%d %d:%d", &a, &b, &c, &d);
            A[k].start_hour = a;
            A[k].start_minute = b;
            A[k].end_hour = c;
            A[k].end_minute = d;
            string s; 
            getline(cin, s);
        }
        sort(A, A+N, cmp);
        int MAX_minute = 0, cur_hour = 10, cur_minute = 0;
        int out_hour = 0, out_minute = 0;

        for(int i = 0; i < N; i++){
            int tmp = 60*(A[i].start_hour-cur_hour)+(A[i].start_minute-cur_minute);
            if(MAX_minute < tmp){
                MAX_minute = tmp;
                out_hour = cur_hour;
                out_minute = cur_minute;
            }
            cur_hour = A[i].end_hour;
            cur_minute = A[i].end_minute;
        }
        if(MAX_minute < 60*(18-cur_hour)-cur_minute){
            MAX_minute = 60*(18-cur_hour)-cur_minute;
            out_hour = cur_hour;
            out_minute = cur_minute;
        }
        //cout << MAX_minute << " " << out_hour << ":" << out_minute << endl;
        if(MAX_minute > 60)
            printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d hours and %d minutes.\n", Case++, out_hour, out_minute, MAX_minute/60, MAX_minute%60);
        else 
            printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d minutes.\n", Case++, out_hour, out_minute, MAX_minute);
    }
    return 0;
}*/
