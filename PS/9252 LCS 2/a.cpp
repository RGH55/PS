#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

char s1[1005], s2[1005];
int dp[1005][1005];
vector<char> ans;

int main()
{
    scanf(" %s %s", s1, s2);
    int len1 = 0, len2 = 0;
    while(s1[len1] != '\0') len1++;
    while(s2[len2] != '\0') len2++;
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i = len1, j = len2;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            ans.push_back(s1[i-1]);
            i--; j--;
        }
        else if(dp[i][j-1] >= dp[i-1][j]) j--;
        else i--;
    }
    printf("%d\n", dp[len1][len2]);
    for(vector<char>::reverse_iterator it = ans.rbegin(); it != ans.rend(); ++it) printf("%c", *it);
    printf("\n");
    return 0;
}
