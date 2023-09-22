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


void solve(){
	int n;
    string x;
    cin >> n >> x;
    string str;
    for(int i{0}; i < (int)x.size(); ++i){
        if(x[i] == '.') continue;
        str += x[i];
    }
    int X = stoi(str);
    int a{0};
    int b{0};
    vs sub = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};
    vi score = {450, 400, 350, 300, 250, 200, 150, 100, 0};
    for(int i{0}; i < n - 1; ++i){
        int c;
        string g; 
        cin >> c >> g;
        int idx = find(sub.begin(), sub.end(), g) - sub.begin();
        a += c;
        b += score[idx] * c;
    }
    int k;
    cin >> k;
    for(int i{(int)score.size() - 1}; i >= 0; --i){
        if((b + score[i] * k) / (a + k) > X){
            cout << sub[i] << "\n"; return;
        }
    }
    cout << "impossible\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
