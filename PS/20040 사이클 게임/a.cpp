#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int a[500005];

int getParent(int x)
{
    if(a[x] == x) return x;
    return a[x] = getParent(a[x]);
}

void unionParent(int x, int y)
{
    x = getParent(x);
    y = getParent(y);
    a[x] = y;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) a[i] = i;
    for(int i=1; i<=M; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        if(getParent(x) == getParent(y)){
            printf("%d\n", i);
            return 0;
        }
        unionParent(x, y);
    }
    printf("0\n");
    return 0;
}
