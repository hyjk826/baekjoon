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
    double score[] = {4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0};
    string degree[] = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};
    double ans{0};
    double cnt{0};
    for(int i{0}; i < 20; ++i){
        string str; double a; string b;
        cin >> str >> a >> b;
        if(b == "P") continue;
        int idx{-1};
        for(int j{0}; j < 9; ++j){
            if(b == degree[j]) idx = j;
        }
        ans += score[idx] * a;
        cnt += a;
    }
    cout << fixed << setprecision(20);
    cout << ans / cnt;
}
