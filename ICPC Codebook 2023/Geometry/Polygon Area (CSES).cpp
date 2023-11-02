/* Your task is to calculate the area of a given polygon.
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
Print one integer: 2a where the area of the polygon is a (
this ensures that the result is an integer).
Constraints
* 3 <= n <= 1000
* -10^9 <= xi,yi <= 10^9
Example Input:
4
1 1
4 2
3 5
1 4
Example Output:
16 */
C++ Solution:
#define int long long
#define X first
#define Y second
signed main() {
  int n;
  cin>>n;
  pair<int,int> a[n];
  for (int i = 0; i < n; i++)
    cin>>a[i].X>>a[i].Y;
  int ans = 0;
//shoelace formula
  for (int i = 0; i < n; i ++) {
    ans += (a[i].X*a[(i+1)%n].Y - a[(i+1)%n].X*a[i].Y);
  }
  cout<<abs(ans);
}
