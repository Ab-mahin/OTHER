// USER: "Ab.Mahin"
// Problem: Lexicographically Maximal Prefix AND
// Contest: CodeChef - START136B
// URL: https://www.codechef.com/START136B/problems/LEXMAX
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

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
        ll n;
        cin >> n;
        ll a[n], mx = 0;
        
        for(ll i = 0; i < n; i++){
        	cin >> a[i];
        	mx = max(mx, a[i]);
        }
        vector<ll> v, ck(n, 0);
        
        for(ll i = 0; i < 31; i++){
        	ll res = 0;
        	for(ll j = 0; j < n; j++){
        		if(!ck[j]){
        			res = max(res, mx & a[j]);
        		}
        	}
        	for(ll j = 0; j < n; j++){
        		if(!ck[j] && (mx & a[j]) == res){
        			v.push_back(res);
        			ck[j] = 1;
        		}
        	}
        	
        	mx = res;
        }
        for(auto i : v) cout << i << ' ';
        for(ll i = 0; i < n; i++){
        	if(!ck[i]) cout << 0 << ' ';
        }
        cout << '\n';
    }
    return 0;
}