#include <algorithm>
using namespace std;

struct Pt
{
    int x, y;
};

int orientation(Pt p1, Pt p2, Pt p3)
{
    int cross = (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
    if (cross == 0) return -1;
    return cross > 0;
}

// Given collinear points a,b,p check if point p is on the line segment ab
bool point_on_seg(Pt a, Pt b, Pt p)
{
    return p.x <= max(a.x, b.x) && p.x >= min(a.x, b.x) &&
           p.y <= max(a.y, b.y) && p.y >= min(a.y, b.y);
}

// Check if the line segments ab and cd intersect
bool do_intersect(Pt a, Pt b, Pt c, Pt d)
{
    int o1 = orientation(a, b, c);
    int o2 = orientation(a, b, d);
    int o3 = orientation(c, d, a);
    int o4 = orientation(c, d, b);

    return ((o1 != o2 && o3 != o4) ||
            (o1 == -1 && point_on_seg(a, b, c)) ||
            (o2 == -1 && point_on_seg(a, b, d)) ||
            (o3 == -1 && point_on_seg(c, d, a)) ||
            (o4 == -1 && point_on_seg(c, d, b)));
}

// Assuming the segments ab and cd are not collinear,
// return their intersection
pair<double,double> find_intersection(Pt a, Pt b, Pt c, Pt d)
{
    double f = (a.x - b.x)*(c.y - d.y) - (a.y - b.y)*(c.x - d.x);
    return { ((a.x*b.y - a.y*b.x)*(c.x - d.x) - (a.x - b.x)*(c.x*d.y - c.y*d.x)) / f,
             ((a.x*b.y - a.y*b.x)*(c.y - d.y) - (a.y - b.y)*(c.x*d.y - c.y*d.x)) / f };
}

