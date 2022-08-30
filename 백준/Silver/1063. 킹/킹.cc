// 2022-08-30
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
    int x1, y1, x2, y2, n;
    string s, t;
    cin >> s >> t >> n;
    x1 = s[0] - 'A';
    y1 = s[1] - '1';
    x2 = t[0] - 'A';
    y2 = t[1] - '1';
    int yy[]{0, 0, -1, 1, 1, 1, -1, -1};
    int xx[]{1, -1, 0, 0, 1, -1, 1, -1};
    vs vec = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        int index = find(vec.begin(), vec.end(), str) - vec.begin();
        x1 += xx[index];
        y1 += yy[index];
        if(x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7){
            x1 -= xx[index];
            y1 -= yy[index];
        }
        else if(x1 == x2 && y1 == y2){
            x2 += xx[index];
            y2 += yy[index];
            if(x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7){
                x1 -= xx[index];
                y1 -= yy[index];
                x2 -= xx[index];
                y2 -= yy[index];
            }
        }
    }
    cout << char(x1 + 'A') << y1 + 1 << "\n" << char(x2 + 'A') << y2 + 1 << "\n";
}

