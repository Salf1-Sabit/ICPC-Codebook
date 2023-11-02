/* Given a polygon, your task is to calculate the number of
lattice points inside the polygon and on its boundary.
A lattice point is a point whose coordinates are
integers.
The polygon consists of n vertices (x1,y1),(x2,y2),...,(xn,
yn). The vertices (xi,yi) and (xi+1,yi+1) are adjacent
for i=1,2,...,n1, and the vertices (x1,y1) and (xn,yn)
are also adjacent.
Input
The first input line has an integer n: the number of
vertices.
After this, there are n lines that describe the vertices.
The ith such line has two integers xi and yi.
You may assume that the polygon is simple, i.e., it does not
intersect itself.
Output
Print two integers: the number of lattice points inside the
polygon and on its boundary.
Constraints
* 3 <= n <= 10^5
* -10^6 <= xi,yi <= 10^6
Example Input:
4
1 1
5 3
3 5
1 4
Example Output:
6 8 */
C++ Solution:
#define int long long
#define P complex<int>
#define X real()
#define Y imag()
signed main() {
// pick’s theorem + https://math.stackexchange.com/a/301895/530789
  int n;
  cin >> n;
  vector<P> v(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[i] = {x, y};
  }
  v.push_back(v[0]);
  int area = 0;
  int b = 0;
  for (int i = 0; i < n; i++) {
    P x = v[i], y = v[i+1];
    area += (conj(x) * y).Y;
    P z = y - x;
    int g = __gcd(z.X, z.Y);
    b += abs(g);
  }
// 2*area = 2*a + b - 2
  int a = abs(area) - b + 2;
  cout << a/2 << ’ ’ << b;
}
