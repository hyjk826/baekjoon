// 2022-12-18
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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
	fastio;
	int t;
    cin >> t;
    string str;
    getline(cin, str);
    while(t--){
        getline(cin, str);
        stringstream ss;
        ss.str(str);
        string t;
        vi vec;
        while(ss >> t){
            vec.push_back(stoi(t));
        }
        int ans{0};
        for(int i{0}; i < (int)vec.size(); ++i){
            for(int j{i + 1}; j < (int)vec.size(); ++j){
                ans = max(ans, gcd(vec[i], vec[j]));
            }
        }
        cout << ans << "\n";
    }
}
	
