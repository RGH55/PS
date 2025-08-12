#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

int N;
int a[100005];

<<<<<<< HEAD
=======
pair<int, int> f(int s, int e, int n)
{
    if(s >= e) return {abs(n + a[s]), s};
    int m = (s+e)/2;
    if(n > a[m]){
        pair<int, int> p = f(m+1, e, n);
        if(p.first < abs(n + a[m])) return p;
        return {abs(n + a[m]), m};
    }
    if(n < a[m]){
        pair<int, int> p = f(s, m, n);
        if(p.first < abs(n + a[m])) return p;
        return {abs(n + a[m]), m};
    }
    return {2e9, m};
}

>>>>>>> bde26bf3b8c4cc48434e12731ff51cc1d7322f63
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &a[i]);
    sort(a, a+N);
<<<<<<< HEAD
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
=======
    pair<pair<int, int>, int> ans = {f(0, N, a[0]), 0};
    printf("%d %d\n", ans.first, ans.first.second);
    for(int i=1; i<N; i++){
        pair<int, int> p = f(0, N, a[i]);
        printf("%d %d\n", p.first, p.second);
        if(p.first < ans.first.first) ans = {p, i};
    }
    if(ans.first.first < ans.second) printf("%d %d\n", a[ans.first.first], a[ans.second]);
    else printf("%d %d\n", a[ans.second], a[ans.first.first]);
>>>>>>> bde26bf3b8c4cc48434e12731ff51cc1d7322f63
    return 0;
}
