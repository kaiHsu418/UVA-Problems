#include <iostream>
#include <climits>
using namespace std;

int ans = 0;

void merge(int A[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1], R[n2+1];
    for(int i = 0; i < n1; i++){
        L[i] = A[p+i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = A[q+1+i];
    }
    L[n1] = INT_MAX; R[n2] = INT_MAX;
    int i = 0, j = 0;
    for(int k = p; k <= r; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
            ans+=n1-i;
        }
    }
}

void merge_sort(int A[], int p, int r){
    if(p<r){
        int q = (p+r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}


int main(){

    int N;
    while(cin >> N, N){
        int A[N];
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        ans = 0;
        merge_sort(A, 0, N-1);
        if(ans%2) cout << "Marcelo";
        else cout << "Carlos";
        cout << endl;
    }
    return 0;
}