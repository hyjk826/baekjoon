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

struct st{
    int age, order;
    string name;
};

int main(){
    fastio;
    int n;
    cin >> n;
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].age >> vec[i].name;
        vec[i].order = i;
    }
    sort(vec.begin(), vec.end(), [&](st a, st b){
        if(a.age == b.age){
            return a.order < b.order;
        }
        else return a.age < b.age;
    });
    for(auto& i : vec){
        cout << i.age << " " << i.name << "\n";
    }
}