// USER: "Ab.Mahin"
// Problem: Expected GCD
// Contest: CodeChef - SEPT19
// URL: https://www.codechef.com/problems/EXPGCD?tab=statement
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define m 1000000007


template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cout.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 2e5 + 5;
ll ans[N], fac[N], ifac[N], phi[N], k;
vector<ll> d[N];

ll bigmod(ll b, ll p){
	if(p == 0) return 1;
	if(p & 1) return (b * bigmod(b, p - 1) % m);
	ll x = bigmod(b, p / 2);
	return (x * x) % m;
}

ll ncr(ll n, ll r){
	if(n < r) return 0;
	return (fac[n] * ifac[r] % m * ifac[n - r] % m);
}


void solve(){
		
	fac[0] = fac[1] = ifac[1] = ifac[0] = 1;
	for(ll i = 1; i < N; i++) phi[i] = i;
	for(ll i = 1; i < N; i++){
		fac[i] = (fac[i - 1] * i) % m;
		ifac[i] = bigmod(fac[i], m - 2) % m;
		for(ll j = i * 2; j < N; j += i){
			d[j].push_back(i);
			phi[j] -= phi[i];
		}
	}
	ll sum = 0;
	phi[1] = 1;
	for(ll i = 1; i < N; i++){
		for(auto j : d[i]){
			ll x = (i / j);
			sum = (sum + ncr(x - 1, k - 1) * phi[j] % m) % m;
		}
		ll val = ncr(i, k);
		ans[i] = (sum * bigmod(val, m - 2)) % m;
	}
	
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
    
    cin >> t >> k;
	solve();
    while(t--){
        ll n;
        cin >> n;
        cout << ans[n] << '\n';
    }
    
    
    return 0;
}