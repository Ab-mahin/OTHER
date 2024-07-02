// USER: "Ab.Mahin"
// Problem: Chef and Queries
// Contest: CodeChef - COOK65
// URL: https://www.codechef.com/problems/CHEFQUE
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
#define m (1ll << 32)
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
const ll N = (1ll << 32) + 5;
bitset<N> mp;
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
        ll q, s, a, b;
        cin >> q >> s >> a >> b;
        ll sum = 0;
        ll x = (s / 2);
        if(s & 1) mp[x] = 1, sum += x;        
        for(ll i = 1; i < q; i++){
        	ll x = ((s * a) + b) % m;
        	ll y = (x / 2);
        	if(x & 1){
        		if(!mp[y]) mp[y] = 1, sum += y;
        	}
        	else{
        		if(mp[y]) mp[y] = 0, sum -= y;
        	}
        	s = x;
        }  
        cout << sum << '\n';                 
    }
    
    
    return 0;
}