// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

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

void prefix(std::vector<int> &v){
	int n = v.size();
	for(int i=1;i<n;i++){
		v[i] += v[i-1];
	}
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

	int n, m;
	std::cin>>n>>m;
	std::vector<int> box(n, 0);
	while(m--){
		int l, r;
		std::cin>>l>>r;
		l--;
		r--;
		box[l] += 1;
		if(r == n-1) continue;
		box[r+1] -= 1;
	}
	prefix(box);
	std::vector<int> frq(1000005, 0);
	int max = 0;
	for(int i=0;i<n;i++){
		++frq[box[i]];
		max = std::max(max, box[i]);
	}
	for(int i=max+2; i>=1;i--){
		frq[i-1] += frq[i];
	}
	int q;
	std::cin>>q;
	while(q--){
		int x;
		std::cin>>x;
		std::cout<<frq[x]<<"\n";
	}

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}
