#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<int> graph[1001];
int innerdeg [1001];

void cls(){
    for(int i = 0 ; i < 1001 ; i++){
        innerdeg[i] = 0;
        graph[i].clear();
    }
}
bool mycmp( int  a , int b){
    if(innerdeg[a] == innerdeg[b]){
        return a > b;
    }
    return innerdeg[a] > innerdeg[b];
}

int main(){
    while(true){
        int n, k;cin>>n>>k;
        if(n == 0 and k == 0){
            break;
        }
        int Graph[1001][1001];
        for(int i = 0 ; i <= n ;  i ++){
            fill(Graph[i], Graph[i]+n+1, 0);
        }
        for(int j = 0 ; j < k ; j++){
            int tmp[1001];
            for(int i =0  ; i < n ; i++){
                cin>>tmp[i];
            }
            for(int i = 0 ; i < n ; i++){
                for(int k = i+1 ; k < n ; k++){
                    if(tmp[i] < tmp[k]) {
                        Graph[tmp[i]][tmp[k]] += 1;
                    }
                }
            }
        }
        cls();
        for(int i = 1 ; i <= n ; i++){
            for (int j = i; j <= n; j++) {
                if(i == j){
                    continue;
                }
                if((float)(Graph[i][j]*1.0) >= (float)((k*1.0)/2)){
                    graph[i].push_back(j);
                }
                if ( (float)(Graph[i][j]*1.0) <= (float)(k*1.0)/2){
                    graph[j].push_back(i);
                }
            }
        }
        bool f = false;
        int Index[1001];
        for(int i = 0 ; i <= n ; i++){
            Index[i] = i;
            innerdeg[i] = 0;
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j < graph[i].size() ; j++){
                innerdeg[graph[i][j]]++;
            }
        }
        sort(Index+1, Index+n+1, mycmp);
        stack<int> ans;
        for(int i= 1 ; i <= n ; i++){
            if(innerdeg[Index[i]] < n-i){
                f = true;
                break;
            }
            ans.push(Index[i]);
            for(int j = 0 ; j < graph[Index[i]].size() ; j++){
                innerdeg[graph[Index[i]][j]]--;
            }
            sort(Index+1, Index+n+1, mycmp);
        }
        if(f){
            cout<<"No solution"<<endl;
        }
        else{
            while(ans.size()>1){
                cout<<ans.top()<<" ";
                ans.pop();
            }
            cout<<ans.top()<<endl;
            ans.pop();
        }

    }
    return 0;
}
