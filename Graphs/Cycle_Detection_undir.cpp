// For Undirected Graph
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

using namespace std;

vector<vector<int>> graph;
int parent = -1;
bool isCyclic(int v, vector<bool> &vis) {
    vis[v] = true;
    for (auto x : graph[v]) {
        if (!vis[x]) return isCyclic(x, vis);
        else if (x == parent) return true;
    }
    return false;
}

int main()
{
    clock_t begin = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertices, edges;
    cin >> vertices >> edges;
    graph.resize(vertices + 1, vector<int>());
    while (edges--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> visited(vertices + 1, false);
    bool flag = false;
    for (int i = 1; i <= vertices; i++) {
        parent = i;
        if (isCyclic(i, visited)) {flag = true; break;}
    }
    flag ? cout << "Yes\n" : cout << "No\n";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}
