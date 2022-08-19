// 2022-08-19
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
    string str;
    cin >> str;
    vs vec;
    for(int i{0}; i < (int)str.size(); ++i){
        for(int j{i + 2}; j < (int)str.size(); ++j){
            string c = str;
            reverse(c.begin(), c.begin() + i + 1);
            reverse(c.begin() + i + 1, c.begin() + j);
            reverse(c.begin() + j, c.end());
            vec.push_back(c);
        }
    }
    sort(vec.begin(), vec.end());
    cout << vec[0];
}