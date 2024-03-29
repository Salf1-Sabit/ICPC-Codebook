// Johnson Algorithm (graph) all pair shortest path with negative cost.
/// Johnson's algorithm for all pair shortest paths in sparse graphs
/// Complexity: O(N * M) + O(N * M * log(N))

#define MAX 90
#define clr(ar) memset(ar, 0, sizeof(ar))
typedef long long ll;
const ll INF = (1LL << 60) - 666;
struct Edge{ // u to v edge
    int u, v;
    ll w;
    Edge(){}
    Edge(int u, int v, ll w) : u(u), v(v), w(w){}
};
bool bellman_ford(int n, int src, vector <Edge> E, vector <ll>& dis){
    dis[src] = 0;
    for (int i = 0; i <= n; i++){
        int flag = 0;
        for (auto e: E){
            if ((dis[e.u] + e.w) < dis[e.v]){
                flag = 1;
                dis[e.v] = dis[e.u] + e.w;
            }
        }
        if (flag == 0) return true;
    }
    return false;
}
vector <ll> dijkstra(int n, int src, vector <Edge> E, vector <ll> potential){
    set<pair<ll, int> > S;
    vector <ll> dis(n + 1, INF);
    vector <ll> temp(n + 1, INF);
    vector <pair<int, ll> > adj[n + 1];
    dis[src] = temp[src] = 0;
    S.insert(make_pair(temp[src], src));
    for (auto e: E){
        adj[e.u].push_back(make_pair(e.v, e.w));
    }
    int __sigh  = 0;
    while (!S.empty()){
        pair<ll, int> cur = *(S.begin());
        S.erase(cur);
        int u = cur.second;
        for (int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first;
            ll w = adj[u][i].second;
            if ((temp[u] + w) < temp[v]){
                S.erase(make_pair(temp[v], v));
                temp[v] = temp[u] + w;
                dis[v] = dis[u] + w;
                S.insert(make_pair(temp[v], v));
            }
        }
    }
    return dis;
}
void johnson(int n, ll ar[MAX][MAX], vector <Edge> E){
    vector <ll> potential(n + 1, INF);
    for (int i = 1; i <= n; i++) E.push_back(Edge(0, i, 0));

    assert(bellman_ford(n, 0, E, potential));
    for (int i = 1; i <= n; i++) E.pop_back();

    for (int i = 1; i <= n; i++){
        vector <ll> dis = dijkstra(n, i, E, potential);
        for (int j = 1; j <= n; j++){
            ar[i][j] = dis[j];
        }
    }
}
ll ar[MAX][MAX];// output all pair shortest distance
vector <Edge> E; // input graph