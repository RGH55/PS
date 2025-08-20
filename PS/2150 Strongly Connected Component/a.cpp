#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int V, E;
vector<int> vt[10005];

int main()
{
    scanf("%d %d", &V, &E);
    for(int i=0; i<E; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        vt[x].push_back(y);
    }

    return 0;
}
