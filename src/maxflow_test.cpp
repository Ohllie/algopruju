#include <iostream>
#include "maxflow.hh"
using namespace std;

int main() {
  while (!cin.eof() && cin.good()) {
    int n;
    cin >> n;
    Mat g(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g(i, j);
      }
    }

    Mat result(n);
    cout << maxflow(g, 0, n - 1, result) << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << result(i, j) << " ";
      }
      cout << endl;
    }
  }
}
