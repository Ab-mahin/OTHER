// USER: "Ab.Mahin"
// Problem: Chef and Gcd Queries
// Contest: CodeChef - MARCH18
// URL: https://www.codechef.com/problems/GCDCNT?tab=statement
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
ll spf[N];
void solve(){
	for(ll i = 1; i < N; i++) spf[i] = i;
	for(ll i = 2; i < N; i++){
		for(ll j = i; j < N; j += i){
			spf[j] = min(spf[j], i);
		}
	}
}

ll fun(ll n){
	return (n * (n - 1)) / 2;
}
ordered_set<ll> od[N];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    
    ll n;
    cin >> n;
    
    ll a[n + 1];
    solve();
    for(ll i = 1; i <= n; i++){
    	cin >> a[i];
    	
    	vector<pair<ll, ll>> v;
    	v.push_back({1, -1});
    	ll x = a[i];
    	set<ll> pr;
    	while(x != 1){
    		if(x != 1) pr.insert(spf[x]);
    		x /= spf[x];
    	}
    	
    	for(auto it = pr.begin(); it != pr.end(); it++){
    		x = v.size();
    		for(ll j = 0; j < x; j++){
    			v.push_back({v[j].first * (*it), -1 * v[j].second});
    		}
    	}
    	
    	for(auto j : v){
    		if(j.first != 1) od[j.first].insert(i);
    	}
    	
    }
	ll q;
	cin >> q;
	
	while(q--){
		ll op, l, r;
		cin >> op >> l >> r;
		if(op & 1){
			ll x = a[l];
			
			vector<pair<ll, ll>> v;
	    	v.push_back({1, -1});
	    	set<ll> pr;
	    	while(x != 1){
	    		if(x != 1) pr.insert(spf[x]);
	    		x /= spf[x];
	    	}
	    	
	    	for(auto it = pr.begin(); it != pr.end(); it++){
	    		x = v.size();
	    		for(ll j = 0; j < x; j++){
	    			v.push_back({v[j].first * (*it), -1 * v[j].second});
	    		}
	    	}
	    			    	
	    	for(auto j : v){
	    		if(od[j.first].order_of_key(l) != od[j.first].size()) od[j.first].erase(od[j.first].find_by_order(od[j.first].order_of_key(l)));
	    	}
	    	v.clear();
			a[l] = r;
			x = a[l];
			v.push_back({1, -1});
			pr.clear();
	    	while(x != 1){
	    		if(x != 1) pr.insert(spf[x]);
	    		x /= spf[x];
	    	}
	    	
	    	for(auto it = pr.begin(); it != pr.end(); it++){
	    		x = v.size();
	    		for(ll j = 0; j < x; j++){
	    			v.push_back({v[j].first * (*it), -1 * v[j].second});
	    		}
	    	}
	    			    	
	    	for(auto j : v){
	    		if(j.first != 1) od[j.first].insert(l);
	    	}
		}
		else{
			ll g;
			cin >> g;
			
			ll x = g;
			vector<pair<ll, ll>> v;
	    	v.push_back({1, -1});
	    	set<ll> pr;
	    	while(x != 1){
	    		if(x != 1) pr.insert(spf[x]);
	    		x /= spf[x];
	    	}
	    	
	    	ll ans = r - l + 1;
	    	for(auto it = pr.begin(); it != pr.end(); it++){
	    		x = v.size();
	    		for(ll j = 0; j < x; j++){
	    			ll ck = -1 * v[j].second;
	    			ll d = v[j].first * (*it);
	    			v.push_back({v[j].first * (*it), -1 * v[j].second});
	    			ll cnt = od[d].order_of_key(r + 1) - od[d].order_of_key(l);	    			
	    			//cout << od[d].order_of_key(r + 1)  << ' ' << od[d].order_of_key(l) << ' ' << cnt << ' ' << ans << '\n';
	    			ans += (ck * (-1) * cnt);
	    		}
	    	}
	    	cout << ans << '\n';		
		}
    }
    
    return 0;
}