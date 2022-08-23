// 2022-08-23
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    string str;
    while(cin >> str){
        if(str == "end") break;
        bool flag = false;
        string a = "aeiou";
        for(int i{0}; i < (int)a.size(); ++i){
            flag |= (str.find(a[i]) != string::npos);
        }
        vi vec;
        for(int i{0}; i < (int)str.size(); ++i){
            if(str[i] == 'a' || str[i] == 'i' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u') vec.push_back(0);
            else vec.push_back(1);
        }
        for(int i{1}; i < (int)vec.size() - 1; ++i){
            if(vec[i] == vec[i - 1] && vec[i] == vec[i + 1]){
                flag = false;
                break;
            }
        }
        for(int i{1}; i < (int)vec.size(); ++i){
            if(str[i] == str[i - 1]){
                if(str[i] == 'e' && str[i - 1] == 'e') continue;
                if(str[i] == 'o' && str[i - 1] == 'o') continue;
                flag = false;
            }
        }
        if(flag) cout << "<" << str << "> is acceptable." << "\n";
        else cout << "<" << str << "> is not acceptable." << "\n"; 
    }
}

