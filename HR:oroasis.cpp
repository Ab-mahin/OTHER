// USER: "Ab.Mahin"
// Problem: OrOasis
// Contest: HackerEarth - January Circuits '24
// URL: https://www.hackerearth.com/challenges/competitive/january-circuits-24/algorithm/oroasis-7e736f17/
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll int
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
const int N = 1e6 + 5;
int idx[N][31];
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
        cin >> n;
        
        ll ans = n, a[n + 1], x = 0;
        ll cnt[31]{0};  
        
        for(ll i = 0; i <= 30; i++) idx[0][i] = 0;
        
        for(ll i = 1; i <= n; i++){
        	cin >> a[i];
        	x |= a[i];
        	for(ll j = 0; j <= 30; j++){
        		idx[i][j] = 0;
        		idx[i][j] = idx[i - 1][j];
        		if(a[i] & (1ll << j)){
        			cnt[j]++;
        			idx[i][j] += 1;
        		}
        	}
        }
                
        auto fun = [&](ll i){
        	ll lo = 1, hi = n - 1, res = n + 1;
	        while(lo <= hi){
	        	ll mid = (lo + hi) / 2, f = 0;
	        	ll l = i;
	        	ll r = min(l + mid - 1, n);
	        	ll y = 0;
	        	
	        	for(ll j = 0; j <= 30; j++){
	        		ll c = idx[r][j] - idx[l - 1][j];
	        		if(c) y |= (1ll << j);
	        	}
	        	if(x == y) f = 1;
	        	if(f){
	        		res = mid;
	        		hi = mid - 1;
	        	}
	        	else lo = mid + 1;
	        }
	        return res;
        };
        
        ll res = 0;
        ll mp[n + 5]{0};
        for(ll i = 1; i <= n; i++){
        	ll xx = fun(i);
        	if(xx <= ans){
        		ll y = 0, p = x;
        		
        		for(ll j = 0; j <= 30; j++){
	        		ll c = idx[i + xx - 1][j] - idx[i - 1][j];
	        		if(c) y |= (1ll << j);
	        		if(cnt[j] && c == cnt[j]) p ^= (1ll << j);
	        	}
		    	if(y == p) mp[xx]++,ans = min(ans, xx);
        	}
        }
        
        if(mp[ans] == 0){
        	cout << -1 << '\n';
        	continue;
        }
    	cout << ans << ' ' << mp[ans] << '\n';
    	
    }
    
    
    return 0;
}