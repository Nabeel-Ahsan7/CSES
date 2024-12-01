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
int guess = 0;
vector<string>grid;
int vis[MAXN][MAXN];
// int dis[MAXN][MAXN];
pair<int,int> parent[MAXN][MAXN];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char direction[] = {'R','L','U','D'};
pair<int,int> End;

void bfs(int x,int y,int n,int m){
    queue<pair<int,int>>st;
    st.push({x,y});
    vis[x][y]=1;
    while(!st.empty()){
        pair<int,int> tp = st.front();
        st.pop();
        vis[tp.first][tp.second]=1;
        
        for(int i=0;i<4;i++){
            int x = dx[i]+tp.first;
            int y = dy[i]+tp.second;
            if(x>=n || x<0 || y>=m || y<0) continue;
            if(grid[x][y]=='#') continue;
            if(grid[x][y]=='B'){
                guess =1 ;
                End={x,y};
                parent[x][y] = tp;
                return;
            }
            if(vis[x][y]){
                continue;
            }
            parent[x][y] = tp;
            st.push({x,y});
            vis[x][y]=1;
        }
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
        int flag = 0;
        pair<int,int>start;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='A'){
                // cout << "ji";

                    bfs(i,j,n,m);
                    start = {i,j};
                    parent[i][j]={-1,-1};
                    // dis[i][j] = 0;
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        vector<pair<int,int>>ans;
        if(guess){
            cout << "YES" << endl;
            ans.push_back(End);
            while(parent[End.first][End.second].first!=-1){
                pair<int,int> p = parent[End.first][End.second];
                ans.push_back(p);
                End = p;
            }
            cout << ans.size()-1<< endl;
            for(int i=ans.size()-2;i>=0;i--){
                if(make_pair(ans[i].first-1,ans[i].second)==ans[i+1]) cout << 'D';
                if(make_pair(ans[i].first+1,ans[i].second)==ans[i+1]) cout << 'U';
                if(make_pair(ans[i].first,ans[i].second+1)==ans[i+1]) cout << 'L';
                if(make_pair(ans[i].first,ans[i].second-1)==ans[i+1]) cout << 'R';
            }
            cout << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }    
 
    return 0;
}
