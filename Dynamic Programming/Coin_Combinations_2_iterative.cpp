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

int32_t main() {
    int n,target; cin >> n >> target; 
    vector<int>coins(n);
    for(auto &x : coins) cin >> x;
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    //base case 
    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }
    //dp[i][k] -> (dp[i][k-Ci] + dp[i+1][k])
    for(int i=n-1;i>=0;i--){
        for(int value = 1;value<=target;value++){
            //skip 
            int res1 = dp[i+1][value];
            int res2 = 0;
            if(coins[i]<=value){
                res2 = dp[i][value-coins[i]];
            }
            dp[i][value] = (res1+res2)%MOD;
        }
    }
    cout << dp[0][target] << endl;
}
