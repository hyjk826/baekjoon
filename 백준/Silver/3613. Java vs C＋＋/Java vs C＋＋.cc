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
    bool flag = true;
    bool ok1, ok2;
    ok1 = ok2 = false;
    string str;
    cin >> str;
    if(str.front() == '_' || str.back() == '_' || isupper(str[0])){
        flag = false;
    }
    for(int i{0}; i < (int)str.size(); ++i){
        if(i && str[i] == '_' && str[i - 1] == '_') flag = false;
        if(str[i] == '_') ok1 = true;
        if('A' <= str[i] && str[i] <= 'Z') ok2 = true;
    }
    if(!flag || (ok1 && ok2)) cout << "Error!";
    else{
        if(ok1){
            for(int i{0}; i < (int)str.size(); ++i){
                if(str[i] == '_') str[i + 1] = toupper(str[i + 1]);
            }
            for(int i{0}; i < (int)str.size(); ++i){
                if(str[i]== '_') continue;
                cout << str[i];
            }
        }
        else if(ok2){
            for(int i{0}; i < (int)str.size(); ++i){
                if('A' <= str[i] && str[i] <= 'Z'){
                    cout << "_";
                    str[i] = tolower(str[i]);
                }
                cout << str[i];
            }
        }
        else cout << str;
    }
}
