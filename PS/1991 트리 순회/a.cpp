#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
pair<int, int> a[30];

void traverse(int n, int o)
{
    if(n == -1) return;
    if(o == 1) printf("%c", n + 'A');
    traverse(a[n].first, o);
    if(o == 2) printf("%c", n + 'A');
    traverse(a[n].second, o);
    if(o == 3) printf("%c", n + 'A');
}

int main()
{
    scanf("%d\n", &N);
    for(int i=0; i<N; i++){
        char p, l, r;
        scanf(" %c %c %c", &p, &l, &r);
        if(l == '.') a[p-'A'].first = -1;
        else a[p-'A'].first = l - 'A';
        if(r == '.') a[p-'A'].second = -1;
        else a[p-'A'].second = r - 'A';
    }

    traverse(0, 1); printf("\n");
    traverse(0, 2); printf("\n");
    traverse(0, 3); printf("\n");

    return 0;
}
