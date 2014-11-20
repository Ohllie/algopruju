#include "subsets.hh"
#include <cassert>
#include <iostream>

int main(){
    vector<int> v = {1,2,3,4};
    auto subsets = generate_subsets(v);
    assert(subsets.size() == 16);
    for(auto subset : subsets){
        for(int x : subset)
            cout << x << " ";
        cout << endl;
    }

    vector<int> empty;
    subsets = generate_subsets(empty);
    assert(subsets.size() == 1 && subsets[0] == empty);
    
    cout << "All tests OK" << endl;
}
