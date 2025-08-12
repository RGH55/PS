#include <cstdio>
#include <algorithm>

using namespace std;

int a[9][9];
bool sq[9][10], row[9][10], col[9][10];

int whichSquare(int x, int y)
{
    if(0 <= x && x < 3){
        if(0 <= y && y < 3) return 0;
        if(3 <= y && y < 6) return 1;
        return 2;
    }
    if(3 <= x && x < 6){
        if(0 <= y && y < 3) return 3;
        if(3 <= y && y < 6) return 4;
        return 5;
    }
    if(0 <= y && y < 3) return 6;
    if(3 <= y && y < 6) return 7;
    return 8;

}

bool f(int x, int y)
{
    if(y >= 9) return f(x+1, 0);
    if(x >= 9){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++) printf("%d ", a[i][j]);
            printf("\n");
        }
        return true;
    }
    if(a[x][y] != 0) return f(x, y+1);
    for(int i=1; i<=9; i++){
        if(sq[whichSquare(x, y)][i] || row[x][i] || col[y][i]) continue;
        a[x][y] = i;
        sq[whichSquare(x, y)][i] = row[x][i] = col[y][i] = true;
        if(f(x, y+1)) return true;
        a[x][y] = 0;
        sq[whichSquare(x, y)][i] = row[x][i] = col[y][i] = false;
    }
    return false;
}

int main()
{
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] != 0) sq[whichSquare(i, j)][a[i][j]] = row[i][a[i][j]] = col[j][a[i][j]] = true;
        }
    }
    if(!f(0, 0)) printf("-1\n");
    return 0;
}
