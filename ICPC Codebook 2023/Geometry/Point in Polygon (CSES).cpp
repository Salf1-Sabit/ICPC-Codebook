/* You are given a polygon of n vertices and a list of m
points. Your task is to determine for each point if it
is inside, outside or on the boundary of the polygon.
The polygon consists of n vertices (x1,y1),(x2,y2),...,(xn,
yn). The vertices (xi,yi) and (xi+1,yi+1) are adjacent
for i=1,2,...,n1, and the vertices (x1,y1) and (xn,yn)
are also adjacent.
Input
The first input line has two integers n and m: the number of
vertices in the polygon and the number of points.
After this, there are n lines that describe the polygon. The
ith such line has two integers xi and yi.
You may assume that the polygon is simple, i.e., it does not
intersect itself.
Finally, there are m lines that describe the points. Each
line has two integers x and y.
Output
For each point, print "INSIDE", "OUTSIDE" or "BOUNDARY".
Constraints
* 3 <= n,m <= 1000
* 1 <= m <= 1000
* -10^9 <= xi,yi <= 10^9
* -10^9 <= x,y <= 10^9
Example Input:
4 3
1 1
4 2
3 5
1 4
2 3
3 1
1 3
Example Output:
INSIDE
OUTSIDE
BOUNDARY */
C++ Solution:
#define int long long
#define P complex<int>
#define X real()
#define Y imag()
const int INF = 1e9 + 7;
int cross(P a, P b, P c) {
  P u = b - a;
  P v = c - a;
  int cp = (conj(u)*v).Y;
  return (cp > 0) - (cp < 0);
}
bool comp(const P &a, const P &b) {
  return (a.X == b.X) ? (a.Y < b.Y) : (a.X < b.X);
}
bool mid(P a, P b, P c) {
  vector<P> v = {a, b, c};
  sort(v.begin(), v.end(), comp);
  return (v[1] == c);
}
bool check(P a, P b, P c, P d) {
  int cp1 = cross(a, b, c);
  int cp2 = cross(a, b, d);
  int cp3 = cross(c, d, a);
  int cp4 = cross(c, d, b);
  if (cp1 * cp2 < 0 && cp3 * cp4 < 0)
    return 1;
  if (cp3 == 0 && mid(c, d, a) && cp4 < 0)
    return 1;
  if (cp4 == 0 && mid(c, d, b) && cp3 < 0)
    return 1;
  return 0;
}
signed main() {
// https://en.wikipedia.org/wiki/Point_in_polygon#
  Ray_casting_algorithm
  int n, m;
  cin >> n >> m;
  vector<P> v;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }
  v.push_back(v[0]);
  while (m--) {
    int x, y;
    cin >> x >> y;
    P a = {x, y};
    P b = {INF, INF};
    int cnt = 0;
    int flag = 0;
    for (int i = 0; i < n; i++) {
      int cp = cross(v[i], v[i+1], a);
      if (cp == 0 && mid(v[i], v[i+1], a)) {
        flag = 1;
        break;
      }
      cnt += check(v[i], v[i+1], a, b);
    }
    if (flag)
      cout << "BOUNDARY" << endl;
    else
      cout << (cnt & 1 ? "INSIDE" : "OUTSIDE") << endl;
  }
}
