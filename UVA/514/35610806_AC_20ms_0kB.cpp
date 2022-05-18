#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    //vector<int> target;
    while(cin >> N, N){
        //queue<int> target;
        int k;
        while(cin >> k, k){
            queue<int> target;
            target.push(k);
            for(int i = 1; i < N; i++){
                cin >> k;
                target.push(k);
            }
            stack<int> s;
            for(int i = 1; i <= N; i++){
                s.push(i);
                while(!s.empty() && s.top() == target.front()){
                    s.pop();
                    target.pop();
                }
            }
            cout << (s.empty() ? "Yes":"No") << endl;
        }
        cout << endl;
    
    }


    return 0;
}
