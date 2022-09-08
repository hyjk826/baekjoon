// 2022-09-08
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
    string str;
    cin >> str;
    vp vec;
    vec.push_back({str[0] - 'A', 1});
    for(int i{1}; i < (int)str.size(); ++i){
        if(vec.back().first == str[i] - 'A') vec.back().second++;
        else vec.push_back({str[i] - 'A', 1});
    }
    int ans{MAX};
    int a{0}, b{0};
    for(int i{0}; i < (int)vec.size() - 1; ++i){
        if(i & 1) a += vec[i].second;
        else b += vec[i].second;
    }
    ans = min(ans, a);
    ans = min(ans, b);
    a = b = 0;
    for(int i{1}; i < (int)vec.size(); ++i){
        if(i & 1) a+= vec[i].second;
        else b += vec[i].second;
    }
    ans = min(ans, a);
    ans = min(ans, b);
    cout << ans;
}
	

