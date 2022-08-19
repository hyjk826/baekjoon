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
	int n;
    cin >> n;
    vs ans;
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        str += 'a';
        string s;
        for(int j{0}; j < (int)str.size(); ++j){
            if('a' <= str[j] && str[j] <= 'z'){
                if(s.size() == 0) continue;
                ans.push_back(s);
                s.clear();
            }
            else s += str[j];
        }
    }
    for(auto& i : ans){
        while(i.size() >= 2 && i[0] == '0') i.erase(i.begin());
    }
    sort(ans.begin(), ans.end(), [&](string a, string b){
        if(a.size() == b.size()) return a < b;
        else return a.size() < b.size();
    });
    for(auto& i : ans) cout << i << "\n";
}