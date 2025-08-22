#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int N, ans;
string a[100005];

void f(int n, int s, int e)
{
    if(s + 1 == e) return;
    int flag = s;
    for(int i=s+1; i<e; i++){
        if(a[i - 1][n] != a[i][n]){
            if(a[i - 1][n] == 0) ans--;
            f(n + 1, flag, i);
            flag = i;
        }
    }
    f(n + 1, flag, e);
    if(flag != s || n == 0) ans += e - s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> N){
        for(int i=0; i<N; i++) cin >> a[i];
        sort(a, a + N);
        ans = 0;
        f(0, 0, N);
        if(ans == 0) printf("%.2f\n", (float)1/N);
        else printf("%.2f\n", (float)ans/N);
    }
    return 0;
}
