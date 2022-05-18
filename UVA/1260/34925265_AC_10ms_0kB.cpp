#include <iostream>

using namespace std;



int main(){
    int n;
    cin >> n;
    int A[1005];
    while(n--){

        int length;
        int cnt = 0;
        cin >> length;
        for(int i = 0; i < length; i++){
            cin >> A[i];
            for(int j = 0; j < i; j++){
                if(A[j] <= A[i]){
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}