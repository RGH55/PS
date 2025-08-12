#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int a[2005];
int dp[2005][2005];

int isPalindrome(int s, int e)
{
    int& res = dp[s][e];
    if(res) return res;
    if(s >= e) return res = 1;
    if(a[s] != a[e]) return res = -1;
    return res = isPalindrome(s+1, e-1);
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &a[i]);
    scanf("%d", &M);
    while(M--){
        int s, e;
        scanf("%d %d", &s, &e);
        if(isPalindrome(s, e) == 1) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
