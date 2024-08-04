// USER: "Ab.Mahin"
// Problem: Square String
// Contest: CodeChef - START145B
// URL: https://www.codechef.com/START145B/problems/SQING
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define m 1000000007 // 998244353
// 0x3f

#define MAX LLONG_MAX

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order() and order_of_key()
// k-th largest element and strictly smaller

// Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 5e5 + 5;

ll bigmod(ll a, ll n){
	ll res = 1;
	while(n){
		if(n & 1) res = (res * a) % m;
		a = (a * a) % m;
		n /= 2;
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;

    cin >> t;
    
    while (t--) {
        ll n;
        cin >> n;
        ll ans = 0, val = 0;
        for(ll i = 1; i <= n; i++){
        	ll x = (val * 2) % m;
        	x = (x + ((i - 1) * (i - 1)) % m) % m;
        	ans = (ans + (bigmod(2, n - i) * x) % m) % m;
        	val = x;
        }
       ans = (ans * 2) % m;
        cout << ans << '\n';
    }
    
    return 0;
}