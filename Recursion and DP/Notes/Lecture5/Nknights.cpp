<<<<<<< HEAD
// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define nl				"\n"
#define pb 				push_back
#define eb				emplace_back
#define vi              std::vector<ll>
#define vs				std::vector<std::string>
#define pii             std::pair<ll,ll>
#define ump				std::unordered_map
#define mp 				std::make_pair
#define pq_max          std::priority_queue<ll>
#define pq_min          std::priority_queue<ll,vi,std::greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(std::string str,char ch) {std::istringstream var((str)); vs v; std::string t; while(std::getline((var), t, (ch))) {v.pb(t);} return v;}


void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<std::string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void display(std::vector<std::vector<bool > > &board) {
    for(auto &row : board) {
        for(int i = 0 ; i <row.size(); i++) {
            bool el = row[i];
            if(!el) {
                std::cout<<".";
            } else {
                std::cout<<"K";
            }
        }
        std::cout<<"\n";
    }
    std::cout<<"---------------------------\n";
}

bool isValidPos(int row, int col, int n) {
    return row >= 0 and col >= 0 and row < n and col < n;
}

bool isSafe(std::vector<std::vector<bool> > &board, int n, int row, int col) {
    if(isValidPos(row-2, col-1, n) && board[row-2][col-1]) {
        return false;
    }
    if(isValidPos(row-2, col+1, n) && board[row-2][col+1]) {
        return false;
    }
    if(isValidPos(row-1, col-2, n) && board[row-1][col-2]) {
        return false;
    }
    if(isValidPos(row-1, col+2, n) && board[row-1][col+2]) {
        return false;
    }
    return true;
}

int ways = 0;

void nknights(int sr, int sc, int placed, int n, std::vector<std::vector<bool> > &board) {
    if(placed == n) {
        display(board);
        ways++;
        return;
    }

    for(int row = sr; row < n; row++) {
        for(int col = ((row == sr) ? sc : 0); col < n; col++ ) {
            if(not board[row][col] and isSafe(board, n, row, col)) {
                board[row][col] = true;
                nknights(row, col+1, placed+1, n, board);
                board[row][col] = false;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n;
    std::cin>>n;
    std::vector<std::vector<bool> > board(n, std::vector<bool> (n, false));
    nknights(0, 0, 0, n, board);
    std::cout<<ways<<"\n";
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
=======
// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define nl				"\n"
#define pb 				push_back
#define eb				emplace_back
#define vi              std::vector<ll>
#define vs				std::vector<std::string>
#define pii             std::pair<ll,ll>
#define ump				std::unordered_map
#define mp 				std::make_pair
#define pq_max          std::priority_queue<ll>
#define pq_min          std::priority_queue<ll,vi,std::greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(std::string str,char ch) {std::istringstream var((str)); vs v; std::string t; while(std::getline((var), t, (ch))) {v.pb(t);} return v;}


void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<std::string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void display(std::vector<std::vector<bool > > &board) {
    for(auto &row : board) {
        for(int i = 0 ; i <row.size(); i++) {
            bool el = row[i];
            if(!el) {
                std::cout<<".";
            } else {
                std::cout<<"K";
            }
        }
        std::cout<<"\n";
    }
    std::cout<<"---------------------------\n";
}

bool isValidPos(int row, int col, int n) {
    return row >= 0 and col >= 0 and row < n and col < n;
}

bool isSafe(std::vector<std::vector<bool> > &board, int n, int row, int col) {
    if(isValidPos(row-2, col-1, n) && board[row-2][col-1]) {
        return false;
    }
    if(isValidPos(row-2, col+1, n) && board[row-2][col+1]) {
        return false;
    }
    if(isValidPos(row-1, col-2, n) && board[row-1][col-2]) {
        return false;
    }
    if(isValidPos(row-1, col+2, n) && board[row-1][col+2]) {
        return false;
    }
    return true;
}

int ways = 0;

void nknights(int sr, int sc, int placed, int n, std::vector<std::vector<bool> > &board) {
    if(placed == n) {
        display(board);
        ways++;
        return;
    }

    for(int row = sr; row < n; row++) {
        for(int col = ((row == sr) ? sc : 0); col < n; col++ ) {
            if(not board[row][col] and isSafe(board, n, row, col)) {
                board[row][col] = true;
                nknights(row, col+1, placed+1, n, board);
                board[row][col] = false;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n;
    std::cin>>n;
    std::vector<std::vector<bool> > board(n, std::vector<bool> (n, false));
    nknights(0, 0, 0, n, board);
    std::cout<<ways<<"\n";
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}