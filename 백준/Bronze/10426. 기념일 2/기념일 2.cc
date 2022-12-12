// 2022-12-12
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
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vi day = {31,28,31,30,31,30,31,31,30,31,30,31};

bool yun(int y){
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}


void next(int& y, int& m, int& d){
    if(m == 2){
        if(yun(y)) day[1] = 29;
        else day[1] = 28;
    }
    if(d == day[m - 1]){
        d = 1;
        if(m == 12){
            y++;
            m = 1;
        }
        else m++;
    }
    else d++;
}

int main() {
	fastio;
    string str; int k;
    cin >> str >> k;
    int y = stoi(str.substr(0, 4));
    int m = stoi(str.substr(5, 2));
    int d = stoi(str.substr(8, 2));
    for(int i{0}; i < k - 1; ++i){
        next(y, m, d);
    }
    cout << y << "-";
    if(m < 10) cout << 0;
    cout << m << "-";
    if(d < 10) cout << 0;
    cout << d;
}
	
