// 2022-09-05
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

struct st{
    int a, b, c;
};

int main() {
	fastio;
    int n, c;
    cin >> n >> c;
    map<int, pi> mp;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        int sz = mp.size();
        if(mp.count(a)) mp[a].first++;
        else mp[a] = {1, sz};
    }    
    vector<st> vec;
    for(auto& i : mp){
        vec.push_back({i.first, i.second.first, i.second.second});
    }
    sort(vec.begin(), vec.end(), [&](st x, st y){
        if(x.b == y.b){
            return x.c < y.c;
        }
        else return x.b > y.b;
    });
    for(auto& i : vec){
        for(int j{0}; j < i.b; ++j){
            cout << i.a << " ";
        }
    }
}
	

