#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll mod_exp(ll base, ll exp, ll mod){
	ll res=1;
	while(exp){
		if(exp%2) res = ((res%mod)*(base%mod))%mod;
		base = ((base%mod)*(base%mod))%mod;
		exp>>=1;
	}
	return res;
}

ll crt(vector<ll> &n, vector<ll> &r){
	ll ans=0;
	ll product=1LL;
	vector<ll> z;
	vector<ll> inv;
	for(int i=0;i<n.size();i++)
		product*=n[i];
	for(int i=0;i<n.size();i++){
		z.push_back(product/n[i]);
	}
	for(int i=0;i<z.size();i++){
		inv.push_back(mod_exp(z[i], n[i]-2, n[i]));
	}
	for(int i=0;i<z.size();i++){
		ans = (ans%product) + ((r[i]*z[i])%product * inv[i]%product)%product;
		ans%=product;
	}
	return ans;
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
    
    ll size;
    cin>>size;
    vector<ll> n(size), r(size);
    for(int i=0;i<size;i++) cin>>n[i];
    for(int i=0;i<size;i++) cin>>r[i];
    cout<<crt(n, r)<<"\n";
        
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}
