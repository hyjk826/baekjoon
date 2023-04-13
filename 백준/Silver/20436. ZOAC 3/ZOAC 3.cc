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
    vs vec;
    vec.push_back("qwertyuiop");
    vec.push_back("asdfghjkl");
    vec.push_back("zxcvbnm");
    function<pi(char)> f = [&](char c){
        for(int i{0}; i < 3; ++i){
            for(int j{0}; j < (int)vec[i].size(); ++j){
                if(vec[i][j] == c){
                    return make_pair(i, j);
                }
            }
        }
    };
    char a, b;
    cin >> a >> b;
    pi s = f(a);
    pi t = f(b);
    string str;
    cin >> str;
    int ans{0};
    vi arr = {4, 4, 3};
    for(int i{0}; i < (int)str.size(); ++i){
        pi q = f(str[i]);
        if(q.second <= arr[q.first]){
            ans += abs(s.first - q.first) + abs(s.second - q.second);
            s = q;
        }
        else{
            ans += abs(t.first - q.first) + abs(t.second - q.second);
            t = q;
        }
    }
    cout << ans + str.size();
}
