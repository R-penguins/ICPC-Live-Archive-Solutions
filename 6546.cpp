/**
 * Cut the Cake
 * 2013 Mid-Atlantic
 */
#include <bits/stdc++.h>
using namespace std;
struct Pt
{
  double x, y;
  Pt(double x = 0, double y = 0) : x(x), y(y) { }
};
istream &operator>>(istream &is, Pt &pt)
{
  is >> pt.x >> pt.y;
  return is;
}
using Vec = Pt;
Vec operator-(Vec A, Vec B) {return Vec(A.x-B.x, A.y-B.y);}
Vec operator+(Vec A, Vec B) {return Vec(A.x+B.x, A.y+B.y);}
Vec operator*(Vec A, double p) {return Vec(A.x*p, A.y*p);}
double Dot(Vec A, Vec B) {return A.x*B.x + A.y*B.y;}
double Length(Vec A) {return sqrt(Dot(A, A));}
double Cross(Vec A, Vec B) {return A.x*B.y - A.y*B.x;}

Pt GetIntersect (Pt P, Vec v, Pt Q, Vec w) {
  Vec u = P - Q;
  double t = Cross(w, u) / Cross(v, w);
  return P+v*t;
}

double DistToLine (Pt P, Pt A, Pt B) {
  Vec v1 = B - A, v2 = P - A;
  return fabs(Cross(v1, v2)) / Length(v1);
}
struct Line
{
  Pt pt;
  Vec vec;
  Line(Pt pt, Vec vec) : pt(pt), vec(vec) { }
};
int main()
{
  double r;
  int n;
  Pt O;
  while ((cin >> r >> O >> n) && (r || O.x || O.y || n))
  {
    int ans = 1;
    vector<Line> lines;
    while (n--)
    {
      Pt ptA, ptB;
      cin >> ptA >> ptB;
      if (DistToLine(O, ptA, ptB) >= r)
        continue;
      else
      {
        ans += 1;
        for (Line &l : lines)
        {
          Vec diff = ptB - ptA;
          if (Cross(l.vec, diff) == 0)
            continue;
          Pt inter = GetIntersect(l.pt, l.vec, ptA, diff);
          if ((inter.x - O.x)*(inter.x - O.x) + (inter.y - O.y)*(inter.y - O.y) > r*r)
            continue;
          ans += 1;
        }
        lines.push_back(Line(ptA, ptB - ptA));
      }
    }
    cout << ans << "\n";
  }

}
