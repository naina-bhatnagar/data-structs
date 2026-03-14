#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> arr = {{0,1,0},{0,0,0},{0,1,0}};
    stack <int> s;
    int n = arr.size(), ans = 0;
    for(int i=n-1; i>=0; i--){
        s.push(i);
    }
    while(!s.empty()){
        int a = s.top(); s.pop();
        if(s.empty()) {ans = a; break;}
        int b = s.top(); s.pop();
        if(arr[a][b] == 1 && arr[b][a] == 0 ) s.push(b);
        else if(arr[a][b] == 0 && arr[b][a] == 1 ) s.push(a);
    }

    for(int i=0;i<n;i++){
        if(i == ans ) continue;
        if( arr[ans][i] == 1 || arr[i][ans] == 0 ){
            ans = -1;
            break;
        }
    }

    cout<<ans<<endl;
    return 0;
}