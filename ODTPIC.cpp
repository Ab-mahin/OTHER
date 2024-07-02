// USER: "Ab.Mahin"
// Problem: Odd Topic
// Contest: CodeChef - AABH2020
// URL: https://www.codechef.com/AABH2020/problems/ODTPIC
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007 // 998244353
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
const ll N = 4e3 + 5;
const ll M = 1e5 + 5;

bitset<N> a[M], b[M];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
    
    //cin >> t;
	
    while(t--){
        ll n, m, q;
        cin >> n >> m >> q;
        
        for(ll i = 1; i <= n; i++){
        	ll x;
        	cin >> x;
        	a[i] = a[i - 1];
        	if(a[i - 1][x]) a[i][x] = 0;
        	else a[i][x] = 1; 
        }
        
        for(ll i = 1; i <= m; i++){
        	ll x;
        	cin >> x;
        	b[i] = b[i - 1];
        	if(b[i - 1][x]) b[i][x] = 0;
        	else b[i][x] = 1;
        }
        
        
        while(q--){
        	ll x, y, l, r;
        	cin >> x >> y >> l >> r;
        	x--, l--;
        	
        	bitset<N> ans = a[y] ^ a[x];
        	bitset<N> res = b[r] ^ b[l];
        	
        	ans ^= res;
        	cout << ans.count() << '\n';
        }
                
    }
    
    
    return 0;
}