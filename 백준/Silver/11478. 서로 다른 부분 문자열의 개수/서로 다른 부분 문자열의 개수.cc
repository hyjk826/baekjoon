// 2022-05-31
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	string str;
    cin >> str;
    set<string> s;
    for(int i{0}; i < (int)str.size(); ++i){
        string t;
        for(int j{i}; j < (int)str.size(); ++j){
            t += str[j];
            s.insert(t);
        }
    }
    cout << s.size();
}