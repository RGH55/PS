#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int> > a[40005];
int parent[40005][20], depth[40005], dist[40005];

void dfs(int n, int di, int p, int de)
{
    depth[n] = de;
    dist[n] = di;
    parent[n][0] = p;
    for(int i=1; (1 << i) < N; i++){
        parent[n][i] = parent[parent[n][i - 1]][i - 1];
    }
    for(vector<pair<int, int> >::iterator it = a[n].begin(); it != a[n].end(); ++it){
        if(it->first == p) continue;
        dfs(it->first, di + it->second, n, de + 1);
    }
}

int lca(int x, int y)
{
    if(depth[x] < depth[y]) swap(x, y);
    int d = depth[x] - depth[y];
    for(int i=0; d; i++){
        if(d % 2) x = parent[x][i];
        d /= 2;
    }
    if(x == y) return x;
    for(int i=19; i>=0; i--){
        if(parent[x][i] != parent[y][i]){
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        a[x].push_back({y, d});
        a[y].push_back({x, d});
    }
    dfs(1, 0, 0, 0);
    scanf("%d", &M);
    while(M--){
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", dist[x] + dist[y] - dist[lca(x, y)] * 2);
    }
    return 0;
}
