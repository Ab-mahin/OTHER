// USER: "Ab.Mahin"
// Problem: Exact Savings
// Contest: CodeChef - START116
// URL: https://www.codechef.com/problems/EXACTSAVINGS?tab=statement
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

#define MAX (1ll << 60)

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
        ll n, x, z;
        cin >> n >> x >> z;
        ll a[n];
        
        ll r = z % x;
        
        vector<ll> dp(x + 1, MAX), pv(x + 1, MAX);
        
        dp[0] = pv[0] = 0;
        for(ll i = 0; i < n; i++){
        	cin >> a[i];
        	ll d = a[i] % x;
        	for(ll j = 0; j < x; j++){
        		cout << ((j - d + x) % x) << ' ';
        		dp[j] = min(dp[j], pv[(j - d + x) % x] + a[i]);
        	}   
        	cout << '\n';
        	pv = dp;	
        }      
        if(r == 0){
        	cout << (z / x) << '\n';
        	continue;
        }
                  
        if(dp[x - r] >= MAX){
        	cout << -1 << '\n';
        }
        else cout << (z + dp[x - r]) / x << '\n';           
    }
    
    
    return 0;
}