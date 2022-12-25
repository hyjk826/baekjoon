// 2022-12-24
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
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

struct st{
    int x, y1, y2, flag;
    bool operator< (const st& a) const{
        return x < a.x;
    }
};

const int sz = 30010;
vi seg(sz * 4);
vi cnt(sz * 4);
vector<st> line;

void update(int node, int l, int r, int s, int e, int value){
    if(r < s || l > e) return;
    if(s <= l && r <= e){
        cnt[node] += value;
    }
    else{
        int mid = (l + r) / 2;
        update(node * 2, l, mid, s, e, value);
        update(node * 2 + 1, mid + 1, r , s, e, value);
    }
    if(cnt[node]) seg[node] = r - l + 1;
    else {
        if(l == r) seg[node] = 0;
        else seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }
}

int main(){
	fastio;
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        line.push_back({x1, y1, y2, 1});
        line.push_back({x2, y1, y2, -1});
    }
    sort(line.begin(), line.end());
    int ans{0};
    for(int i{0}; i < (int)line.size(); ++i){
        if(i){
            ans += (line[i].x - line[i - 1].x) * seg[1];
        }
        update(1, 0, 30000, line[i].y1, line[i].y2 - 1, line[i].flag);
    }
    cout << ans;
}
