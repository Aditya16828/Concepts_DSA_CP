<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

using namespace std;

vector<list<int>> graph;

void print_graph() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << "->";
        for (auto x : graph[i]) {cout << x << ", ";}
        cout << "\n";
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
    cin >> vertices >> edges;
    graph.resize(vertices, list<int>());
    while (edges--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    print_graph();

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}
=======
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

using namespace std;

vector<list<int>> graph;

void print_graph() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << "->";
        for (auto x : graph[i]) {cout << x << ", ";}
        cout << "\n";
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
    cin >> vertices >> edges;
    graph.resize(vertices, list<int>());
    while (edges--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    print_graph();

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
