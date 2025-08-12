#include <cstdio>

using namespace std;

int N, ans;
int a[16];

void f(int n, int k)
{
    if(a[k] != -1) return;
    for(int i=0; i<N; i++){
        if(a[i] == -1) continue;
        if(a[i]+i == n+k) return;
        if(a[i]-i == n-k) return;
    }
    if(n == N-1){
        ans++;
        return;
    }
    a[k] = n;
    for(int i=0; i<N; i++) f(n+1, i);
    a[k] = -1;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) a[i] = -1;
    for(int i=0; i<N; i++) f(0, i);
    printf("%d\n", ans);
    return 0;
}
