#include<bits/stdc++.h>
using namespace std;
map< int, int > mp;

struct canvas{
    int id;
    int one;
    int two;
    int three;
    int total;
};

bool mycmp(canvas a,canvas b){
    if(a.total == b.total){
        if(a.one == b.one){
            if(a.two == b.two){
                return a.id < b.id; 
            }
            return a.two > b.two;
        }
        return a.one > b.one;
    }
    return a.total > b.total;
}

int main(){
    while(true){
        int n;cin>>n;
        mp.clear();
        vector<canvas> ans;
        if(n == 0){
            break;
        }
        int counter = 0;
        for(int j = 0 ; j < n ; j++){
            int m;cin>>m;
            for(int i =0  ; i < m ; i++){
                int tmp;cin>>tmp;
                if(mp[tmp] == 0){
                    mp[tmp] = ++counter;
                    canvas t;
                    t.id = tmp;
                    t.one = t.two = t.three = 0;
                    ans.push_back(t);
                }
                switch(i){
                    case 0:{
                        ans[mp[tmp]-1].one++;
                    }
                    case 1:{
                        ans[mp[tmp]-1].two++;
                    }
                    case 2:{
                        ans[mp[tmp]-1].three++;
                    }
                    default:
                        break;
                }
                ans[mp[tmp]-1].total += 3-i; 
            }
        }
        sort(ans.begin(), ans.end(), mycmp);
        for(int i = 0 ; i < ans.size(); i++){
            if(i!=0){
                if(ans[i].total == ans[0].total){
                    if(ans[i].one == ans[0].one){
                        if(ans[i].two == ans[0].two){
                            cout<<" "<<ans[i].id;
                        }
                    }
                }
            }
            else{
                cout<<ans[0].id;
            }
        }
        cout<<endl;
    }
    return 0;
}