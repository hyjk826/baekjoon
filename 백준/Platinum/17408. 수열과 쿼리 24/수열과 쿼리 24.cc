// 2022-07-17
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

class SegTree{
    public:
        SegTree(vl v){
            vec = v;
            seg.resize(4 * (int)vec.size());
            init(1, 0, (int)vec.size() - 1);
        }
        pl init(int node, int start, int end) {  
            if (start == end) return seg[node] = {-1, vec[start]};
            int mid = (start + end) / 2;
            pl a = init(node * 2, start, mid);
            pl b = init(node * 2 + 1, mid + 1, end);
            vl v;
            v.push_back(a.first);
            v.push_back(a.second);
            v.push_back(b.first);
            v.push_back(b.second);
            sort(v.begin(), v.end(), greater<ll>());
            return seg[node] = {v[0], v[1]};
        }

        pl f(int node, int sumFrom, int sumTo, int start, int end) {
            if (start > sumTo || end < sumFrom) return {-1, -1};
            if (sumFrom <= start && end <= sumTo) return seg[node];
            int mid = (start + end) / 2;
            pl a = f(node * 2, sumFrom, sumTo, start, mid);
            pl b = f(node * 2 + 1, sumFrom, sumTo, mid + 1, end);
            vl v;
            v.push_back(a.first);
            v.push_back(a.second);
            v.push_back(b.first);
            v.push_back(b.second);
            sort(v.begin(), v.end(), greater<ll>());
            return {v[0], v[1]};
        }

        pl update(int node, int start, int end, int index, ll newValue) {
            if (start > index || end < index) return {-1, -1};
            if (start == end) return seg[node] = {-1, newValue};
            int mid = (start + end) / 2;
            update(node * 2, start, mid, index, newValue);
            update(node * 2 + 1, mid + 1, end, index, newValue); 
            vl v;
            v.push_back(seg[node*2].first);
            v.push_back(seg[node*2].second);
            v.push_back(seg[node*2 + 1].first);
            v.push_back(seg[node*2 + 1].second);
            sort(v.begin(), v.end(), greater<ll>());
            return seg[node] = {v[0], v[1]};
        }
        pl ff(){
            for(int i{1}; i <= 9; ++i){
                cout << seg[i].first << " " << seg[i].second << "\n";
            }
        }
    private:
        vl vec;
        vector<pl> seg;
};

int main() {
	fastio;
    int n;
    cin >> n;
    vl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    SegTree seg(vec);
    int m;
    cin >> m;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            b--;
            seg.update(1, 0, n - 1, b, c);
        }
        else{
            b--;
            c--;
            pl k = seg.f(1, b, c, 0, n - 1);
            cout << k.first + k.second << "\n";
        }
    }
}
