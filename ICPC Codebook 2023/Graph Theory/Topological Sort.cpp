/* A topological sort of a directed acyclic graph is a
linear ordering of its vertices such that for every
directed edge (u -> v) from vertex (u) to vertex (v), (
u) comes before (v) in the ordering.
This code includes:
1. Topological ordering of a Directed Acyclic Graph (DAG)
2. How to check if a topological ordering is valid or not
*/

#define pb push_back
int N; // Number of nodes
// Assume that this graph is a DAG
vector<int> graph[100000], top_sort;
bool visited[100000];
void dfs(int node) {
  for (int i : graph[node]) {
    if (!visited[i]) {
      visited[i] = true;
      dfs(i);
    }
  }
  top_sort.pb(node);
}
void compute() {
  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      visited[i] = true;
      dfs(i);
    }
  }
  reverse(begin(top_sort), end(top_sort));
// The vector ‘top_sort‘ is now topologically sorted
}
int main() {
  int M;
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a - 1].pb(b - 1);
  }
  compute();
  vector<int> ind(N);
  for (int i = 0; i < N; i++)
    ind[top_sort[i]] = i;
  for (int i = 0; i < N; i++) {
    for (int j : graph[i])
      if (ind[j] <= ind[i]) {
        cout << "IMPOSSIBLE\n"; // topological sort wasn’t
        valid
        exit(0);
      }
  }
  for (int i : top_sort)
    cout << i + 1 << " ";
  cout << "\n";
}
