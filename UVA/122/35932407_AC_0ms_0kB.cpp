#include <bits/stdc++.h>
#define sub(k) k.substr(k.find(',')+1, k.end()-k.begin()-k.find(',')-2)

using namespace std;

string tree[260];

bool cmp(string a, string b){
    string lena = sub(a);//a.substr(a.find(',')+1, a.end()-a.begin()-a.find(',')-2);
    string lenb = sub(b);//b.substr(b.find(',')+1, b.end()-b.begin()-b.find(',')-2);
    if(lena.size() == lenb.size()) return lena < lenb;
    return lena.size() < lenb.size();
}

int main(){
    int cnt = 0;
    //cout << endl;
    while(cin >> tree[++cnt]){
        if(tree[cnt] == "()"){
            cnt--;
            sort(tree+1, tree+cnt+1, cmp);
            bool isTree = 1;
            map<string, int> m;
            for(int i = 1; i <= cnt; i++){
                //cout << tree[i] << endl;
                m[sub(tree[i])]++;
                //cout << m[sub(tree[i])] << endl;
            }
            for(int i = 1; i <= cnt; i++){
                if(m[sub(tree[i])] >= 2){ //more than one value in one node
                    isTree = 0;
                    break;
                }
                if(m[sub(tree[i]).substr(0, sub(tree[i]).size()-1)] == 0){
                    isTree = 0; //no parent of the current node
                    break;
                }
            }
            if(isTree == 0) cout << "not complete" << endl;
            else{
                for(int i = 1; i <= cnt; i++){
                    if(i != 1) cout << " ";
                    cout << tree[i].substr(1, tree[i].find(',')-1);
                }
                cout << endl;
            }
            cnt = 0;
        }
    }    
    return 0;
}