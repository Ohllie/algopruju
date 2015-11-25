#include <vector>
#include <algorithm>
using namespace std;

struct Pt {
  double x, y;
  bool operator==(const Pt &p) const { return x == p.x && y == p.y; 
}
  bool operator<(const Pt &p) const { return x < p.x || (x == p.x 
&& y < p.y); }
};

bool left_turn(Pt p1, Pt p2, Pt p3) {
  return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - 
p1.x) > 0;
}

vector<Pt> convex_hull(vector<Pt> pts) {
  sort(pts.begin(), pts.end());
  vector<Pt> lower;
  vector<Pt> upper;

  pts.erase(unique(pts.begin(), pts.end()), pts.end());

  if (pts.size() <= 2) {
    return pts;
  }

  for (int i = 0; i < pts.size(); ++i) {
    while (lower.size() >= 2 &&
           !left_turn(lower[lower.size() - 2], lower.back(), 
pts[i])) {
      lower.pop_back();
    }
    lower.push_back(pts[i]);
  }

  for (int i = pts.size() - 1; i >= 0; --i) {
    while (upper.size() >= 2 &&
           !left_turn(upper[upper.size() - 2], upper.back(), 
pts[i])) {
      upper.pop_back();
    }
    upper.push_back(pts[i]);
  }

  lower.pop_back();
  upper.pop_back();

  lower.insert(lower.end(), upper.begin(), upper.end());

  return lower;
}
