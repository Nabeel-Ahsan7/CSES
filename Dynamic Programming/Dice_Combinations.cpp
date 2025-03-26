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
const int N = 1e6+10;
int dp[10][N+50]={};
int solve(int val,int sum,int target){
    if(dp[val][sum]!=-1) return dp[val][sum];
    if(sum>target) return dp[val][sum] = 0;
    if(sum==target) return dp[val][sum] = 1;
    int total = 0;
    for(int i=1;i<=6;i++){
        total+= (solve(val,sum+i,target)%MOD);
    }
    return dp[val][sum]=(total%MOD);
}

void solve() {
    int n; cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << solve(0,0,n) << endl;
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
