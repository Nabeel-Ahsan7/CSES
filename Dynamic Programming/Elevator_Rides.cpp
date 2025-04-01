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
const int inf = 1e9;
 
void solve() {
    int n,weight; cin >> n >> weight;
    vector<int>v(n);
    for(auto &x : v) cin >> x;
    pair<int,int> dp[(1<<n)];
    for(int i=0;i<(1<<n);i++) dp[i] = make_pair(inf,inf);
    // base case
    dp[0] = {1,0};
    //here dp[all possible combination with bit masking] = {ride need, last ride space taken}
    for(int i=1;i<=(1<<n)-1;i++){
        for(int bit=0;bit<n;bit++){
            if((1<<bit)&i){
                // if this bit flipped 001011 -> 000011
                int remain_bit = i ^ (1<<bit);
                int adding_weight = dp[remain_bit].second + v[bit];
                if(adding_weight<=weight){
                    dp[i] = min(dp[i],make_pair(dp[remain_bit].first,adding_weight));
                }
                else{
                    dp[i] = min(dp[i],make_pair(dp[remain_bit].first+1,v[bit]));
                }
            }
        }
    }
    cout << dp[(1<<n)-1].first << endl;
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
