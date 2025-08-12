#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int maxNode, maxDist;
bool visited[10005];
vector<pair<int, int> > vt[10005];

void dfs(int n, int dist)
{
    if(visited[n]) return;
    visited[n] = true;
    if(maxDist < dist){
        maxNode = n;
        maxDist = dist;
    }
    for(vector<pair<int, int> >::iterator it = vt[n].begin(); it != vt[n].end(); ++it){
        dfs(it->first, dist + it->second);
    }
    visited[n] = false;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        vt[a].push_back({b, w});
        vt[b].push_back({a, w});
    }

    dfs(1, 0);
    dfs(maxNode, 0);

    printf("%d\n", maxDist);
    return 0;
}
