#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <unordered_set>
#include <map>
#include <string>
#include <cstring>
#include <unordered_map>
#include <sstream>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
#define MAX 2147000000
#define MOD 998244353LL
using namespace std;

struct st {
    int v, e, dis;
};


int main() {
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n, m, w;
        cin >> n >> m >> w;
        vector<st> edge;
        for(int i{0}; i < m; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            edge.push_back({a, b, c});
            edge.push_back({b, a, c});
        }
        for(int i{0}; i < w; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            edge.push_back({a, b, -c});
        }
        vi bell(n, MAX);
        bell[0] = 0;
        for(int i{0}; i < n - 1; ++i){
            for(int j{0}; j < 2 * m + w; ++j){
                int a = edge[j].v;
                int b = edge[j].e;
                int c = edge[j].dis;
                bell[b] = min(bell[b], bell[a] + c);
            }
        }
        bool flag = false;
        for(int i{0}; i < 2 * m + w; ++i){
            int a = edge[i].v;
            int b = edge[i].e;
            int c = edge[i].dis;
            if(bell[b] > bell[a] + c) flag = true;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }  
}