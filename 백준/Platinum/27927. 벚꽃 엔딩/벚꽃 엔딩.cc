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

struct SparseTable{
	vector<vi> lookup;
	SparseTable(vi& arr){
		lookup.resize((int)arr.size(), vi(20));
		int n = (int)arr.size();
		for (int i = 0; i < n; i++)
			lookup[i][0] = arr[i];
		for (int j = 1; (1 << j) <= n; j++) {
			for (int i = 0; (i + (1 << j) - 1) < n; i++) {
				lookup[i][j] = min(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	ll query(int L, int R){
		int j = (int)log2(R - L + 1);
		return min(lookup[L][j], lookup[R - (1 << j) + 1][j]);
	}
};

struct SparseTable2{
	vector<vi> lookup;
	SparseTable2(vi& arr){
		lookup.resize((int)arr.size(), vi(20));
		int n = (int)arr.size();
		for (int i = 0; i < n; i++)
			lookup[i][0] = arr[i];
		for (int j = 1; (1 << j) <= n; j++) {
			for (int i = 0; (i + (1 << j) - 1) < n; i++) {
				lookup[i][j] = max(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	int query(int L, int R){
		int j = (int)log2(R - L + 1);
		return max(lookup[L][j], lookup[R - (1 << j) + 1][j]);
	}
};


int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vi A(n), B(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i] >> B[i];
    }
    SparseTable2 sp1(A);
    SparseTable sp2(B);
    int a{-1}, b{0};
    int j{0};
    vp p;
    for(int i{0}; i < n; ++i){
        while(j < n && sp1.query(i, j) <= sp2.query(i, j)) j++;
        int l = sp1.query(i, j - 1);
        int r = sp2.query(i, j - 1);
        if(j - i == a) {
            p.push_back({l, r});
        }
        else if(j - i > a){
            a = j - i;
            p.clear();
            p.push_back({l, r});
        }
    }
    sort(p.begin(), p.end());
    vp p2;
    p2.push_back(p[0]);
    for(int i{1}; i < (int)p.size(); ++i){
        if(p[i].first <= p2.back().second) p2.back().second = max(p2.back().second, p[i].second);
        else p2.push_back(p[i]);
    }
    for(auto& i : p2){
        b += i.second - i.first + 1;
    }
    cout << a << " " << b;
}
