#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int> > vt[100005];
int parent[100005][20][3]; /// [0] : NodeNum, [1] : Max, [2] : Min
int depth[100005];

void dfs(int n, int p, int di, int de)
{
    depth[n] = de;
    parent[n][0][0] = p;
    parent[n][0][1] = parent[n][0][2] = di;
    for(int i=1; i<20; i++){
        parent[n][i][0] = parent[parent[n][i - 1][0]][i - 1][0];
        parent[n][i][1] = max(parent[n][i - 1][1], parent[parent[n][i - 1][0]][i - 1][1]);
        parent[n][i][2] = min(parent[n][i - 1][2], parent[parent[n][i - 1][0]][i - 1][2]);
    }
    for(vector<pair<int, int> >::iterator it = vt[n].begin(); it != vt[n].end(); ++it){
        if(it->first == p) continue;
        dfs(it->first, n, it->second, de + 1);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        vt[x].push_back({y, w});
        vt[y].push_back({x, w});
    }
    dfs(1, 0, 0, 0);
    scanf("%d", &K);
    while(K--){
        int x, y;
        int M = 0, m = 1000005;
        scanf("%d %d", &x, &y);
        if(depth[x] < depth[y]) swap(x, y);
        int diff = depth[x] - depth[y];
        for(int i=0; diff; i++){
            if(diff % 2){
                M = max(M, parent[x][i][1]);
                m = min(m, parent[x][i][2]);
                x = parent[x][i][0];
            }
            diff /= 2;
        }
        if(x == y){
            printf("%d %d\n", m, M);
            continue;
        }
        for(int i=19; i>=0; i--){
            if(parent[x][i][0] == parent[y][i][0]) continue;
            M = max(M, max(parent[x][i][1], parent[y][i][1]));
            m = min(m, min(parent[x][i][2], parent[y][i][2]));
            x = parent[x][i][0];
            y = parent[y][i][0];
        }
        M = max(M, max(parent[x][0][1], parent[y][0][1]));
        m = min(m, min(parent[x][0][2], parent[y][0][2]));
        printf("%d %d\n", m, M);
    }
    return 0;
}
