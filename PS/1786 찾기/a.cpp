#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_LEN 1000005

using namespace std;

char T[MAX_LEN], P[MAX_LEN];
int a[MAX_LEN];
vector<int> ans;

int main()
{
    fgets(T, MAX_LEN, stdin);
    fgets(P, MAX_LEN, stdin);
    for(int i=0; i<MAX_LEN; i++){
        if(T[i] == '\n') T[i] = 0;
        if(P[i] == '\n') P[i] = 0;
    }
    int i = 1, j = 0;
    while(P[i + j] != '\0'){
        while(P[i + j] == P[j]){
            a[i + j + 1] = j + 1;
            j++;
        }
        i = i + j - a[j];
        if(j == 0) i++;
        j = a[j];
    }
    i = 0, j = 0;
    while(T[i] != '\0'){
        while(T[i + j] != '\0' && T[i + j] == P[j]) j++;
        if(P[j] == '\0') ans.push_back(i + 1);
        i = i + j - a[j];
        if(j == 0) i++;
        j = a[j];
    }
    printf("%d\n", ans.size());
    for(vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) printf("%d ", *it); printf("\n");
    return 0;
}
