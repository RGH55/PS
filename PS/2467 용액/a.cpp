#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

int N;
int a[100005];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &a[i]);
    sort(a, a+N);
    int ans = abs(a[0] + a[1]);
    pair<int, int> p = {0, 1};
    for(int i=0; i<N; i++){
        int s = 0, e = N;
        while(s < e){
            int m = (s + e) / 2;
            if(m != i && abs(a[m] + a[i]) < ans){
                ans = abs(a[m] + a[i]);
                p = {min(m, i), max(m, i)};
            }
            if(a[m] + a[i] > 0) e = m;
            else s = m + 1;
        }
    }
    printf("%d %d\n", a[p.first], a[p.second]);
    return 0;
}
