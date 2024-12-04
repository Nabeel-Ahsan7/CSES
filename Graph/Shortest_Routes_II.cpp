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
#define inf                LLONG_MAX
using namespace std;
 
int32_t main()
{
    int n,m,q; cin >> n >> m >> q;
    int graph[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            graph[i][j] = inf;
        }
    }
    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        graph[u][v] = min(graph[u][v],w);
        graph[v][u] = min(graph[v][u],w);
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j){
                graph[i][j] = 0;
            }
        }
    }
    for(int k=0;k<=n;k++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(graph[i][k] != inf && graph[k][j] != inf){
                    graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
    }
    while(q--){
        int u,v; cin >> u >> v;
        if(graph[u][v]>=inf) cout << -1 << endl;
        else cout << graph[u][v] << endl;
    }
}
