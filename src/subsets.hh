#include <vector>

using namespace std;

vector<vector<int > > generate_subsets(vector<int> v){
    vector<vector<int > > subsets;
    for(int mask = 0; mask < (1 << v.size()); mask++){
        vector<int> subset;
        for(int i = 0; i < v.size(); i++){
            if(mask & (1 << i))
                subset.push_back(v[i]);
        }
        subsets.push_back(subset);
    }
    return subsets;
}

