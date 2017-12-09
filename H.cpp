//Not Complited Yet
#include <bits/stdc++.h>
using namespace std;
const int SIZE = 50001;
bool visited[SIZE];
vector<int> SCC_Graph[SIZE];
vector<int> ListOfEachSCC[SIZE];
int SCC_List[SIZE];

void TopolSort(vector<int> g[],int u, stack<int>& ans){
    if(visited[u]){
        return;
    }
    visited[u] = true;
    for(int i = 0 ; i < g[u].size() ; i++){
        TopolSort(g,g[u][i],ans);
    }
    ans.push(u);
}

void DFSR(vector<int> g[],int u, int counter){
    if(visited[u]){
        return;
    }
    visited[u] = true;
    for(int i = 0 ; i < g[u].size() ; i++){
        DFSR(g,g[u][i], counter);
    }
    ListOfEachSCC[counter].push_back(u);
    SCC_List[u] = counter;
}

int SCC(vector<int> graph[], vector<int> graph_reverce[],int v){
    fill(visited, visited+v, false);
    for(int i = 0 ; i < v ; i++){
        SCC_Graph[i].clear();
        ListOfEachSCC[i].clear();
        SCC_List[i] = 0;
    }
    stack<int> TopolSorted;
    for(int i = 0 ; i < v ; i++){
        if(visited[i]){
            continue;
        }
        TopolSort(graph,i, TopolSorted);
    }
    fill(visited, visited+v, false);
    fill(SCC_List, SCC_List+v, 0);
    int counter = 0;
    while(!TopolSorted.empty()){
        int u = TopolSorted.top();
        TopolSorted.pop();
        if(visited[u]){
            continue;
        }
        DFSR(graph_reverce, u, counter);
        counter++;
    }
    for(int i = 0 ; i < counter ; i++){
        for(int j = 0 ; j < ListOfEachSCC[i].size() ; j++){
            int u = ListOfEachSCC[i][j];
            for(int k = 0 ; k < graph[u].size() ; k++){
                int w = graph[u][k];
                if(SCC_List[u] != SCC_List[w]){
                    SCC_Graph[SCC_List[u]].push_back(SCC_List[w]);
                }
            }
        }
    }
    return counter;
}
int DFS(int u){
    if(visited[u]){
        return 0;
    }
    visited[u] = true;
    int ans = ListOfEachSCC[u].size();
    for(int i = 0 ; i < SCC_Graph[u].size() ; i++){
        ans += DFS(SCC_Graph[u][i]);
    }
    return ans;
}

void fun(int cu, vector<int> v[], int n);
int main(){
    while(true){
        int n, m;cin>>n>>m;
        if(n == 0 and m==0 ){
            break;
        }
        vector<int> graph[SIZE];
        vector<int> graphr[SIZE];
        for(int i = 0 ; i < m ; i++){
            int a, b;cin>>a>>b;
            a--;b--;
            graph[a].push_back(b);
            graphr[b].push_back(a);
        }
        int cu = SCC(graph, graphr, n);
        //fun(cu, graph, n);
        int ans = 0;
        bool f=false;
        for(int i = 0 ;i < cu ; i++){
            int tmp = 0;
            if(ListOfEachSCC[i].size() <= 1){
                continue;
            }
            fill(visited, visited+501, false);
            tmp = DFS(i) - ListOfEachSCC[i].size();
            //cout<<"ops"<<tmp;
            for(int j = 0 ; j < ListOfEachSCC[i].size() ; j++){
                int counter = 0;
                int v = ListOfEachSCC[i][j];
                for(int k = 0 ; k < graph[v].size() ; k++){
                    if(SCC_List[graph[v][k]] == SCC_List[v]){
                        counter++;
                    }
                }
                if(counter > 1){
                    //cout<<"counter: "<<counter<<endl;
                    f = true;
                    break;
                }
            }
            if(f){
                
                f = false;
                tmp+=ListOfEachSCC[i].size();
            }
            ans = max(ans, tmp);
        }
        cout<<ans<<endl;
    }
    return 0;
}















void fun (int cu, vector<int> v[], int n){
    cout<<"Graph is: \n";
    for(int i = 0 ; i < n ;i++){
        cout<<i<<" :";
        for(int j = 0 ; j < v[i].size() ; j++){
            cout<<" "<<v[i][j];
        }
        cout<<endl;
    }
    cout<<"----------------\n";
    cout<<"SCC Graph is: \n";
    for(int i = 0 ; i < cu ; i++){
        cout<<i<<": ";
        for(int j = 0 ; j < SCC_Graph[i].size() ; j++){
            cout<<SCC_Graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------\n";
    cout<<"List of Each SCC is : \n";
    for(int i = 0 ; i < cu; i++){
        cout<<i<<": ";
        for(int j = 0 ; j < ListOfEachSCC[i].size() ; j++){
            cout<<ListOfEachSCC[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"------------------\n";
        //-------------------

}