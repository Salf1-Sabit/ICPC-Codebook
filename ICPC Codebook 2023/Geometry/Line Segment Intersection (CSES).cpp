/* There are two line segments: the first goes through the
points (x1,y1) and (x2,y2), and the second goes through
the points (x3,y3) and (x4,y4).
Your task is to determine if the line segments intersect, i.
e., they have at least one common point.
Input
The first input line has an integer t: the number of tests.
After this, there are t lines that describe the tests. Each
line has eight integers x1, y1, x2, y2, x3, y3, x4 and
y4.
Output
For each test, print "YES" if the line segments intersect
and "NO" otherwise.
Constraints
* 1 <= t <= 10^5
* -10^9 <= x1,y1,x2,y2,x3,y3,x4,y4 <= 10^9
* (x1,y1) != (x2,y2)
* (x3,y3) != (x4,y4)
Example Input:
5
1 1 5 3 1 2 4 3
1 1 5 3 1 1 4 3
1 1 5 3 2 3 4 1
1 1 5 3 2 4 4 1
1 1 5 3 3 2 7 4
Example Output:
NO
YES
YES
YES
YES */
C++ Solution:
#define int long long
#define P complex<int>
#define X real()
#define Y imag()
int cross(P a, P b, P c) {
  P u = b - a;
  P v = c - a;
  return (conj(u)*v).Y;
}
bool comp(const P &a, const P &b) {
  return (a.X == b.X) ? (a.Y < b.Y) : (a.X < b.X);
}
bool mid(P a, P b, P c) {
  vector<P> v = {a, b, c};
  sort(v.begin(), v.end(), comp);
  return (v[1] == c);
}
int sgn(int x) {
  return (x > 0) - (x < 0);
}
bool check(P a, P b, P c, P d) {
  int cp1 = cross(a, b, c);
  int cp2 = cross(a, b, d);
  int cp3 = cross(c, d, a);
  int cp4 = cross(c, d, b);
  if (cp1 == 0 && mid(a, b, c))
    return 1;
  if (cp2 == 0 && mid(a, b, d))
    return 1;
  if (cp3 == 0 && mid(c, d, a))
    return 1;
  if (cp4 == 0 && mid(c, d, b))
    return 1;
  if (sgn(cp1) != sgn(cp2) && sgn(cp3) != sgn(cp4))
    return
      1;
  return 0;
}
signed main() {
  int t;
  cin>>t;
  while (t--) {
    int x, y;
    P a, b, c, d;
    cin >> x >> y;
    a = {x, y};
    cin >> x >> y;
    b = {x, y};
    cin >> x >> y;
    c = {x, y};
    cin >> x >> y;
    d = {x, y};
    cout << (check(a, b, c, d) ? "YES" : "NO") << endl;
  }
}
