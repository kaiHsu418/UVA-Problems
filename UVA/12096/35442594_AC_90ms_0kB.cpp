#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>

using namespace std;


int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        stack< set<int> > S;
        map< set<int>, int> M;
        int cnt = 0;
        for(int i = 0; i < N; i++){
            string op;
            cin >> op;
            if(op[0] == 'P') {
                set<int> tmp;
                S.push(tmp);
            }
            else if(op[0] == 'D'){
                set<int> tmp = S.top();
                S.pop();
                S.push(tmp);
                S.push(tmp);
            }
            else if(op[0] == 'A'){
                set<int> tmp = S.top();
                S.pop();
                if(!M.count(tmp)){
                    S.top().insert(cnt);
                    M[tmp] = cnt;
                    cnt++;
                }
                else if(!S.top().count(M[tmp])){
                    S.top().insert(M[tmp]);
                }
            }
            else if(op[0] == 'U'){
                set<int> tmp1 = S.top();
                S.pop();
                set<int> tmp2 = S.top();
                S.pop();
                set<int> tmp;
                for(auto i : M){
                    int x = i.second;
                    if(tmp1.count(x) || tmp2.count(x)) tmp.insert(x);
                }
                S.push(tmp);
            }
            else{
                set<int> tmp1 = S.top();
                S.pop();
                set<int> tmp2 = S.top();
                S.pop();
                set<int> tmp;
                for(auto i : M){
                    int x = i.second;
                    if(tmp1.count(x) && tmp2.count(x)) tmp.insert(x);
                }
                S.push(tmp);
            }
            cout << S.top().size() << endl;
        }
        cout << "***" << endl;
    } 
    return 0;
}