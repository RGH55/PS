#include <cstdio>
#include <algorithm>
#include <vector>
#define MOD 1000003

using namespace std;
using ll = long long;
using mat = vector<vector<ll> >;

int N, S, E, T;
mat A, ans;

mat operator *(const mat& a, const mat& b)
{
    mat ret(5*N, vector<ll>(5*N));
    for(int i=0; i<5*N; i++){
        for(int j=0; j<5*N; j++){
            for(int k=0; k<5*N; k++){
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

mat operator *=(mat& a, const mat& b)
{
    return a = a * b;
}

int main()
{
    scanf("%d %d %d %d", &N, &S, &E, &T);
    A.assign(5*N, vector<ll>(5*N));
    ans.assign(5*N, vector<ll>(5*N));
    for(int i=0; i<N; i++) for(int j=1; j<5; j++) A[5*i + j][5*i + j - 1] = 1;
    for(int i=0; i<5*N; i++) ans[i][i] = 1;
    for(int i=0; i<N; i++){
        char s[15];
        scanf(" %s", s);
        for(int j=0; j<N; j++) if(s[j] != '0') A[5*i][5*j + s[j] - '1'] = 1;
    }
    while(T){
        if(T % 2) ans *= A;
        A *= A;
        T /= 2;
    }
    printf("%lld\n", ans[5 * (S - 1)][5 * (E - 1)]);
    return 0;
}
