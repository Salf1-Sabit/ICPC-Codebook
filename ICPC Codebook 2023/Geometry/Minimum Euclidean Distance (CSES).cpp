/* Given a set of points in the two-dimensional plane, your
task is to find the minimum Euclidean distance between
two distinct points.
The Euclidean distance of points (x1,y1) and (x2,y2) is sqrt
((x1-x2)^2 + (y1-y2)^2).
Input
The first input line has an integer n: the number of points.
After this, there are n lines that describe the points. Each
line has two integers x and y. You may assume that
each point is distinct.
Output
Print one integer: d^2 where d is the minimum Euclidean
distance (this ensures that the result is an integer).
Constraints
* 2 <= n <= 2*10^5
* -10^9 <= x,y <= 10^9
Example Input:
4
2 1
4 4
1 2
6 3
Example Output:
2 */
C++ Solution:
#define int long long
#define P pair<int, int>
#define X first
#define Y second
int norm(P a, P b) {
return (b.X - a.X) * (b.X - a.X) + (b.Y - a.Y) * (b.Y - a.
Y);
}
signed main(){
int n; cin>>n;
vector<P> v(n);
int d = LLONG_MAX;
for (int i = 0; i < n; i++) {
int x, y; cin >> x >> y;
v[i] = {x, y};
}
sort(v.begin(), v.end());
set<P> s = {{v[0].Y, v[0].X}};
int j = 0;
for (int i = 1; i < n; i++) {
auto it = s.begin();
int dd = ceil(sqrt(d));
while (j < i && v[j].X < v[i].X - dd) {
s.erase({v[j].Y, v[j].X});
j++;
}
auto l = s.lower_bound({v[i].Y - dd, 0});
auto r = s.upper_bound({v[i].Y + dd, 0});
for (auto it = l; it != r; it++) {
d = min(d, norm({it->Y, it->X}, v[i]));
}
s.insert({v[i].Y, v[i].X});
}
cout << d;
}