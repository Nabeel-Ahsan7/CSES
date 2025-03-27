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

int32_t main() {
    int n; cin >> n;
    vector<string>v(n);
    for(auto &x : v) cin >> x;
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    if(v[0][0]!='*')dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int val1 = 0;
            int val2 = 0;
            if(i-1>=0 && v[i-1][j]!='*'){
                val1 =  dp[i-1][j]; 
            }
            if(j-1>=0 && v[i][j-1]!='*'){
                val2 = dp[i][j-1];
            }
            if(v[i][j]!='*') dp[i][j] = max(dp[i][j],(val1 + val2)%MOD);
        }
    }
    cout << dp[n-1][n-1]%MOD << endl;
}
