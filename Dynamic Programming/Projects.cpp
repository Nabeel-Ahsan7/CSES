#include<bits/stdc++.h>
#define int long long int
#define yes cout << "YES" << endl
#define show(x) cout << x << endl;
#define no cout << "NO" << endl
#define uint unsigned long long int
#define all(v) v.begin(),v.end()
#define print(v) for(auto x : v) cout << x << " "; cout << endl;
int mypow(int a, int b){ int ans = 1; while(b){ if (b&1) ans = (ans*a); b >>= 1; a = (a*a); } return ans; }
#define init(arr, val) memset(arr, val, sizeof(arr))
using namespace std;
void setIO(){ios_base::sync_with_stdio(false); cin.tie(NULL);}
const int MOD = 1e9+7;
const int inf = 1e9;
 
void solve() {
    int n; cin >> n;
    pair<int,pair<int,int>>v[n];
    for(int i=0;i<n;i++){
        int starting_day,ending_day,reward; cin >> starting_day >> ending_day >> reward;
        v[i] = {starting_day,{ending_day,reward}};
    }
    sort(v,v+n);
    int dp[n+1]={};
    for(int i=n-1;i>=0;i--){
        // Choose
        dp[i] = dp[i+1];
        //Not choose
        int nextValue_ind = upper_bound(v,v+n,make_pair(v[i].second.first,make_pair(inf,inf)))-v;
        dp[i] = max(dp[i],v[i].second.second + dp[nextValue_ind]);
    }
    cout << dp[0] << endl;
}   
 
int32_t main() {
    setIO();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
}
