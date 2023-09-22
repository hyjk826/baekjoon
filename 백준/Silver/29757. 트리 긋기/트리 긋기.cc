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
    int x, y, idx;
};

void solve(){
	int n;
    cin >> n;
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].x >> vec[i].y;
        vec[i].idx = i;
    }
    sort(vec.begin(), vec.end(), [&](st& a, st& b){
        if(a.x != b.x) return a.x < b.x;
        else return a.y < b.y;
    }); 
    for(int i{1}; i < n; ++i){
        cout << vec[i - 1].idx + 1 << " " << vec[i].idx + 1 << "\n";
    }
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
