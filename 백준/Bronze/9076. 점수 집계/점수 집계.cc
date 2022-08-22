// 2022-08-22
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
    while(t--){
        vi vec(5);
        for(int i{0}; i < 5; ++i){
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        if(vec[3] - vec[1] >= 4){
            cout << "KIN\n";
        }
        else cout << vec[1] + vec[2] + vec[3] << "\n";
    }
}

