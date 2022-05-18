#include <iostream>
#include <string>

using namespace std;


int palindrome(string input, int length){

    int end = length/2;

    for(int i = 0; i <= end; i++){
        int j = length-i-1;
        if((input[i] == 'O' && input[j] == '0') || input[i] == '0' && input[j] == 'O'){
            continue;
        }
        if(input[i] != input[j]){
            return 0;
        }
    }
    return 1;
}




int mirror(string input, int length){

    int end = length/2;
    string s1 = "AEHIJLMOSTUVWXYZ12358";
    string s2 = "A3HILJMO2TUVWXY51SEZ8";

    for(int i = 0; i <= end; i++){
        int j = length-i-1;
        if((input[i] == 'O' && input[j] == '0') || input[i] == '0' && input[j] == 'O'){
            continue;
        }
        if(s1.find(input[i], 0) == -1){
            return 0;
        }
        if(s1.find(input[i],0) != s2.find(input[j],0)){
            return 0;
        }
    }
    
    return 1;
}

int main() {
    string s;
    while(cin>>s){
        int n = s.length();
        if(palindrome(s, n) && mirror(s, n))
            cout <<s << " -- is a mirrored palindrome." << endl;
        else if(palindrome(s, n))
            cout << s << " -- is a regular palindrome." << endl;
        else if(mirror(s, n))
            cout << s << " -- is a mirrored string." << endl;
        else 
            cout << s << " -- is not a palindrome." << endl;
        cout << endl;
    }
    return 0;
}