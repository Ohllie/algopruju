#include <map>

using namespace std;

class UnionFind {
public:
  class UF_element {
  public:
    int size;
    UF_element *parent;
    int id;
    UF_element(int id) : size(1), parent(this), id(id) {}
  };

  std::map<int, UF_element *> idToElement;
  void makeSet(int id); // Creates a new set with identifier id
  int find(int id);     // Returns the identifier of the set that contains the
                        // parameter id
  void doUnion(int id_1,
               int id_2); // Merges the two sets given by the identifiers
  int getSize(int id);    // Returns the size of the set

  ~UnionFind();
};

UnionFind::~UnionFind() {
  for (pair<int, UF_element *> p : idToElement)
    delete p.second;
}

void UnionFind::makeSet(int id) {
  UF_element *x = new UF_element(id);
  idToElement[id] = x;
}

int UnionFind::find(int id) {
  UF_element *p = idToElement.at(id);
  while (p->id != p->parent->id) {
    p = p->parent;
  }
  return p->id;
}

void UnionFind::doUnion(int id_1, int id_2) {
  UF_element *p1 = idToElement.at(find(id_1));
  UF_element *p2 = idToElement.at(find(id_2));
  if (p1->id == p2->id)
    return;
  if (p1->size < p2->size) {
    p1->parent = p2;
    p2->size += p1->size;
  } else if (p2->size < p1->size) {
    p2->parent = p1;
    p1->size += p2->size;
  } else { // Equal sizes
    p2->parent = p1;
    p1->size += p2->size;
  }
}

int UnionFind::getSize(int id) { return idToElement.at(find(id))->size; }
