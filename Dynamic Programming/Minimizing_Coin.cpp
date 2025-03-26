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



void solve() {
    int n,target; cin >> n >> target; 
    vector<int>coins(n);
    for(auto &x : coins) cin >> x;
    int dp[target+100];
    for(int i=0;i<target+100;i++) dp[i] = INT_MAX;
    dp[0] = 0;
    for(int i=0;i<=target;i++){
        for(auto &c : coins){
            if(i<c) continue;
            dp[i] = min(dp[i],1+dp[i-c]);
        }
    }
    if(dp[target]>=INT_MAX) cout << -1 << endl;
    else cout << dp[target] << endl;
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
