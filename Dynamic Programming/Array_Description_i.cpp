#include<bits/stdc++.h>
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
    int n,m; cin >> n >> m;
    vector<int>v(n);
    for(auto &x : v) cin >> x;
    
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    if(v[0]==0){
        for(int i=1;i<=m;i++) dp[0][i] = 1;
    } 
    else{
        dp[0][v[0]] = 1;
    }
    for(int i=1;i<n;i++){
        if(v[i]==0){
            for(int j=1;j<=m;j++){
                for(int k=-1;k<=1;k++){
                    if(j+k>=0 && j+k<=m)dp[i][j]= (dp[i][j] + dp[i-1][j+k])%MOD;
                }
            }
        }
        else{
            for(int k=-1;k<=1;k++){
                if(v[i]+k>=0 && v[i]+k<=m)dp[i][v[i]]= (dp[i][v[i]] + dp[i-1][v[i]+k])%MOD;
            }
        }
    }
    cout << accumulate(all(dp[n-1]),0ll)%MOD << endl;
}
