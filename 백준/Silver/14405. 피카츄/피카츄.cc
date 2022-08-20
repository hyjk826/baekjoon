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
	string str;
    cin >> str;
    bool flag = true;
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == 'p'){
            if(i >= (int)str.size() - 1|| str[i + 1] != 'i'){
                flag = false;
                break;
            }
            else i++;
        }
        else if(str[i] == 'k'){
            if(i >= (int)str.size() - 1|| str[i + 1] != 'a'){
                flag = false;
                break;
            }
            else i++;
        }
        else if(str[i] == 'c'){
                if(i >= (int)str.size() - 2|| str[i + 1] != 'h' || str[i + 2] != 'u'){
                    flag = false;
                    break;
                }
                else i += 2;
        }
        else{
            flag = false;
            break;
        }
    }
    if(flag) cout << "YES";
    else cout << "NO";
}