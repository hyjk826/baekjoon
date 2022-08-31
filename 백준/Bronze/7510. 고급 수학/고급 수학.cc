// 2022-08-31
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
    int t;
    cin >> t;
    for(int i{0}; i < t; ++i){
        cout << "Scenario #" << i + 1 << ":\n";
        vl vec(3);
        for(int j{0}; j < 3; ++j){
            cin >> vec[j];
        }
        sort(vec.begin(), vec.end());
        if((vec[0] * vec[0] + vec[1] * vec[1] == vec[2] * vec[2]) && vec[0] + vec[1] > vec[2]) cout << "yes\n\n";
        else cout << "no\n\n";
    }
}

