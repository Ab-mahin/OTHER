// USER: "Ab.Mahin"
// Problem: LCM Sum
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/LCMSUM/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007


template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const ll N = 1e6 + 5;
ll phi[N], res[N];

ll call(){
	phi[0] = 0;
	phi[1] = 1;
	
	for(ll i = 2; i < N; i++)  phi[i] = i - 1;
	for(ll i = 2; i < N; i++){
		for(ll j = 2 * i; j < N; j += i){
			phi[j] -= phi[i];
		}
	}
	
	for(ll i = 1; i < N; i++){
		for(ll j = i; j < N; j += i){
			res[j] += (i * phi[i]); 
		}
	}
	
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
	call();
		
    while(t--){
        ll n;
        cin >> n;
        ll ans = (res[n] + 1);
        ans *= n;
        ans /= 2;
                
        cout << ans << '\n';
    }
    
    
    return 0;
}