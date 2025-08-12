#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int a[100005];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &a[i]);
    sort(a, a + N);
    int sum = abs(a[0] + a[1]);
    int ans[2] = {a[0], a[1]};
    int s = 0, e = N - 1;
    while(s < e){
        if(abs(a[s] + a[e]) < sum){
            sum = abs(a[s] + a[e]);
            ans[0] = a[s]; ans[1] = a[e];
        }
        if(a[s] + a[e] > 0) e--;
        else s++;
    }
    printf("%d %d\n", ans[0], ans[1]);
    return 0;
}
