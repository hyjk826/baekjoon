// 2022-09-09
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
    deque<int> dQ;
    for(int i{0}; i < n; ++i){
        string str;
        int a;
        cin >> str;
        if(str == "push_front"){
            cin >> a;
            dQ.push_front(a);
        }
        else if(str == "push_back"){
            cin >> a;
            dQ.push_back(a);
        }
        else if(str == "pop_front"){
            if(dQ.empty()) cout << -1 << "\n";
            else{
                cout << dQ.front() << "\n";
                dQ.pop_front();
            }
        }
        else if(str == "pop_back"){
            if(dQ.empty()) cout << -1 << "\n";
            else{
                cout << dQ.back() << "\n";
                dQ.pop_back();
            }
        }
        else if(str == "size"){
            cout << dQ.size() << "\n";
        }
        else if(str == "empty"){
            if(dQ.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(str == "front"){
            if(dQ.empty()) cout << -1 << "\n";
            else cout << dQ.front() << "\n";
        }
        else if(str == "back"){
            if(dQ.empty()) cout << -1 << "\n";
            else cout << dQ.back() << "\n";
        }
    }
}