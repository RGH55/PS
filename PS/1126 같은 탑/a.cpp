#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, S;
int a[55], sum[55];
vector<vector<int>> vt;
bool visited[250005];

int dfs(int n, int cnt)
{
    if(n == N){
        if(cnt == 1) return -1;
        for(int i=1; i<cnt; i++) if(sum[i -1] != sum[i]) return -1;
        return sum[0];
    }
    int ret = -1;
    for(int i=0; i<cnt; i++){
        if(a[n] + sum[i] <= S/2){
            vt[i].push_back(a[n]);
            sum[i] += a[n];
            ret = max(ret, dfs(n + 1, cnt));
            vt[i].pop_back();
            sum[i] -= a[n];
        }
    }
    ret = max(ret, dfs(n + 1, cnt));
    if(cnt == 2) return ret;
    vt[cnt].push_back(a[n]);
    sum[cnt] += a[n];
    ret = max(ret, dfs(n + 1, cnt + 1));
    vt[cnt].pop_back();
    sum[cnt] -= a[n];
    return ret;
}

int main()
{
    scanf("%d", &N);
    vt.assign(N, vector<int>());
    for(int i=0; i<N; i++) scanf("%d", &a[i]);
    for(int i=0; i<N; i++) S += a[i];
    sort(a, a + N);
    printf("%d\n", dfs(0, 0));
    return 0;
}
