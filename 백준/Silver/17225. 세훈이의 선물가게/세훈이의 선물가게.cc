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
    int a, b, n;
    cin >> a >> b >> n;
    vp tt;
    for(int i{0}; i < n; ++i){
        int t, c;
        char color;
        cin >> t >> color >> c;
        int cc{0};
        if(color == 'R') cc = 1;
        for(int j{0}; j < c; ++j){
            tt.push_back({t + j * a, cc});
        }
    }
    sort(tt.begin(), tt.end());
    vi A, B;
    for(int i{0}; i < (int)tt.size(); ++i){
        if(tt[i].second == 0) A.push_back(i + 1);
        else B.push_back(i + 1);
    }
    cout << A.size() << "\n";
    for(auto& i : A) cout << i << " ";
    cout << "\n";
    cout << B.size() << "\n";
    for(auto& i : B) cout << i << " ";
}
