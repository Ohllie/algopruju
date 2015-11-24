#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
vector<int> get_border_array(string& P){
    vector<int> B(P.size()+1);
    if(B.size() == 1) return B;
    for(int L = 2; L <= P.size(); L++){
        int prev_longest = L-1;
        while(prev_longest != 0){
            prev_longest = B[prev_longest];
            if(P[L-1] == P[prev_longest]){
                B[L] = prev_longest + 1;
                break;
            }
        }
    }
   return B;
   
}
 
vector<int> kmp(string& P, string& S){
    auto B = get_border_array(P);
    int length = 0;
    vector<int> occurrences;
    for(int i = 0; i < S.size(); i++){
        while(length == P.size() || P[length] != S[i]){
            length = B[length];
            if(length == 0) break;
        }
        if(S[i] == P[length]) length++;
        if(length == P.size()) occurrences.push_back(i-P.size()+1);
    }
    return occurrences;
}
 
static void example_usage(){
    string s = "ababbaabbaababaaababa";
    string p = "aba";
    for(auto i : kmp(p,s)) cout << i << " "; cout << endl;
}
