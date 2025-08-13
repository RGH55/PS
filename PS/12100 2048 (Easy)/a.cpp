#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int a[25][25], ans;

void dfs(int n, int m)
{
    if(n == 5){
        ans = max(ans, m);
        return;
    }
    int tmp[25][25];
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) tmp[i][j] = a[i][j];
    for(int i=0; i<N; i++){
        bool flag[N] = {0,};
        for(int j=1; j<N; j++){
            int nj = j;
            while(nj >= 0){
                if(nj - 1)
            }
        }
    }
}

int main()
{
    scanf("%d", &N);
    int m = 0;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++){
        scanf("%d", &a[i][j]);
        m = max(m, a[i][j]);
    }
    dfs(0, m);
    printf("%d\n", ans);
    return 0;
}
