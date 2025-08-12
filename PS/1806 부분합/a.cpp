#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, S;
int a[100005], sum[100005];
int memo[100005];

int check(int len)
{
    if(memo[len] != -1) return memo[len];
    if(sum[len-1] >= S) return memo[len] = 1;
    for(int i=len; i<N; i++){
        if(sum[i] - sum[i-len] >= S) return memo[len] = 1;
    }
    return memo[len] = 0;
}

int f(int s, int e)
{
    if(s > e) return 0;
    int m = (s + e) / 2;
    if(check(m)){
        if(s == e) return s;
        return f(s, m);
    }
    else{
        return f(m+1, e);
    }
}

int main()
{
    scanf("%d %d", &N, &S);
    for(int i=0; i<=N; i++) memo[i] = -1;
    for(int i=0; i<N; i++){
        scanf("%d", &a[i]);
        sum[i] = (i > 0 ? sum[i-1] : 0) + a[i];
    }
    printf("%d\n", f(0, N));
    return 0;
}
