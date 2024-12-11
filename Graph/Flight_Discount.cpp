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
const int N = 1e5+5;
vector<pair<int,int>>graph[N];
int dist[N][2];
 
void dijkstra(int vertex){
    set<pair<int,pair<int,int>>>st;
    st.insert({0,{vertex,0}});
    dist[vertex][0] = 0;
    dist[vertex][1] = 0;
    while(!st.empty()){
        auto node = *st.begin();
        st.erase(st.begin());
        int v = node.second.first;
        int flag = node.second.second;
        int wt = node.first;
        if (wt > dist[v][flag]) continue;
        for(auto child : graph[v]){
            if(flag){
                if(dist[v][flag]+child.second<dist[child.first][flag]){
                    dist[child.first][flag] = dist[v][flag]+child.second;
                    st.insert({dist[child.first][flag],{child.first,flag}});
                }
            }
            else{
                int child_wt = child.second;
                int child_vertex = child.first;
                // using cupon
                int wt_after_using_cupon = child_wt/2;
                if(dist[v][0]+wt_after_using_cupon<dist[child_vertex][1]){
                    dist[child_vertex][1] = dist[v][0]+wt_after_using_cupon;
                    st.insert({dist[child_vertex][1],{child_vertex,1}});
                }
                if(dist[v][0]+child_wt < dist[child_vertex][0]){
                    dist[child_vertex][0] = dist[v][0]+child_wt;
                    st.insert({dist[child_vertex][0],{child_vertex,0}});
                }
            }
        }
    }
}
 
int32_t main() {
    fill(&dist[0][0], &dist[N][0], LLONG_MAX);
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,wt; cin >> u >> v >> wt;
        graph[u].push_back({v,wt});
    }
    dijkstra(1);
    cout << min(dist[n][0],dist[n][1]) << endl;
}
