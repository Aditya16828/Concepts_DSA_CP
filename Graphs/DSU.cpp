#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define vec std::vector
#define vll std::vector<long long int>
#define vi std::vector<int>
#define vb std::vector<bool>
#define pii std::pair<int, int>
#define pllll std::pair<long long int, long long int>
#define loop(i, a, b) for(int i=a;i<=b;i++)
#define rloop(i, a, b) for(int i=a;i>=b;i--)
#define iter_all(el, cont) for(auto &el:cont)

void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
	std::cout << *it << " = " << a << std::endl;
	err(++it, args...);
}

void file_i_o() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int Get(int el, std::vector<int> &parent){
	if(parent[el] == el) return el;
	return parent[el] = Get(parent[el], parent);
}

void Union(int el1, int el2, std::vector<int> &rank, std::vector<int> &parent){
	el1 = Get(el1, parent);
	el2 = Get(el2, parent);

	if(rank[el1] == rank[el2]){
		parent[el2] = el1;
		rank[el1]++;
	} else if(rank[el1] < rank[el2]){
		parent[el1] = el2;
	} else {
		parent[el2] = el1;
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin>>n;
	vi parent(n), rank(n);
	loop(i, 0, n-1) parent[i] = i;
	
	int q;
	std::cin>>q;
	while(q--){
		std::string str;
		std::cin>>str;

		int a, b;
		if(str == "union"){
			std::cin>>a>>b;
			Union(a, b, rank, parent);
		} else if(str == "get"){
			std::cin>>a;
			std::cout<<Get(a, parent)<<"\n";
		}
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}