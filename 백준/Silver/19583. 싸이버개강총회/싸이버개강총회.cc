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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

void solve(){
	string s, e, q;
    cin >> s >> e >> q;
    int ans{0};
    string str;
    getline(cin, str);
    vi A;
    A.push_back(stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2)));
    A.push_back(stoi(e.substr(0, 2)) * 60 + stoi(e.substr(3, 2)));
    A.push_back(stoi(q.substr(0, 2)) * 60 + stoi(q.substr(3, 2)));
    set<string> x, y;
    while(getline(cin, str)){        
        string s = str.substr(0, 5);
        string name = str.substr(6);
        int a = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        if(a <= A[0]) x.insert(name);
        if(A[1] <= a && a <= A[2]) y.insert(name);
    }
    for(auto& i : x){
        if(y.count(i)) ans++;
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
