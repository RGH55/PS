#include <cstdio>
#include <algorithm>

using namespace std;

int N;
long long a[10005][2];
long long ans;

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%lld %lld", &a[i][0], &a[i][1]);
    a[N][0] = a[0][0];
    a[N][1] = a[0][1];
    for(int i=0; i<=N; i++){
        ans += a[i][0] * a[i+1][1] - a[i][1] * a[i+1][0];
    }
    if(ans > 0) printf("%.1lf\n", (double)ans/2);
    else printf("%.1lf\n", -(double)ans/2);
    return 0;
}
