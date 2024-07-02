// USER: "Ab.Mahin"
// Problem: Box and Ball System
// Contest: CodeChef - FEB12
// URL: https://www.codechef.com/problems/BBSYSTEM
// Memory Limit: 256 MB
// Time Limit: 500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define m 500009 


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
const ll N = 2229283;
ll fac[N], ans[N], d[N], cnt[N];
void solve(){
	ans[0] = 1;
	for(ll i = 1; i < N; i++){
		for(ll j = i; j < N; j += i){
			d[j]++;
		}
		cnt[d[i]]++;
		ans[i] = (ans[i - 1] * cnt[d[i]]) % m;
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
	solve();
    while(t--){
        ll n;
        cin >> n;
        
        if(n > N){
        	cout << m - 1 << '\n';
        	continue;
        }
        
        cout << (ans[n] - 1 + m) % m << '\n';
    }
    
    
    return 0;
}