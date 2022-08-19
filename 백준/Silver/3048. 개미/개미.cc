// 2022-08-19
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    set<char> A, B;
    for(auto& c : s) A.insert(c);
    for(auto& c : t) B.insert(c);
    reverse(s.begin(), s.end());
    s += t;
    int q;
    cin >> q;
    for(int i{0}; i < q; ++i){
        for(int i{0}; i < (int)s.size() - 1; ++i){
            if(A.count(s[i]) && B.count(s[i + 1])){
                swap(s[i], s[i + 1]);
                i++;
            }
        }
    }
    cout << s;
}