// USER: "Ab.Mahin"
// Problem: D - Brackets Sequence
// Contest: Virtual Judge - DP-1
// URL: https://vjudge.net/contest/623036#problem/D
// Memory Limit: 64 MB
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
const ll N = 1e2 + 5;
ll dp[N][N], n, path[N][N];
string s;
ll a[N];
ll solve(ll i, ll j){
	//bug(i, j);
	if(i > j) return 0;
	if(i == j) return 1;
	ll &res = dp[i][j];
	if(~res) return res;
	res = N * N;
	for(ll k = i; k <= j; k++){
		if(s[i] == '(' && s[k] == ')' || s[i] == '[' && s[k] == ']'){
			ll val = solve(i + 1, k - 1) + solve(k + 1, j);
			if(val < res){
				path[i][j] = k;
				res = val;
			}
		}
		ll val = solve(i, k) + solve(k + 1, j);
		if(val < res){
			path[i][j] = k;
			res = val;	
		}
	}
	return res;
}

void print(ll i , ll j){
	if(i > j) return;
	if(i == j){
		cout << ((s[i] == '(' || s[i] == ')') ? "()" : "[]");
		return;
	}
	ll k = path[i][j];
	
	if(s[i] == '(' && s[k] == ')'){
		cout << "(";
		print(i + 1, k - 1);
		cout << ")";
		print(k + 1, j);
	}
	else if(s[i] == '[' && s[k] == ']'){
		cout << "[";
		print(i + 1, k - 1);
		cout << "]";
		print(k + 1, j);
	}
	else {
		print(i, k);
		print(k + 1, j);
	}
	return;
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
    
    //cin >> t;
	
    while(t--){
        string ans;
        cin >> s;
        n = s.size();
        memset(dp, -1, sizeof dp);
       
        solve(0, n - 1);
        print(0, n - 1);
        
    }
    
    
    return 0;
}