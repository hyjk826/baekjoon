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

int ch[4][4][4];

void solve(){
    int n, m;
    cin >> n >> m;
    vs subject = {"-", "kor", "eng", "math"};
    vs fruit = {"-", "apple", "pear", "orange"};
    vs color = {"-", "red", "blue", "green"};
    for(int i{0}; i < n; ++i){
        string a, b, c;
        cin >> a >> b >> c;
        int x = find(subject.begin(), subject.end(), a) - subject.begin();
        int y = find(fruit.begin(), fruit.end(), b) - fruit.begin();
        int z = find(color.begin(), color.end(), c) - color.begin();
        ch[x][y][z]++;
        ch[0][0][0]++;
        ch[x][0][0]++;
        ch[0][y][0]++;
        ch[0][0][z]++;
        ch[x][y][0]++;
        ch[0][y][z]++;
        ch[x][0][z]++;
    }
    for(int i{0}; i < m; ++i){
        string a, b, c;
        cin >> a >> b >> c;
        int x{0}, y{0}, z{0};
        x = find(subject.begin(), subject.end(), a) - subject.begin();
        y = find(fruit.begin(), fruit.end(), b) - fruit.begin();
        z = find(color.begin(), color.end(), c) - color.begin();
        cout << ch[x][y][z] << "\n";
    }
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
