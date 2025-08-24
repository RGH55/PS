#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> a[2][20005];
vector<int> last;
int visited[2][20005], cnt = 1;
bool ans = true;

int Not(int& x)
{
    if(x % 2) return x - 1;
    return x + 1;
}

void dfs(int n, int i)
{
    if(visited[i][n]) return;
    visited[i][n] = cnt;
    if(i == 1 && visited[i][Not(n)] == cnt) ans = false;
    for(vector<int>::iterator it = a[i][n].begin(); it != a[i][n].end(); ++it){
        dfs(*it, i);
    }
    if(i == 0) last.push_back(n);
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        if(x > 0) x *= 2;
        else x = -2 * x + 1;
        if(y > 0) y *= 2;
        else y = -2 * y + 1;
        a[0][Not(x)].push_back(y);
        a[0][Not(y)].push_back(x);
        a[1][x].push_back(Not(y));
        a[1][y].push_back(Not(x));
    }
    for(int i = 2; i < 2*N + 2; i++) dfs(i, 0);
    for(vector<int>::reverse_iterator it = last.rbegin(); it != last.rend(); ++it){
        dfs(*it, 1);
        cnt++;
    }
    printf("%d\n", ans);
    return 0;
}
