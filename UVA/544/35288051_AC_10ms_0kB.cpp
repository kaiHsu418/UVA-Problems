#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> city2id;
int graph[205][205];
int N, R;

int main(){
    int CASE = 0;
    while(cin >> N >> R, N, R){
        int cnt = 1;
        city2id.clear();
        for(int i = 0; i < R; i++){
            string city1, city2;
            int weight;
            cin >> city1 >> city2 >> weight;
            int u, v;
            if(city2id.find(city1) != city2id.end()){
                u = city2id[city1];
            }
            else{
                u = cnt++;
                city2id[city1] = u;
            }
            if(city2id.find(city2) != city2id.end()){
                v = city2id[city2];
            }else{
                v = cnt++;
                city2id[city2] = v;
            }
            graph[u][v] = weight;
            graph[v][u] = weight;
        }
        string start_city, end_city;
        cin >> start_city >> end_city;

        for(int k = 1; k <= N; k++){
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++){
                    graph[i][j] = max(graph[i][j], min(graph[i][k], graph[k][j]));
                }
            }
        }
        printf ("Scenario #%d\n", ++CASE);
        printf ("%d tons\n\n", graph[city2id[start_city]][city2id[end_city]]);
    }
    return 0;
}

/*
4 3
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Muenchen
5 5
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Hamburg 220
Hamburg Muenchen 170
Muenchen Karlsruhe
0 0

*/