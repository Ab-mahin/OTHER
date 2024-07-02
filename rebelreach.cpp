// USER: "Ab.Mahin"
// Problem: RebelReach
// Contest: HackerEarth - January Circuits '24
// URL: https://www.hackerearth.com/challenges/competitive/january-circuits-24/algorithm/rebelreach-e1a2d3d1/
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
const ll N = 1e6 + 5;
vector<ll> g[N];
ll st[N][21], pr[N],a[N], n, sum[N][21], lev[N];
bitset<N> vis;

void dfs(ll u, ll v, ll c){
	pr[v] = u;
	vis[v] = 1;
	lev[v] = c;
	//cout << u << ' ' << v << '\n';
	for(auto i : g[v]){
		if(!vis[i]){
			dfs(v, i, c + 1);
		}
	}
}

void build(){
	for(ll i = 1; i <= n; i++) st[i][0] = pr[i], sum[i][0] = a[i];
	
	for(ll i = 1; (1ll << i) <= n; i++){
		for(ll j = 1; j + (1ll << i) <= n; j++){
			if(j - (1ll << (i - 1) >= 0)) sum[j][i] = sum[j][i - 1] + sum[j - (1ll << (i - 1))][i - 1];
		}
		for(ll j = 1; j <= n; j++){
			if (st[j][i - 1]){
				st[j][i] = st[st[j][i - 1]][i - 1];
			}
		}
	}	
}
ll f = 0;
ll ck(ll l, ll d){
	if(l == 0 || d < 0) return 0;
	ll lg = log2(d), res  = 0;
	f = st[l][lg];
	cout << l << ' ' << d << ' ' << f << ' ' << sum[l][lg] << '\n';
	return res = sum[l][lg] + ck(f, d - (1ll << lg));
}

ll query(ll i, ll v){
	
	ll lo = 0, hi = lev[i], ans = i;
	//cout << lo << ' ' << hi << '\n';
	while(lo <= hi){
		ll mid = (lo + hi) / 2;
		f = i;
		ll res = ck(i, mid);
		cout << res << ' ' << i << ' ' << mid << '\n';
		if(res < v){
			ans = f;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	return ans;
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
	
    while(t--){
        cin >> n;
        
        for(ll i = 0; i <= n; i++){
        	g[i].clear();
        	vis[i] = 0;
        	lev[i] = 0;
        }
        
        for(ll i = 0; i < n - 1; i++){
        	ll u, v;
        	cin >> u >> v;
        	g[u].push_back(v);
        	g[v].push_back(u);
        }
        
        dfs(0, 1, 1);
        
        for(ll i = 1; i <= n; i++){
        	cin >> a[i];
        }
        
        build();
        
        ll q;
        cin >> q;
        
        /*for(ll i = 1; i <= n; i++){
        	cout << i << ' ';
    		for(ll j = 0; j < n; j++){
    			cout << sum[i][j] << ' ';
    		}
    		cout << '\n';
    	}
    	cout << '\n';*/
        
        while(q--){
        	ll i, v;
        	cin >> i >> v;
        	cout << query(i, v) << '\n';
        }
                
    }
    
    
    return 0;
}