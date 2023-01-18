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
    int v, dis;
    bool operator< (const st& a) const {
        return dis < a.dis;
    }
};

vector<st> graph[100001];

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> dijk(n + 1);
    for (int i{ 0 }; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }
    int x, y;
    cin >> x >> y;
    dijk[x] = MAX;
    priority_queue<st> pQ;
    pQ.push({ x, MAX });
    while (!pQ.empty()) {
        int v{ pQ.top().v };
        int dis{ pQ.top().dis };
        pQ.pop();
        if (dijk[v] > dis) continue;
        for (int i{ 0 }; i < (int)graph[v].size(); ++i) {
            int nx{ graph[v][i].v };
            int ndis{ graph[v][i].dis };
            if (min(dis, ndis) > dijk[nx]) {
                dijk[nx] = min(dis, ndis);
                pQ.push({ nx, dijk[nx] });
            }
        }
    }
    cout << dijk[y];
}