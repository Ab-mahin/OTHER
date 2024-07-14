// USER: "Ab.Mahin"
// Problem: Perfect Prefixes
// Contest: CodeChef - START141
// URL: https://www.codechef.com/problems/PREPER?tab=statement
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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

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
        ll a[n + 1], b[n + 1], c[n + 1];
        ordered_set<ll> s, d;
        ll ans = 0;
        for(ll i = 1; i <= n; i++){
        	cin >> a[i];
        	s.insert(a[i]);
        	c[i] = a[i];
        	ll x = s.order_of_key(i + 1);
        	b[i] = 0;
        	if(x == i) ans++, b[i] = 1;
        }
        vector<ll> p, q;
        s.clear();
        
        for(ll i = 1; i < n; i++){
        	swap(c[i], c[i + 1]);
        	if(i & 1) s.insert(c[i]);
        	else d.insert(c[i]);
        	ll x = (i & 1 ? s : d).order_of_key(i + 1);
        	if(x == i){
        		(i & 1 ? p : q).push_back(1);
        	}else{
        		if(b[i] == 1) (i & 1 ? p : q).push_back(-1);
        		else (i & 1 ? p : q).push_back(0);
        	}
        	if(i & 1) s.insert(c[i + 1]);
        	else d.insert(c[i + 1]);
        	swap(c[i], c[i + 1]);
        	if(i & 1) d.insert(c[i]);
        }
        ll sum = 0, mx = 0;
        for(ll i = 0; i < p.size(); i++){
        	if(p[i] > sum + p[i]) sum = p[i];
        	else sum += p[i];
        	mx = max(mx, sum);
        }   
        sum = 0;
        for(ll i = 0; i < q.size(); i++){
        	if(q[i] > sum + q[i]) sum = q[i];
        	else sum += q[i];
        	mx = max(mx, sum);
        }        
        
        cout << ans + mx << '\n';     
        
                
    }
    return 0;
}