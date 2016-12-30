/** Area of Triangle  , Area of convex Polygon , Cross Product  **/



struct Point {
  Int x, y;

  bool operator <(const Point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};


double triangle_area(point p1, point p2, point p3) {
    return 0.5*abs((p2.first - p1.first)*(p3.second - p1.second) - (p2.second - p1.second)*(p3.first - p1.first));
}



double  area(vector<Point>& p  ) {

    double  ans = 0;

    for (size_t i = 0; i < p.size(); i++) {
      ans += p[i].x * p[(i+1) % 4].y;
      ans -= p[(i+1) % 4].x * p[i].y;
    }

    return 0.5*abs(ans);
  }


long long cross(const Point &O, const Point &A, const Point &B)
{
  return (A.x - O.x) *1LL* (B.y - O.y) - (A.y - O.y) * 1LL* (B.x - O.x);
}
