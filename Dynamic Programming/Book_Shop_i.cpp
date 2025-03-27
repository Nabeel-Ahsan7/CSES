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
    int number_of_book , budget ; cin >> number_of_book >> budget ;
    vector<int>prices(number_of_book);
    vector<int>pages(number_of_book);
    for(auto &x : prices) cin >> x;
    for(auto &x : pages) cin >> x;
    vector<vector<int>>dp(number_of_book+1,vector<int>(budget+1));
    for(int bd = 0; bd<=budget;bd++){
        dp[0][bd] = 0;
    }
    for(int i=1;i<=number_of_book;i++){
        int number_of_pages=pages[i-1];
        int price = prices[i-1];
        for(int taka = 0;taka <= budget;taka++){
            int mx_page = 0;
            mx_page = max(mx_page,dp[i-1][taka]);
            if(taka>=price) mx_page = max(mx_page,number_of_pages+dp[i-1][taka-price]);
            dp[i][taka] = mx_page;
        }
    }
    cout << *max_element(all(dp[number_of_book])) << endl;
}
//Note : here space complexity is huge , that's why long long int gives runtime error in cses. thats why i comment out it.
