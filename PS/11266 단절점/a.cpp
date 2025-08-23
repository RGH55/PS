#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int V, E;
vector<int> vt[10005], ans;
bool visited[10005];

void dfs(int n)
{
    if(visited[n]) return;
    visited[n] = true;
    for(vector<int>::iterator it = vt[n].begin(); it != vt[n].end(); ++it){
        dfs(*it);
    }
}

bool check(int n)
{
    for(int i=1; i<=V; i++) visited[i] = false;
    visited[n] = true;
    dfs(vt[n].front());
    for(vector<int>::iterator it = vt[n].begin() + 1; it != vt[n].end(); ++it){
        if(!visited[*it]) return true;
    }
    return false;
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
    for(int i=1; i<=V; i++) if(check(i)) ans.push_back(i);
    printf("%d\n", ans.size());
    for(vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) printf("%d ", *it);
    printf("\n");
    return 0;
}
