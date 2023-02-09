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

int main(){
	fastio;
    string s, t;
    cin >> s >> t;
    int a{0}, b{0};
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int sc = stoi(s.substr(6, 2));
    a = h * 3600 + m * 60 + sc;
    h = stoi(t.substr(0, 2));
    m = stoi(t.substr(3, 2));
    sc = stoi(t.substr(6, 2));
    b = h * 3600 + m * 60 + sc;
    if(a == b){
        cout << "24:00:00"; return 0;
    }
    int c = (b - a + (3600 * 24)) % (3600 * 24);
    h = c / 3600;
    c %= 3600;
    m = c / 60;
    c %= 60;
    if(h < 10) cout << 0;
    cout << h;
    cout << ":";
    if(m < 10) cout << 0;
    cout << m;
    cout << ":";
    if(c < 10) cout << 0;
    cout << c;
}
