// 2022-09-01
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
    vi vec(3);
    for(int i{0}; i < 3; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    if(vec[1] - vec[0] == vec[2] - vec[1]) cout << vec[2] + vec[1] - vec[0];
    else{
        if(vec[1] - vec[0] == (vec[2] - vec[1]) * 2){
            cout << vec[0] + vec[2] - vec[1];
        }
        else cout << vec[1] + vec[1] - vec[0];
    }
}

