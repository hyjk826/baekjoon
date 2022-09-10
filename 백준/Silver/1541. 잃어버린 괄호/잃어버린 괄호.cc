// 2022-09-10
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
    string str;
    cin >> str;
    vi A;
    vc B;
    string s;
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == '+' || str[i] == '-'){
            A.push_back(stoi(s));
            s.clear();
            B.push_back(str[i]);
        }
        else s += str[i];
        if(i == (int)str.size() - 1){
            A.push_back(stoi(s));
        }
    }
    vi vec;
    vec.push_back(A.front());
    for(int i{0}; i < (int)B.size(); ++i){
        if(B[i] == '+'){
            vec.back() += A[i + 1];
        }
        else{
            vec.push_back(A[i + 1]);
        }
    }
    int ans = vec.front();
    for(int i{1}; i < (int)vec.size(); ++i){
        ans -= vec[i];
    }
    cout << ans;
}