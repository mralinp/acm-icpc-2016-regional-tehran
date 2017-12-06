#include <bits/stdc++.h>
using namespace std;
bool fun(map<int, int> a, map<int, int> b){
    for(auto p : a){
        int tmp = p.first, cnt = p.second;
        if(tmp&1){
            if(b[tmp] != cnt){
                return false;
            }
        }
        else{
            if(!b.count(tmp) and ((tmp/2-1)%2 == 0 || !b.count(tmp/2 - 1))){
                return false;
            }
        }
    }
    return true;
}
int main(){
    while(true){
        int n, m;cin>>n>>m;
        if(n == -1 and m == -1){
            break;
        }
        map<int, int> a, b;
        for(int i = 0 ; i < n ; i++){
            int tmp;cin>>tmp;
            a[tmp]++;
        }
        for(int i = 0 ; i < m ; i++){
            int tmp;cin>>tmp;
            b[tmp]++;
        }
        bool f1 = fun(a, b);
        bool f2 = fun(b, a);
        if(f1 and f2){
            cout<<"Y"<<endl;
        }
        else{
            cout<<"N"<<endl;
        }
    }
    return 0;
}