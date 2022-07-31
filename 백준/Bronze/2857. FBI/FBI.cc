// 2022-07-31
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
    vi ans;
    for(int i{0}; i < 5; ++i){
        string s;
        cin >> s;
        if(s.find("FBI") != string::npos) ans.push_back(i);
    }
    if(ans.size() == 0) cout << "HE GOT AWAY!";
    else{
        for(auto& i : ans) cout << i + 1 << " ";
    }
    
}

