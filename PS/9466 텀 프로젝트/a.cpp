#include <cstdio>
#include <algorithm>

using namespace std;

int T, N;
int a[100005];
int visited[100005];

int f(int n)
{
    if(visited[n] == 1) return n;
    if(visited[n] == -1 || visited[n] == 2) return -1;
    visited[n] = 1;
    int x = f(a[n]);
    if(x == -1){
        visited[n] = -1;
        return -1;
    }
    visited[n] = 2;
    if(x == n) return -1;
    return x;
}

int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i=1; i<=N; i++) visited[i] = 0;
        for(int i=1; i<=N; i++) scanf("%d", &a[i]);
        for(int i=1; i<=N; i++) f(i);
        int cnt = 0;
        for(int i=1; i<=N; i++){
            if(visited[i] == -1) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
