#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int V, E;
vector<int> vt[2][10005];
vector<vector<int>> ans;
vector<int> last;
bool visited[10005][2];

bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a.front() < b.front();
}

void dfs(int n, int i)
{
    if(visited[n][i]) return;
    visited[n][i] = true;
    for(vector<int>::iterator it = vt[i][n].begin(); it != vt[i][n].end(); ++it){
        dfs(*it, i);
    }
    if(i == 0) last.push_back(n);
    else ans.back().push_back(n);
}

int main()
{
    scanf("%d %d", &V, &E);
    for(int i=0; i<E; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        vt[0][x].push_back(y);
        vt[1][y].push_back(x);
    }
    for(int i=1; i<=V; i++) dfs(i, 0);
    for(vector<int>::reverse_iterator it = last.rbegin(); it != last.rend(); ++it){
        if(visited[*it][1]) continue;
        ans.push_back(vector<int>());
        dfs(*it, 1);
    }
    for(vector<vector<int>>::iterator it = ans.begin(); it != ans.end(); ++it) sort(it->begin(), it->end());
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for(vector<vector<int>>::iterator it = ans.begin(); it != ans.end(); ++it){
        for(vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2) printf("%d ", *it2);
        printf("-1\n");
    }
    return 0;
}
