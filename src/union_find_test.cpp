#include <iostream>
#include <cassert>
#include "union_find.hh"

using namespace std;

int main(){
    UnionFind uf;
    uf.makeSet(1);
    uf.makeSet(2);
    uf.makeSet(3);
    uf.makeSet(4);
    uf.makeSet(5);
    uf.makeSet(6);
    uf.makeSet(7);
    uf.makeSet(8);
    uf.doUnion(1,2);
    uf.doUnion(6,5);
    uf.doUnion(3,4);
    uf.doUnion(6,2);
    assert(uf.getSize(1) == 4);
    assert(uf.getSize(2) == 4);
    assert(uf.getSize(3) == 2);
    assert(uf.getSize(4) == 2);
    assert(uf.getSize(5) == 4);
    assert(uf.getSize(6) == 4);
    assert(uf.getSize(7) == 1);
    assert(uf.getSize(8) == 1);
    assert(uf.find(1) == uf.find(2));
    assert(uf.find(5) == uf.find(6));
    assert(uf.find(3) == uf.find(4));
    assert(uf.find(2) == uf.find(6));
    assert(uf.find(1) == uf.find(6));
    std::cout << "All tests ok" << std::endl;
    return 0;
}
