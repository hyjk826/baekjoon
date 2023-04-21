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
    string s, t;
    cin >> s >> t;
    
    int l{-1}, r{(int)t.size()};
    string a, b;
    while(r != l + 1){
        while(l + 1 < r){
            a += t[l + 1];
            l++;
            if(a.size() >= (int)s.size() && a.back() == s.back() && a.substr((int)a.size() - (int)s.size(), (int)s.size()) == s){
                for(int i{0}; i < (int)s.size(); ++i){
                    a.pop_back();
                }
                break;
            }
        }
        while(r - 1 > l){
            b += t[r - 1];
            r--;
            if(b.size() >= (int)s.size() && b.back() == s.front()){
                string k = b.substr((int)b.size() - (int)s.size(), (int)s.size());
                reverse(k.begin(), k.end());
                if(k == s){
                    for(int i{0}; i < (int)s.size(); ++i){
                        b.pop_back();
                    }
                    break;
                }                
            }
        }
    }
    while(!b.empty()){
        a += b.back();
        b.pop_back();
        if(a.size() >= (int)s.size() && a.back() == s.back() && a.substr((int)a.size() - (int)s.size(), (int)s.size()) == s){
            for(int i{0}; i < (int)s.size(); ++i){
                a.pop_back();
            }
        }
    }
    cout << a;
}
