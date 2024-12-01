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
int dist[MAXN];
int parent[MAXN];
void bfs(){
    queue<int>q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        for(auto child : graph[vertex]){
            if(vis[child]){
                if(dist[child]>1+dist[vertex]){
                    dist[child] = 1+dist[vertex];
                    parent[child] = vertex;
                }
                continue;
            }
            parent[child] = vertex;
            q.push(child);
            dist[child] = 1 + dist[vertex];
            vis[child] = 1;
        }
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
    memset(parent,-1,sizeof(parent));
    bfs();
    if(parent[n]==-1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        int vertex = n;
        while(parent[vertex]!=-1){
            ans.push_back(parent[vertex]);
            vertex = parent[vertex];
        }
        cout << ans.size()+1 << endl;
        for(int i=ans.size()-1;i>=0;i--){
            cout << ans[i] << " ";
        }
        cout << n << endl;
    }
}
