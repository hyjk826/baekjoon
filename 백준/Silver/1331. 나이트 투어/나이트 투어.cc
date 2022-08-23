// 2022-08-23
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
    vector<vi> ch(6, vi(6));
    int px, py;
    px = py = -1;
    int a, b;
    for(int i{0}; i < 36; ++i){
        string str;
        cin >> str;
        int x = str[0] - 'A';
        int y = str[1] - '1';
        if(i == 0){
            a = x;
            b = y;
        }
        if(px == -1 && py == -1){
            px = x;
            py = y;
            ch[x][y] = 1;
            continue;
        }
        if(abs(px - x) == 1 && abs(py - y) == 2 && ch[x][y] == 0){
            px = x;
            py = y;
            ch[x][y] = 1;
            continue;
        }
        if(abs(px - x) == 2 && abs(py - y) == 1 && ch[x][y] == 0){
            px = x;
            py = y;
            ch[x][y] = 1;
            continue;
        }
        cout << "Invalid";
        return 0;
    }
    if((abs(a - px) == 1 && abs(b - py) == 2) || (abs(a - px) == 2 && abs(b - py) == 1)) cout << "Valid";
    else cout << "Invalid";    
}

