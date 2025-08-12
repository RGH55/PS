#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, K;
long long ans;
vector<pair<int, int> > vt;
multiset<int> s;

int main()
{
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        int m, v;
        scanf("%d %d", &m, &v);
        vt.push_back({v, m});
    }
    for(int i=0; i<K; i++){
        int c;
        scanf("%d", &c);
        s.insert(c);
    }
    sort(vt.begin(), vt.end());

    for(vector<pair<int, int> >::reverse_iterator it = vt.rbegin(); it != vt.rend(); ++it){
        set<int>::iterator itlow = s.lower_bound(it->second);
        if(itlow == s.end()) continue;
        s.erase(itlow);
        ans += it->first;
    }
    printf("%lld\n", ans);
    return 0;
}
