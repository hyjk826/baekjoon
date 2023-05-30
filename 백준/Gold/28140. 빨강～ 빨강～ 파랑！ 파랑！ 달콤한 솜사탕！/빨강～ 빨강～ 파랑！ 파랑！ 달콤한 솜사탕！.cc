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

int main(){
	fastio;
	int n, q;
	cin >> n >> q;
	string str;
	cin >> str;
	vi A, B;
	for(int i{0}; i < n; ++i){
		if(str[i] == 'R') A.push_back(i);
	}
	for(int i{n - 1}; i >= 0; --i){
		if(str[i] == 'B') B.push_back(n - 1 - i);
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		auto it = lower_bound(A.begin(), A.end(), l);
		if(it == A.end()){
			cout << -1 << "\n"; continue;
		}
		int a = *it;
		it++;
		if(it == A.end() || *it >= r - 1){
			cout << -1 << "\n"; continue;
		}
		int b = *it;
		r = (n - 1 - r);
		it = lower_bound(B.begin(), B.end(), r);
		if(it == B.end() || b >= n - 1 - *it){
			cout << -1 << "\n"; continue;
		}
		int c = *it;
		it++;
		if(it == B.end() || b >= n - 1 - *it){
			cout << -1 << "\n"; continue;
		}
		int d = *it;
		cout << a << " " << b << " " << n - 1 - d << " " << n - 1 - c << "\n";
	}
}
