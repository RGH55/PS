#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int a[4][4005];
vector<int> vt[2];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d %d %d %d", &a[0][i], &a[1][i], &a[2][i], &a[3][i]);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            vt[0].push_back(a[0][i] + a[1][j]);
            vt[1].push_back(a[2][i] + a[3][j]);
        }
    }
    sort(vt[0].begin(), vt[0].end());
    sort(vt[1].begin(), vt[1].end());
    long long cnt = 0;
    for(vector<int>::iterator it = vt[0].begin(); it != vt[0].end(); ++it){
        int s1 = 0, e1 = vt[1].size(), s2 = 0, e2 = vt[1].size();
        while(s1 < e1){
            int m = (s1+e1)/2;
            if(vt[1][m] >= -*it) e1 = m;
            else s1 = m + 1;
        }
        while(s2 < e2){
            int m = (s2+e2)/2;
            if(vt[1][m] > -*it) e2 = m;
            else s2 = m + 1;
        }
        cnt += s2 - s1;
    }
    printf("%lld\n", cnt);
    return 0;
}
