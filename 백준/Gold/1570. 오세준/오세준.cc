// 2022-08-16
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
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2 || y1 > y2) cout << "-1";
    else {
        int R = x2 - x1;
        int U = y2 - y1;
        int q = (R + U) / n;
        vector<string> vec;
        for(int i{n}; i >= 0; --i){
            int a{i}, b{n - i};
            string ans;
            if(a * q <= R && b * q <= U && a >= R - a * q && b >= U - b * q){
                ans += string(R - a * q, 'R');
                ans += string(U - b * q, 'U');
                ans += string(a - (R - a * q), 'R');
                ans += string(b - (U - b * q), 'U');
                vec.push_back(ans);
            }
        }
        sort(vec.begin(), vec.end());
        if(vec.size() == 0) cout << -1;
        else cout << vec[0];
    }
}

