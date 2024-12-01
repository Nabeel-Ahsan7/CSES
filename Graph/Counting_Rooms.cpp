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
const int MAXN = 1e3+5;
vector<string>grid;
int vis[MAXN][MAXN];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int x,int y,int n,int m){
    if(x>=n || x<0 || y>=m || y<0) return;
    if(vis[x][y]) return;
    if(grid[x][y]=='#') return;
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        dfs(dx[i]+x,dy[i]+y,n,m);
    }
}


int32_t main() {
    fastIO;
    int t=1;
    for(int test=1;test<=t;test++){
        int n,m; cin >> n >> m;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            string s; cin >> s;
            grid.push_back(s);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && grid[i][j]=='.'){
                    dfs(i,j,n,m);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }    

    return 0;
}
