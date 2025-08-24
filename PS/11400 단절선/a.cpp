#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int V, E;
vector<int> vt[100005];
vector<pair<int, int>> ans;
int visited[100005], cnt;

int dfs(int n, int p)
{
    visited[n] = ++cnt;
    int ret = visited[n];
    for(vector<int>::iterator it = vt[n].begin(); it != vt[n].end(); ++it){
        if(*it == p) continue;
        if(visited[*it]){
            ret = min(ret, visited[*it]);
            continue;
        }
        int x = dfs(*it, n);
        if(x > visited[n]) ans.push_back({min(n, *it), max(n, *it)});
        ret = min(ret, x);
    }
    return ret;
}

int main()
{
    scanf("%d %d", &V, &E);
    for(int i=0; i<E; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        vt[x].push_back(y);
        vt[y].push_back(x);
    }
    for(int i=1; i<=V; i++) dfs(i, 0);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(vector<pair<int, int>>::iterator it = ans.begin(); it != ans.end(); ++it) printf("%d %d\n", it->first, it->second);
    return 0;
}
