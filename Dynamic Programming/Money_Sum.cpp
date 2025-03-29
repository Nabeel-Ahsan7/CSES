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
    vector<int>v(n);
    int sum = 0;
    for(auto &x : v) { cin >> x; sum+=x;}
    vector<vector<int>>dp(n+1,vector<int>(sum+1));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            //jodi na nei
            dp[i][j] = dp[i-1][j];
            // jodi nei
            if(j-v[i-1]>=0 && dp[i-1][j-v[i-1]]==1)dp[i][j] = dp[i-1][j-v[i-1]];
        }
    }
    vector<int>ans;
    for(int i=1;i<=sum;i++){
        if(dp[n][i]==1)ans.push_back(i);
    }
    cout << ans.size() << endl;
    print(ans);
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
