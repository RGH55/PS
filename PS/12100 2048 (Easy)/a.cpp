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
    int tmp[25][25], nm = m;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) tmp[i][j] = a[i][j];
    for(int i=0; i<N; i++){
        bool flag[N] = {0,};
        for(int j=1; j<N; j++){
            int nj = j;
            while(nj > 0 && a[i][nj - 1] == 0) nj--;
            if(nj > 0 && !flag[nj - 1] && a[i][nj - 1] == a[i][j]){
                a[i][j] = 0;
                a[i][nj - 1] *= 2;
                nm = max(nm, a[i][nj - 1]);
                flag[nj - 1] = true;
            }
            else{
                int tmp = a[i][j];
                a[i][j] = 0;
                a[i][nj] = tmp;
            }
        }
    }
    dfs(n + 1, nm);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) a[i][j] = tmp[i][j];
    nm = m;
    for(int i=0; i<N; i++){
        bool flag[N] = {0,};
        for(int j=N-2; j>=0; j--){
            int nj = j;
            while(nj < N - 1 && a[i][nj + 1] == 0) nj++;
            if(nj < N - 1 && !flag[nj + 1] && a[i][nj + 1] == a[i][j]){
                a[i][j] = 0;
                a[i][nj + 1] *= 2;
                nm = max(nm, a[i][nj + 1]);
                flag[nj + 1] = true;
            }
            else{
                int tmp = a[i][j];
                a[i][j] = 0;
                a[i][nj] = tmp;
            }
        }
    }
    dfs(n + 1, nm);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) a[i][j] = tmp[i][j];
    nm = m;
    for(int i=0; i<N; i++){
        bool flag[N] = {0,};
        for(int j=1; j<N; j++){
            int nj = j;
            while(nj > 0 && a[nj - 1][i] == 0) nj--;
            if(nj > 0 && !flag[nj - 1] && a[nj - 1][i] == a[j][i]){
                a[j][i] = 0;
                a[nj - 1][i] *= 2;
                nm = max(nm, a[nj - 1][i]);
                flag[nj - 1] = true;
            }
            else{
                int tmp = a[j][i];
                a[j][i] = 0;
                a[nj][i] = tmp;
            }
        }
    }
    dfs(n + 1, nm);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) a[i][j] = tmp[i][j];
    nm = m;
    for(int i=0; i<N; i++){
        bool flag[N] = {0,};
        for(int j=N-2; j>=0; j--){
            int nj = j;
            while(nj < N - 1 && a[nj + 1][i] == 0) nj++;
            if(nj < N - 1 && !flag[nj + 1] && a[nj + 1][i] == a[j][i]){
                a[j][i] = 0;
                a[nj + 1][i] *= 2;
                nm = max(nm, a[nj + 1][i]);
                flag[nj + 1] = true;
            }
            else{
                int tmp = a[j][i];
                a[j][i] = 0;
                a[nj][i] = tmp;
            }
        }
    }
    dfs(n + 1, nm);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) a[i][j] = tmp[i][j];
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
