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
int parent[MAXN];
int V = -1;
int flag = 0;
void dfs(int vertex, int p){
    vis[vertex] = 1;
    for(auto child : graph[vertex]){
        if(child==p) continue;
        if(vis[child] && V==-1){
            flag = 1;
            V = vertex;
            parent[child] = -1;
            return;
        }
        if(vis[child]) continue;
        parent[child] = vertex;
        dfs(child,vertex);
    }
}
 
int32_t main()
{
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i,-1);
    }
    if(flag==0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int>ans;
    while(true){
        ans.push_back(V);
        if(parent[V]==-1) break;
        V = parent[V];
    }
    cout << ans.size()+1 << endl;
    for(auto x : ans){
        cout << x << " ";
    }
    cout << ans[0] << endl;
}
