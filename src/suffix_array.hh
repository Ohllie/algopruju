#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> get_suffix_array(const vector<int>& seq){
    if(seq.size() == 0) return vector<int>();

    vector<int> cur = seq;
    int n = cur.size();
    for(int length = 1; ; length *= 2){
        vector<pair<pair<int,int>, int> > pairs(n); // pair, original position index
        for(int i = 0; i < n; i++){
           auto new_pair = make_pair(cur[i], i + length < n ? cur[i+length] : -1);
           pairs[i] = make_pair(new_pair, i);
        }
        sort(pairs.begin(), pairs.end());
        int code = 0;
        for(int i = 0; i < n; i++){
            if(i != 0 && pairs[i].first != pairs[i-1].first)
                code++;
            cur[pairs[i].second] = code;
        }
        if(code == n-1){
            vector<int> result(n);
            for(int i = 0; i < n; i++)
                result[i] = pairs[i].second;
            return result;
        }
    }
}

