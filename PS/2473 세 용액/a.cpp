#include <cstdio>
#include <algorithm>

using namespace std;

int N;
long long a[5005];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%lld", &a[i]);
    sort(a, a + N);
    long long sum = abs(a[0] + a[1] + a[2]);
    long long ans[3] = {a[0], a[1], a[2]};
    for(int i=0; i<N; i++){
        int s = 0, e = N-1;
        while(s < e){
            if(s != i && e != i && abs(a[i] + a[s] + a[e]) < sum){
                sum = abs(a[i] + a[s] + a[e]);
                ans[0] = a[i]; ans[1] = a[s]; ans[2] = a[e];
            }
            if(a[i] + a[s] + a[e] > 0) e--;
            else s++;
        }
    }
    sort(ans, ans + 3);
    printf("%lld %lld %lld\n", ans[0], ans[1], ans[2]);
    return 0;
}
