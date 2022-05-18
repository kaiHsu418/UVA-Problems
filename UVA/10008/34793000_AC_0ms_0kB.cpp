#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {


    int K;
    int k = 0;
    cin >> K;
    int freq[26];

    for(int i = 0; i < 26; i++){
        freq[i] = 0;
    }


    while(k <= K){
        string input;
        char c = getchar();
        if(c == '\n') k++;
        else {
            if(c <= 'z' && c >= 'a'){
                freq[c-'a']++;
            }
            else if( c <= 'Z' && c >= 'A'){
                freq[c-'A']++;
            }
        }
    }

    int max = 0;
    for(int i = 0; i < 26; i++){
        if(freq[i] > max){
            max = freq[i];
        }
    }

    for(int i = max; i >= 1; i--){
        for(int j = 0; j < 26; j++){
            if(i == freq[j]){
                printf("%c %d\n",'A'+j,i);
            }
        }
    }


    return 0;
}