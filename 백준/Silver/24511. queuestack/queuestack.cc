// 2022-09-17
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

int main() {
	fastio;
    int n;
    cin >> n;
    vi ch(n);
    for(int i{0}; i < n; ++i) cin >> ch[i];
    deque<int> dQ;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(ch[i] == 0) dQ.push_back(a);
    }
	int m;
    cin >> m;
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        dQ.push_front(a);
        cout << dQ.back() << " ";
        dQ.pop_back();
    }
}
	

