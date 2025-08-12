#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int a[25][25];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &a[i][j]);
    return 0;
}
