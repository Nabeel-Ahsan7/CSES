#include <bits/stdc++.h>
#define int                long long int
#define yes                cout << "YES" << endl
#define no                 cout << "NO" << endl
#define fastIO             ios::sync_with_stdio(false); cin.tie(NULL);
#define ull                unsigned long long int
#define all(v)             v.begin(),v.end()
#define print(v)           for(auto x : v) cout << x << " "; cout << endl;
#define init(arr, val)     memset(arr, val, sizeof(arr))
#define testcase(x)        cout << "Case " << x << ": "
using namespace std;
const int MAXN = 1e5+10;
vector<int>graph[MAXN];
int vis[MAXN];
void dfs(int vertex){
    vis[vertex] = 1;
    for(auto child : graph[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}
int32_t main()
{
    int n,m; cin >> n >> m;
    vector<int>ans;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i);
        ans.push_back(i);
    }
    cout << ans.size()-1 << endl;
    for(int i=1; i< ans.size(); i++){
        cout << ans[i-1] << " " << ans[i] << endl;
    }
}
