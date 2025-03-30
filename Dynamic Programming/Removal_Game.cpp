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
    for(auto &x : v) cin >> x;
    vector<vector<int>>dp(n,vector<int>(n,0));
    //Base Case
    for(int i=0;i<n;i++){
        dp[i][i] = v[i];
    }
    for(int len = 2;len<=n;len++){
        for(int i=0;len+i-1<n;i++){
            int j = i+len-1;
            int left = v[i];
            int right = v[j];
            //left
            if(i+2<=j) left = v[i] + min(dp[i+1][j-1],dp[i+2][j]);
            if(j-2>=i) right = v[j] + min(dp[i+1][j-1],dp[i][j-2]);
            dp[i][j] = max(right,left);
        }
    }
    cout << dp[0][n-1] << endl;
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
