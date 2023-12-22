#include <bits/stdc++.h> 
using namespace std;
#define N 100001
int a[N];
int DB[N];
vector<int> deleteMaxResults;
int n;
int dbSize = 0;
void input(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        DB[++dbSize] = a[i];
    }
    for (int i = 1; i <= dbSize; i++) {
        cout << DB[i] << " ";
    }
    cout << endl;
}
int main() 
{ 
    input();
    
    while (true){
        string cmd; cin >> cmd;
        if(cmd == "*"){
            for (int i = 0; i < deleteMaxResults.size(); i++) {
                cout << deleteMaxResults[i] << endl;
            }
            break;
        } 
        else if(cmd == "insert"){
            int k; cin >> k;
            DB[++dbSize] = k;
        }else if(cmd == "delete-max"){
            int tmp = 0;
            for (int i = 1; i <= dbSize; i++) {
                if(DB[i] >= tmp) tmp = DB[i];
            }
            for (int i = 1; i <= dbSize; i++) {
                if (DB[i] == tmp) {
                    for (int j = i; j < dbSize; j++) {
                        DB[j] = DB[j + 1];
                    }
                    dbSize--;
                    break;
                }
            }
            deleteMaxResults.push_back(tmp);
        }
    }
    
    return 0;
}
