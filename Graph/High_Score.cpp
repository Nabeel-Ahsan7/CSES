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
const int N = 2505;
vector<pair<int,int>>graph[N];
int dp[N];
int vis[N];
int target;
bool dfs(int vertex){
    if(vertex==target) return true;
    vis[vertex] = 1;
    bool flag = false;
    for(auto child : graph[vertex]){
        if(vis[child.first]) continue;
        flag |= dfs(child.first);
    }
    return flag;
}
 
int32_t main()
{
    int n,m; cin >> n >> m;
    target = n;
    vector<int>dist(n+1,LLONG_MIN);
    vector<pair<pair<int,int>,int>> edges;
    for(int i=0;i<m;i++){
        int u,v,wt; cin >> u >> v >> wt;
        graph[u].push_back({v,wt});
        edges.push_back({{u,v},wt});
    }
    dist[1] = 0;
    for(int i=0;i<n-1;i++){
        for(auto &x : edges){
            if(dist[x.first.first]!=LLONG_MIN && dist[x.first.first]+x.second>dist[x.first.second]){
                dist[x.first.second] = dist[x.first.first]+x.second;
            }
        }
    }
    int flag = 0;
    for(auto &x : edges){
        if(dist[x.first.first]!=LLONG_MIN && dist[x.first.first]+x.second>dist[x.first.second]){
            dist[x.first.second] = dist[x.first.first]+x.second;
            if(dfs(x.first.second)){
                flag = 1;
                break;
            }
        }
    }
    if(flag ) cout << -1 << endl;
    else cout << dist[n] <<endl;
}
