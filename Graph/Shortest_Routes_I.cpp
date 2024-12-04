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
#define inf                LLONG_MAX;
using namespace std;
 
const int MAXN = 1e5+5;
int vis[MAXN];
int dist[MAXN];
vector<pair<int,int>> Graph[MAXN];

void Dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source] = 0;
    
    while(!pq.empty()) {
        auto Short_Distance = pq.top();
        pq.pop();
        
        int vertex = Short_Distance.second;
        int current_dist = Short_Distance.first;

        if(current_dist > dist[vertex]) continue;
 
        for(auto child : Graph[vertex]) {
            int child_wt = child.second;
            int child_vertex = child.first;
            
            if(dist[child_vertex] > dist[vertex] + child_wt) {
                dist[child_vertex] = dist[vertex] + child_wt;
                pq.push({dist[child_vertex], child_vertex});
            }
        }
    }
}
 
int32_t main() {
    int n, m;
    cin >> n >> m;
    
    // Initialize distances to infinity
    for(int i = 0; i <= MAXN; i++) dist[i] = inf;
 
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        Graph[u].push_back({v, wt});
    }

    Dijkstra(1);

    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}
