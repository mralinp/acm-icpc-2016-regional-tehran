#include<bits/stdc++.h>
using namespace std;
bool mycmp(int a, int b){
    return a < b;
}
int main(){
    while(true){
        int n;cin>>n;
        if(n == 0){
            break;
        }
        int size = (1<<(n))+1;
        vector<int> arr;
        for(int i = 0 ; i < size ; i++){
            int tmp;cin>>tmp;
            arr.push_back(tmp);
        }
        sort(arr.begin(), arr.end(), mycmp);
        for(int i =0  ; i < arr.size() ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}