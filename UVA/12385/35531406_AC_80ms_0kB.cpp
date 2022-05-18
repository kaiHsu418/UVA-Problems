#include <iostream>
#include <string.h>

using namespace std;


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N;
    cin >> N;
    while(N--){
        int len;
        int s[100005] = {0};
        cin >> len;
        for(int i = 0; i < len; i++){
            cin >> s[i];
        }
        int last = 0;
        int ans = 0;
        int pos[100005];
        memset(pos, -1, sizeof(pos));
        for(int i = 0; i < len; i++){
            if(pos[s[i]] != -1){
                if(pos[s[i]] >= last){
                    ans++;
                    last = i;
                }
            }
            pos[s[i]] = i;
        }
        cout << ans << endl;
    }
    return 0;
}
