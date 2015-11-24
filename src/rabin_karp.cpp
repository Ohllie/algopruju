#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
typedef long long LL;
 
vector<int> rabin_karp(string& p, string& s){
    vector<int> occurrences;
    LL x = 2452343;
    LL mod = 1e9+7;
   
    LL p_hash = 0;
    for(char c : p) p_hash = (p_hash * x + c) % mod;
   
    LL s_hash = 0;
    for(int i = 0; i < p.size(); i++) s_hash = (s_hash * x + s[i]) % mod;
   
    if(p_hash == s_hash) occurrences.push_back(0);
   
    LL x_pow = 1;
    for(int i = 0; i < p.size(); i++) x_pow = (x_pow * x) % mod;
   
    for(int i = p.size(); i < s.size(); i++){
        s_hash = (s_hash * x + s[i]) % mod;
        s_hash -= (x_pow * s[i-p.size()]) % mod;
        if(s_hash < 0) s_hash += mod;
        if(s_hash == p_hash) occurrences.push_back(i-p.size()+1);
    }
    return occurrences;
}
 
static void example_usage(){
    string s = "ababbaabbaababaaababa";
    string p = "aba";
    for(auto x : rabin_karp(p,s)) cout << x << " "; cout << endl;
}
