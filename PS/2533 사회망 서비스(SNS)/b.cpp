#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, ans;
vector<int> vt[1000005];

bool dfs(int n, int p)
{
    bool ret = true;
    for(vector<int>::iterator it = vt[n].begin(); it != vt[n].end(); ++it){
        if(*it == p) continue;
        ret &= dfs(*it, n);
    }
    if(!ret) ans++;
    return !ret;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        vt[x].push_back(y);
        vt[y].push_back(x);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}
