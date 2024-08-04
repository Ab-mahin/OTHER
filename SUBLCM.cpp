// USER: "Ab.Mahin"
// Problem: T - Subarray LCM
// Contest: Virtual Judge - Long Contest on Number Theory
// URL: https://vjudge.net/contest/641669#problem/T
// Memory Limit: 1024 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll int
//#define m 1000000007 // 998244353
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
const ll N = 1e6 + 5;
ll mp[N], cnt[N];
vector<ll> divs[N];
bitset<N> p;
void fun(){
	for(ll i = 2; i < N; i += 2){
		divs[i].push_back(2);
	}
	for(ll i = 3; i < N; i += 2){
		if(p[i] == false){
			for(ll j = i; j < N; j += i){
				p[j] = 1;
				divs[j].push_back(i);
			}
		}
	}
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
	fun();
    while (t--) {
        ll n;
        cin >> n;
        
        ll a[n + 1], ans = 0;
        memset(mp, -1, sizeof mp);
        for(ll i = 1; i <= n; i++) cin >> a[i];
        for(ll i = 1, l = 0; i <= n; i++){
        	for(ll j = 0; j < divs[a[i]].size(); j++){
        		if(mp[divs[a[i]][j]] != -1){
        			l = max(l, mp[divs[a[i]][j]]);
        		}
        		mp[divs[a[i]][j]] = i;
        	}
        	ans = max(ans, i - l);
        }
        
        if(ans <= 1) ans = -1;
        cout << ans << '\n';
        
    }
    
    return 0;
}