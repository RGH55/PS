#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


vector<int> N;

long long f(int n, int k) /// n : 카운트하는 숫자, k : 현재 자리수
{
    long long ret = 0, pow = 1;
    if(k < 0){
        for(int i=0; i<N.size(); i++)
            if(N[i] == n) ret++;
        return ret;
    }
    for(int i=0; i<k; i++) pow *= 10;
    for(int i=k+1; i<N.size(); i++){
        if(N[i] == n) ret += N[k] * pow;
    }
    if(N[k] > n) ret += pow;
    ret += N[k] * pow/10 * k;
    if(n == 0 && k == N.size() - 1){
        for(int i=1; i<N.size(); i++){
            pow /= 10;
            ret -= 9 * pow * i;
        }
        ret -= N.size();
    }
    ret += f(n, k - 1);
    return ret;
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n){
        N.push_back(n % 10);
        n /= 10;
    }
    for(int i=0; i<10; i++) printf("%lld ", f(i, N.size() - 1));
    printf("\n");
    return 0;
}
