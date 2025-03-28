#include<bits/stdc++.h>
// #define int long long int
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
const int N = 1e6+5;
int32_t main() {
    int t; cin >> t;
    vector<vector<int>> dp(N+1,vector<int>(2,0));
    while(t--){
        int n; cin >> n;
        dp[n][0] = 1;
        dp[n][1] = 1;
        for(int i=n-1;i>=0;i--){
            dp[i][0] = (2ll*dp[i+1][0]+dp[i+1][1])%MOD;
            dp[i][1] = (4ll*dp[i+1][1]+dp[i+1][0])%MOD;
        }
        cout << (dp[1][0] + dp[1][1])%MOD << endl;
    }
}
