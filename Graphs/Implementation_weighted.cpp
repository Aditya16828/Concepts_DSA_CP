#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

using namespace std;

vector<vector<pair<int, int>>> graph;

void print_graph(){
	for(int i=0;i<graph.size();i++){
		cout<<i<<"->";
		for(auto x:graph[i]){cout<<x.first<<"("<<x.second<<"), ";}
		cout<<"\n";
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
    graph.resize(vertices, vector<pair<int,int>>());
    while(edges--){
    	int u,v,wt;
    	cin>>u>>v>>wt;
    	graph[u].push_back({v, wt});
    	graph[v].push_back({u, wt});
    }
    print_graph();

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}
