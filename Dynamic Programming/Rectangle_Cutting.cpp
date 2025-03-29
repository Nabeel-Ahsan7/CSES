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
    int n,m; cin >> n >>m;
    vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
    //base case
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==j){
                dp[i][j] = 0;
                continue;
            }
            for(int k=1;k<=max(n,m);k++){
               //row
                if(i-k>0&& i-k<=n && k<=n) dp[i][j] = min(dp[i][j],1 + dp[i-k][j] + dp[k][j]);
               //col
                if(j-k>0&&j-k<=m && k<=m) dp[i][j] = min(dp[i][j],1 + dp[i][j-k] + dp[i][k]);
            }
 
        }
    }
    cout << dp[n][m] << endl;
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
