#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> a[100005];
int parent[100005];
bool visited[100005];

void dfs(int n, int p)
{
    if(visited[n]) return;
    visited[n] = true;
    parent[n] = p;
    for(vector<int>::iterator it = a[n].begin(); it != a[n].end(); ++it){
        dfs(*it, n);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        int x, y, d;
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 0);
    scanf("%d", &M);
    while(M--){
        for(int i=1; i<=N; i++) visited[i] = false;
        int x, y, p;
        scanf("%d %d", &x, &y);
        p = x;
        while(p != 1){
            visited[p] = true;
            p = parent[p];
        }
        visited[1] = true;
        p = y;
        while(!visited[p]) p = parent[p];
        printf("%d\n", p);
    }
    return 0;
}
