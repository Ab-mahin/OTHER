// USER: "Ab.Mahin"
// Problem: Tile Permutation Paradox
// Contest: HackerEarth - January Circuits '24
// URL: https://www.hackerearth.com/challenges/competitive/january-circuits-24/algorithm/tile-permutation-paradox-73323005/
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
#define m 1000000007 // 998244353
//0x3f

#define MAX LLONG_MAX

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//find_by_order() and order_of_key()
//k-th largest element and strictly smaller

//Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cerr.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 1e4 + 5;

ll dp[N];
ll x;
ll solve(ll i){
	if(i < 0) return 0;
	if(i == 0) return 1;
	if(dp[i] != -1) return dp[i];
	ll res = 0;
	res = (res + solve(i - 1)) % m;
	res = (res + solve(i - x)) % m;
	return dp[i] = res;
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
    
	cin >> t;
	
    while(t--){
        ll n;
        cin >> n >> x;
        memset(dp, -1, sizeof dp);
        ll p = (n + x - 1) / x;
        if(n % x == 0) p++;
        ll ans = (m + solve(n) - p) % m;
        cout << ans << '\n';  
    }
    
    
    return 0;
}