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
int ans[MAXN];
int flag = 1;
void dfs(int vertex, int parent, int team){
    ans[vertex] = team;
    vis[vertex] = 1;
    for(auto child : graph[vertex]){
        if(parent==child) continue;
        if(vis[child] && ans[child]==team){
            flag = 0;
            return;
        }
        if(vis[child]) continue;
        if(team==1) dfs(child,vertex,2);
        else dfs(child,vertex,1);
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
        dfs(i,-1,1);
    }
    if(flag==0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
