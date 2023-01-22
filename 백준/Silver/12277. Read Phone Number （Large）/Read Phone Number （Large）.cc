// 2023-01-22
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
    string s, t;
    cin >> s >> t;
    t += '-';
    vi A;
    string str;
    for(int i{0}; i < (int)t.size(); ++i){
        if(t[i] == '-') {
            A.push_back(stoi(str));
            str.clear();
        }
        else{
            str += t[i];
        }
    }
    int sum{0};
    vs ss = {"double", "triple", "quadruple", "quintuple", "sextuple", "septuple", "octuple", "nonuple", "decuple"};
    vs num = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int cnt{0};
    for(int i{0}; i < (int)A.size(); ++i){
        str = s.substr(sum, A[i]);
        vp B;
        B.push_back({str[0] - '0', 1});
        for(int j{1}; j < (int)str.size(); ++j){
            if(str[j] - '0'== B.back().first) B.back().second++;
            else B.push_back({str[j] - '0', 1});
        }
        for(int j{0}; j < (int)B.size(); ++j){
            if(B[j].second == 1) cout << num[B[j].first] << " ";
            else{
                if(B[j].second > 10){
                    for(int k{0}; k < B[j].second; ++k){
                        cout << num[B[j].first] << " ";
                    }
                }
                else{
                    cout << ss[B[j].second - 2] << " " << num[B[j].first] << " ";
                }
            }
        }
        sum += A[i];   
    }
    cout << "\n";
}

int main() {
	fastio;	
	int t;
    cin >> t;
    for(int T{1}; T <= t; ++T){
        cout << "Case #" << T << ": ";
        solve();
    }
}
	
