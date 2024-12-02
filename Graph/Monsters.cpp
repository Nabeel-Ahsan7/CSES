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
int vis[MAXN][MAXN];
int dist[MAXN][MAXN];
char direction[MAXN][MAXN];
pair<int,int> parent[MAXN][MAXN];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char mv[] ={'R','L','D','U'}; 
int flag = 0;
int endX = 0;
int endY = 0;


void Multi_Source_BFS(vector<pair<pair<int,int>,int>>&source,vector<string>&v,int n,int m){
    queue<pair<pair<int,int>,int>>q;
    for(auto &x : source){
        q.push(x);
        vis[x.first.first][x.first.second] = 1;
    }
    while(!q.empty()){
        pair<pair<int,int>,int> tp = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x = tp.first.first + dx[i];
            int y = tp.first.second + dy[i];
            if(x>=n || x<0 || y>=m || y<0) continue;
            if(vis[x][y]) continue;
            if(v[x][y]=='#') continue;
            q.push({{x,y},tp.second+1});
            dist[x][y] = tp.second+1;
            vis[x][y] = 1;
        }
    }
}



void BFS(int axisX, int axisY , vector<string>&v , int n , int m){
    if(axisX == n-1 || axisX == 0 || axisY == m-1 || axisY == 0){
        endX = axisX;
        endY = axisY;
        flag = 1;
        return;
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{axisX,axisY},0});
    vis[axisX][axisY] = 1;
    while(!q.empty()){
        auto tp = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x = tp.first.first + dx[i];
            int y = tp.first.second + dy[i];
            if(vis[x][y] || x>=n || x<0 || y>=m || y<0 || v[x][y]=='#') continue;
            if(x==n-1 || y==m-1 || x == 0 || y == 0){
                if(dist[x][y] > tp.second + 1){
                    endX = x;
                    endY = y;
                    direction[x][y] = mv[i];
                    flag = 1;
                    parent[x][y] = {tp.first.first,tp.first.second};
                    break;
                }
            }
            direction[x][y] = mv[i];
            vis[x][y] = 1;
            q.push({{x,y},tp.second+1});
            parent[x][y] = {tp.first.first,tp.first.second};
        }
        if(flag) break;
    }
}

int32_t main()
{
    int n,m; cin >> n >> m;
    vector<string>v(n);
    for(auto &x : v) cin >> x;
    int X,Y;
    vector<pair<pair<int,int>,int>>monster;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='A') X = i,Y=j;
            if(v[i][j]=='M') monster.push_back({{i,j},0});
        }
    }
    Multi_Source_BFS(monster,v,n,m);
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j]==0 && v[i][j]!='A' && v[i][j]!='#' && v[i][j]!='M') dist[i][j]=INT_MAX;
        }
    }
    BFS(X,Y,v,n,m);
    if(flag){
        cout << "YES" << endl;
        string ans = "";
        parent[X][Y]={-1,-1}; 
        while(parent[endX][endY].first!=-1){
            ans+=direction[endX][endY];
            auto tp = parent[endX][endY];
            endX = tp.first;
            endY = tp.second;
        }
        cout << ans.size() << endl;
        if(ans.size()){
            for(int i=ans.size()-1 ; i>=0;i--){
                cout << ans[i];
            }
            cout << endl;
        }
    }
    else{
        cout << "NO" << endl;
    }
}
