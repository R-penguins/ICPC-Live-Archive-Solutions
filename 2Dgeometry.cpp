#include <bits/stdc++.h>
using namespace std;

struct Vec
{
    double x, y;
    Vec(double x = 0, double y = 0) : x(x), y(y) { }

    double len() const
    {
        return sqrt(x * x + y * y);
    }

    Vec normalize() const
    {
        return Vec(-y / len(), x / len());
    }

    double angle() const
    {
        return atan2(y, x);
    }
};

using Pt = Vec;

struct Line
{
    Pt pt;
    Vec vec;
    Line(Pt pt = 0, Vec vec = 0) : pt(pt), vec(vec) { }
};

struct Seg
{
    Pt a, b;
    Vec ab;
    Seg(Pt a = 0, Pt b = 0) : a(a), b(b)
    {
        ab = b - a;
    }
};

const double EPS = 1e-10;
int dcmp(double x)
{
    return abs(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

bool operator==(const Pt &l, const Pt &r)
{
    return abs(l.x - r.x) <= EPS && abs(l.y - r.y) <= EPS;
}

bool operator<(const Pt &l, const Pt &r)
{
    return l.x < r.x || (l.x == r.x && l.y < r.y);
}

Vec operator-(const Vec &l, const Vec &r)
{
    return Vec(l.x - r.x, l.y - r.y);
}

Vec operator+(const Vec &l, const Vec &r)
{
    return Vec(l.x + r.x, l.y + r.y);
}

Vec operator*(double k, const Vec &vec)
{
    return Vec(k * vec.x, k * vec.y);
}

Vec operator/(const Vec &vec, double k)
{
    return Vec(vec.x / k, vec.y / k);
}

double dot(const Vec &l, const Vec &r)
{
    return l.x * r.x + l.y * r.y;
}

double angle(const Vec &l, const Vec &r)
{
    return acos(dot(l, r) / l.len() / r.len());
}

double cross(const Vec &l, const Vec &r)
{
    return l.x * r.y - l.y * r.x;
}

double area(const Pt &a, const Pt &b, const Pt &c)
{
    return cross(b - a, c - a);
}





// Make sure !pts.empty()
double area(const vector<Pt> &pts)
{
    double ans = 0;
    for (int i = 1; i < pts.size() - 1; ++i)
        ans += cross(pts[i] - pts[0], pts[i + 1] - pts[0]);
    return ans / 2;
}

Vec rotate(const Vec &vec, double a)
{
    return Vec(vec.x * cos(a) - vec.y * sin(a),
               vec.x * sin(a) + vec.y * cos(a));
}

// Make sure cross(vp, vq) != 0
Pt intersect(const Pt &p, const Vec &vp, const Pt &q, const Vec &vq)
{
    return p + cross(vq, p - q) / cross(vp, vq) * vp;
}

double dist(const Pt &p, const Line &line)
{
    return abs(cross(line.vec, p - line.pt)) / line.vec.len();
}

double dist(const Pt &p, const Seg &seg)
{
    if (seg.a == seg.b)
        return (p - seg.a).len();
    Vec ap = p - seg.a, bp = p - seg.b;
    if (dot(seg.ab, ap) < -EPS)
        return ap.len();
    else if (dot(seg.ab, bp) > EPS)
        return bp.len();
    return abs(cross(seg.ab, ap)) / seg.ab.len();
}

Pt projection(const Pt &p, const Line &line)
{
    return line.pt +
        dot(line.vec, p - line.pt) / dot(line.vec, line.vec) * line.vec;
}

bool hasIntersection(const Seg &l, const Seg &r)
{
    double la = cross(l.ab, r.a - l.a), lb = cross(l.ab, r.b - l.a),
           ra = cross(r.ab, l.a - r.a), rb = cross(r.ab, l.b - r.a);
    return dcmp(la) * dcmp(lb) < 0 && dcmp(ra) * dcmp(rb) < 0;
}


bool on(const Pt &p, const Seg &seg)
{
    return dcmp(cross(seg.a - p, seg.b - p)) == 0 &&
           dcmp(dot(seg.a - p, seg.b - p)) < 0;
}
