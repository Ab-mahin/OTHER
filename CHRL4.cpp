// USER: "Ab.Mahin"
// Problem: Chef and Way
// Contest: CodeChef - LTIME08
// URL: https://www.codechef.com/problems/CHRL4?tab=statement
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
#define m 1000000007 // 998244353
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
    
    //cin >> t;
	
    while(t--){
        ll n, k;
        cin >> n >> k;
        
        double lg[n]{0};
        ll ans[n], a[n];
        memset(ans, -1, sizeof ans);
        
        priority_queue <pair<double, ll>, vector<pair<double, ll>>, greater<pair<double, ll>>> q;
        
        for(ll i = 0; i < n; i++){
        	cin >> a[i];
        }
        
        ans[0] = a[0];
        lg[0] = log10(a[0]);
        
        q.push({lg[0], 0});
                
        ll j = 1;
        while(ans[n - 1] == -1){
        	
        	pair<double, ll> p = q.top();
        	double l = p.first;
        	ll i = p.second;
        	
        	if(j - i > k){
        		q.pop();
        	}
        	else {
        		lg[j] = (l + log10(a[j]));
        		ans[j] = (ans[i] * a[j]) % m;
        		q.push({lg[j], j});
        		j++;
        	}	
        }
        cout << ans[n - 1] << '\n';   
    }
    
    
    return 0;
}