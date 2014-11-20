#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    // Iterate all permutations of v in lexicographical order
    vector<int> v = {6,1,2,7,5};
    vector<int> current = v;
    sort(current.begin(), current.end());
    do{
        for(int x : current) cout << x << " ";
        cout << endl;
    } while(next_permutation(current.begin(), current.end()));
}
