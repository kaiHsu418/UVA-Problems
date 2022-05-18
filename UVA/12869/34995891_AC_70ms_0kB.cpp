#include <iostream>
#include <algorithm>


using namespace std;


int main(){

    long long int low, high;

    while(cin >> low >> high, low, high){
        cout << high/5-low/5+1 << endl;
    }
    return 0;
}