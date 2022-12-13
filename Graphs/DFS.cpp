#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

using namespace std;

vector<vector<int>> graph;
void dfs(int u, vector<bool> &vis){
	vis[u] = true;
	cout<<u<<" ";
	for(auto x:graph[u]){
		if(!vis[x]) dfs(x, vis);
	}
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
	cin>>vertices>>edges;
	graph.resize(vertices, vector<int>());
	while(edges--){
		int u, v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<bool> visited(vertices, false);
	dfs(0, visited);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}
