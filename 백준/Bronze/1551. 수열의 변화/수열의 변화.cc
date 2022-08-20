// 2022-08-21
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
	int n, k;
    cin >> n >> k;
    vi vec;
    string str;
    cin >> str;
    str += ',';
    string s;
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == ','){
            vec.push_back(stoi(s));
            s.clear();
        }
        else s += str[i];
    }
    for(int i{0}; i < k; ++i){
        vi A;
        for(int j{0}; j < (int)vec.size() - 1; ++j){
            A.push_back(vec[j + 1] - vec[j]);
        }
        vec = A;
    }
    for(int i{0}; i < (int)vec.size(); ++i){
        cout << vec[i];
        if(i < (int)vec.size() - 1) cout << ",";
    }
}