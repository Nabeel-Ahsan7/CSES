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
    int n; cin >> n;
    int half_of_total = n*(n+1)/4;
    vector<vector<int>>dp(n+1,vector<int>(half_of_total+1));
    //base case
    dp[0][0] = 1; 
    if(half_of_total*2 != (n*(n+1)/2)){
        cout << 0 << endl;
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=half_of_total;j++){
            //na niya
            dp[i][j] = dp[i-1][j];
            if(j-i>=0) dp[i][j] = (dp[i][j] + dp[i-1][j-i])%MOD;
        }
    }
    cout << dp[n-1][half_of_total] << endl;
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
