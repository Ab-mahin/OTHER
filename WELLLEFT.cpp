// USER: "Ab.Mahin"
// Problem: Amphibian Escape
// Contest: CodeChef - START141B
// URL: https://www.codechef.com/START141B/problems/WELLLEFT
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
//#define m 1000000007 // 998244353
//0x3f

#define MAX LLONG_MAX

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

//find_by_order() and order_of_key()
//k-th largest element and strictly smaller


/* To finding all possible submask for a mask(set bits);
 
for(ll mask = 0; mask < (1 << n); mask++){
    for(ll submask = mask ; submask > 0; submask = (submask - 1) & mask){
    	cout << mask << ' ' << submask << '\n';	
    }
}
*/

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
        ll n, k, h;
        cin >> n >> k >> h;
        ll ans = 0;
        for(ll i = 1; i <= n; i++){
        	ll lo = 1, hi = n, resA = 0, resB = 0, ok = 0, ck = 0;
        	while(lo <= hi){
        		ll mid = (lo + hi) / 2;
        		ll d = (k * i) - (k - 1) * mid;
        		if(d >= h){
        			lo = mid + 1;
        			resA = mid;
        		}else hi = mid - 1;
        	}
        	lo = 1, hi = i - 1;
        	while(lo <= hi){
        		ll mid = (lo + hi) / 2;
        		ll d = (k * i) - (k - 1) * mid;
        		if(d >= h){
        			hi = mid - 1;
        			resB = mid;
        		}else lo = mid + 1;
        	}
        	ll res = resA - resB + ((resA && resB));
        	if(i >= h) res = n, resA = 0, resB = 0;
        	 
        	ans += res;
        }
        cout << ans << '\n'; 
    }
    return 0;
}