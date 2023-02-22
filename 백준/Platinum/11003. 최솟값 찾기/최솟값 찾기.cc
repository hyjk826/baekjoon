// 2022-07-28
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

class SegTree{
    public:
        SegTree(vi v){
            vec = v;
            seg.resize(4 * (int)vec.size());
            init(1, 0, (int)vec.size() - 1);
        }
        void init(int node, int start, int end) {  
            if (start == end){
                seg[node] = vec[start];
                return;
            }
            int mid = (start + end) / 2;
            init(node * 2, start, mid);
            init(node * 2 + 1, mid + 1, end);
            seg[node] = min(seg[node *2], seg[node * 2 + 1]);
        }

        int f(int node, int sumFrom, int sumTo, int start, int end) {
            if (start > sumTo || end < sumFrom) return MAX;
            if (sumFrom <= start && end <= sumTo) return seg[node];
            int mid = (start + end) / 2;
            return min(f(node * 2, sumFrom, sumTo, start, mid), f(node * 2 + 1, sumFrom, sumTo, mid + 1, end));
        }
    private:
        vi vec;
        vi seg;
};

int main() {
	fastio;
    int n, k;
    cin >> n >> k;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    SegTree seg(vec);
    for(int i{0}; i < n; ++i){
        cout << seg.f(1, max(0, i - k + 1), i, 0, n - 1) << " ";
    }
}

