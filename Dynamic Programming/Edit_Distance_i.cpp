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
const int N = 1e6+5;
int32_t main() {
    string s1,s2; cin >> s1 >> s2;
    int n = s1.size();
    int m  = s2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
    //base case
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char first_string_char = s1[i-1];
            char second_string_char = s2[j-1];
            if(first_string_char == second_string_char){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
            dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
        }
    }
    cout << dp[n][m] << endl;
}
