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
    vector<int>ans;
    ans.push_back(v[0]);
    vector<int>insertInto(n);
    for(int i=1;i<n;i++){
        int ind = lower_bound(all(ans),v[i]) - ans.begin();
        if(ind==ans.size()){
            ans.push_back(v[i]);
            insertInto[i] = ans.size();
        }
        else{
            ans[ind] = v[i];
            int len = ind+1;
            insertInto[i] = len;
        }
    }
    cout << ans.size() << endl;
    // vector<int>printSequence;
    // int curr = ans.size();
    // for(int i=insertInto.size();i>=0;i--){
    //     if(curr==insertInto[i]){
    //         printSequence.push_back(v[i]);
    //         curr--;
    //     }
    // }
    // reverse(all(printSequence));
    // for(auto x : printSequence){
    //     cout << x << " ";
    // }
    // cout << endl;
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
