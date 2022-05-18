#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Calls{
    public:
        int time, duration, target;
        Calls(int a, int b, int c):
            time(a), duration(b), target(c) {}
};

vector <Calls> F[10000];
int vis[10000]; 

int dfs(int source, int time){
    vis[source] = 1;
    for(int i = 0; i < F[source].size(); i++){
        if(F[source][i].time <= time && time <= F[source][i].time+F[source][i].duration){
            if(vis[F[source][i].target]) return 9999;
            else return dfs(F[source][i].target, time);
        }
    }
    return source;
}

int main(){
    
    int N, cases = 0;
    cin >> N;
    cout << "CALL FORWARDING OUTPUT" << endl;
    int system = 1;

    while(N--){
        printf("SYSTEM %d\n", ++cases);
        int source, time, duration, target;
        for(int i = 0; i < 10000; i++){
            F[i].clear();
        }
        while(cin >> source, source){
            cin >> time >> duration >> target;
            F[source].push_back(Calls(time, duration, target));
        }
        while(cin >> time, time != 9000){
            cin >> source;
            memset(vis, 0, sizeof(vis));
            printf("AT %04d CALL TO %04d RINGS %04d\n", time, source, dfs(source, time));
        }
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}