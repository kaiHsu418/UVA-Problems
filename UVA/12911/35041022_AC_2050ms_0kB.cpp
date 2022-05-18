#include <iostream>
#include <map>
#include <vector>

using namespace std;

void subsetSum(long long curSum, map<long long, int> &S, vector<long long> subset, int index){
    for(int i = index; i < subset.size(); i++){
        curSum+=subset[i];
        //cout << curSum <<" ";
        S[curSum]++;
        //cout << S[curSum] << endl;
        subsetSum(curSum, S, subset, i+1);
        curSum-=subset[i];
    }
}


int main(){

    long long N, T;
    while(cin >> N >> T){

        vector<long long> subset1, subset2;
        long long left, right;
        left = N/2;
        right = N-left;
        for(int i = 0; i < left; i++){
            long long tmp;
            cin >> tmp;
            subset1.push_back(tmp);
        }
        for(int i = 0; i < right; i++){
            long long tmp;
            cin >> tmp;
            subset2.push_back(tmp);
        }
        
        map<long long, int> S1, S2;

        subsetSum(0, S1, subset1, 0);
        subsetSum(0, S2, subset2, 0);
        
        long long cnt = 0;
        for(auto i:S1){
            if(S2.find(T-i.first) != S2.end());{
                cnt+= (long long) i.second*S2[T-i.first];
            }
        }
        cout << cnt + S1[T] + S2[T] << endl;
    }
    return 0;
}