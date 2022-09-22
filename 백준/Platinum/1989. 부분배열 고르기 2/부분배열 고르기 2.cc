// 2022-09-22
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

vl vec(1000000);
vl preSum(1000000);
vector<int> minIndexSeg(4000001);
int n;

int init(int node, int s, int e) {
	if (s == e) return minIndexSeg[node] = s;
	int m = (s + e) / 2;
	int l = init(node * 2, s, m);
	int r = init(node * 2 + 1, m + 1, e);
	if (vec[l] <= vec[r]) return minIndexSeg[node] = l;
	else return minIndexSeg[node] = r;
}

int idx(int node, int s, int e, int l, int r) {
	if (r < s || l > e) return -1;
	if (l <= s && e <= r) return minIndexSeg[node];
	int m{ (s + e) / 2 };
	int a{ idx(node * 2, s, m, l, r) };
	int b{ idx(node * 2 + 1, m + 1, e, l, r) };
	if (a == -1) return b;
	if (b == -1) return a;
	if (vec[a] <= vec[b]) return a;
	else return b;
}

ll sum(int l, int r){
    if(l == 0) return preSum[r];
    else return preSum[r] - preSum[l - 1];
}
int a, b;
ll mx{0};

void f(int l, int r){
    if(l > r) return;
    int index = idx(1, 0, n - 1, l, r);
    if(mx < 1LL * sum(l, r) * vec[index]){
        mx = 1LL * sum(l, r) * vec[index];
        a = l;
        b = r;
    }
    f(l, index - 1);
    f(index + 1, r);
}

int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        preSum[i] = vec[i];
    }
    for(int i{1}; i < n; ++i){
        preSum[i] += preSum[i - 1];
    }
    init(1, 0, n - 1);
    f(0, n - 1);
    cout << mx << "\n";
    cout << a + 1 << " " << b + 1;
}
	

