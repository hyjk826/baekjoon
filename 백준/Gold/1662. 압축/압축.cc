// 2023-01-18
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
    string str;
    cin >> str;
    vi vec;
    int ans{0};
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == ')'){
            int cnt{0};
            while(vec.back() != -1){
                cnt += vec.back();
                vec.pop_back();
            }
            vec.pop_back();
            int a = vec.back();
            vec.pop_back();
            vec.push_back(a * cnt);
        }
        else{
            if(i < (int)str.size() - 1 && str[i + 1] == '(') vec.push_back(str[i] - '0');
            else{
                if(str[i] == '(') vec.push_back(-1);
                else vec.push_back(1);
            }
        }
    }
    cout << accumulate(vec.begin(), vec.end(), 0);
}
