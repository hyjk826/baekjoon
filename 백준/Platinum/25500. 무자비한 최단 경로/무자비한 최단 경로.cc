// 2022-09-16
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

struct st {
    ll x, y, z, num;
};

struct st2 {
    ll v, w;
    bool operator< (const st2& a) const {
        return w > a.w;
    }
};

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<st> vec(n);
    vector<vector<st2>> g(n + k + 1);
    for (int i{ 0 }; i < n; ++i) {
        cin >> vec[i].x >> vec[i].y >> vec[i].z;
        vec[i].num = i;
    }
    sort(vec.begin(), vec.end(), [&](st a, st b) {
        return a.x < b.x;
    });
    for (int i{ 1 }; i < (int)vec.size() - 1; ++i) {
        g[vec[i - 1].num].push_back({ vec[i].num, abs(vec[i - 1].x - vec[i].x) });
        g[vec[i].num].push_back({ vec[i - 1].num, abs(vec[i - 1].x - vec[i].x) });
        g[vec[i].num].push_back({ vec[i + 1].num, abs(vec[i + 1].x - vec[i].x) });
        g[vec[i + 1].num].push_back({ vec[i].num, abs(vec[i + 1].x - vec[i].x) });
    }
    sort(vec.begin(), vec.end(), [&](st a, st b) {
        return a.y < b.y;
    });
    for (int i{ 1 }; i < (int)vec.size() - 1; ++i) {
        g[vec[i - 1].num].push_back({ vec[i].num, abs(vec[i - 1].y - vec[i].y) });
        g[vec[i].num].push_back({ vec[i - 1].num, abs(vec[i - 1].y - vec[i].y) });
        g[vec[i].num].push_back({ vec[i + 1].num, abs(vec[i + 1].y - vec[i].y) });
        g[vec[i + 1].num].push_back({ vec[i].num, abs(vec[i + 1].y - vec[i].y) });
    }
    for (int i{ 0 }; i < n; ++i) {
        int a = vec[i].z % k;
        int b = (k - a) % k;
        g[vec[i].num].push_back({ n + a, vec[i].z });
        g[n + b].push_back({ vec[i].num, vec[i].z });
    }
    vl dijk(n + k + 1, (ll)1e18);
    dijk[0] = 0;
    priority_queue<st2> pQ;
    pQ.push({ 0, 0 });
    while (!pQ.empty()) {
        ll v{ pQ.top().v };
        ll w{ pQ.top().w };
        pQ.pop();
        if (dijk[v] < w) continue;
        for (auto& u : g[v]) {
            ll nv{ u.v };
            ll nw{ u.w };
            if (dijk[nv] > dijk[v] + nw) {
                dijk[nv] = dijk[v] + nw;
                pQ.push({ nv, dijk[nv] });
            }
        }
    }
    for (int i{ 0 }; i < n; ++i) {
        cout << dijk[i] << "\n";
    }
}


