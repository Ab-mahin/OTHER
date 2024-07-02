// USER: "Ab.Mahin"
// Problem: GCD Sum
// Contest: HackerEarth - Data Structures - Advanced Data Structures - Fenwick (Binary Indexed) Trees
// URL: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/akash-and-gcd-1-16/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll int
#define m 1000000007
#define lc (n * 2)
#define rc ((n * 2) + 1)



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
const ll N = 5e5 + 5;
ll phi[N], fun[N], a[N];
vector<ll> d[N];
void solve(){
	phi[0] = 0;
	phi[1] = 1;
	for(ll i = 2; i < N; i++) phi[i] = i - 1;
	
	for(ll i = 1; i < N; i++) d[i].push_back(1);
	
	for(ll i = 2; i < N; i++){
		d[i].push_back(i);
		for(ll j = 2 * i; j < N; j += i){
			phi[j] -= phi[i];
			d[j].push_back(i);
		}
	}
	
	for(ll i = 1; i < N; i++){
		for(auto j : d[i]){
			ll x = (i / j);
			fun[i] = (fun[i] + (j * phi[x]) % m) % m;
		}
	}
}

const ll id = 3e6;
struct{
	ll val = 0;
}tr[id];


void pull(ll n){
	tr[n].val = (tr[lc].val  + tr[rc].val) % m;
}

void build(ll n, ll b, ll e){
	if(b == e){
		tr[n].val = fun[a[b]];
		return;
	}
	
	ll mid = (b + e) / 2;
	build(lc, b, mid);
	build(rc, mid + 1, e);
	pull(n);
	
}

void upd(ll n, ll b, ll e, ll i, ll x){
	if (b > i || e < i) return;
	if (b == e && b == i) {
      	tr[n].val = fun[x];
      	return;
    }
    
    ll mid = (b + e) / 2;
    upd(lc, b, mid, i, x);
    upd(rc, mid + 1, e, i, x);
    pull(n);
}


ll query(ll n, ll b, ll e, ll i, ll j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tr[n].val % m;
    ll mid = (b + e) / 2;
    ll L = query(lc, b, mid, i, j) % m;
    ll R = query(rc, mid + 1, e, i, j) % m;
    return (L + R) % m;
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
    
	solve();
	
	
	ll n;
	cin >> n;
		
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	build(1, 0, n - 1);
	
	ll q;
	cin >> q;
	while(q--){
		
		char ch;
		cin >> ch;
		
		ll i, j;
		cin >> i >> j;
		if(ch == 'C'){
			i--, j--;
			cout << query(1, 0, n - 1, i, j) << '\n';
		}
		else{
			i--;
			upd(1, 0, n - 1, i, j);
		}
		
	}
	
    
    return 0;
}