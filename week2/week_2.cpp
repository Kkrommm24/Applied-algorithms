#include <bits/stdc++.h> 
#define pii pair<int, int>
using namespace std;
// int main() 
// { 
//     stack<int> S;
//     for(int i = 1; i <= 5; i++){
//         S.push(i);
//         cout << "PUSH " <<  i << endl;
//     }
//     while(!S.empty()){
//         int e = S.top();
//         S.pop();
//         cout << "POP " << e << endl;
//     }

//     //demo queue
//     queue<int> Q;
//     for(int e = 1; e <= 5; e++){
//         Q.push(e);
//         cout << "QUEUE PUSH " <<  e << endl;
//     }
//     while(!Q.empty()){
//         int e = Q.front();
//         Q.pop();
//         cout << "QUEUE POP " << e << endl;
//     }
//     return 0;
// }

void demomap(){
    map<string, int> M;
    M["abc"] = 1;
    M["def"] = 2;
    M["xyzt"] = 10;

    string k = "abc";
    cout << "value of key " << k << " = " << M[k] << endl;
    for(map<string, int>::iterator p = M.begin(); p != M.end(); p++){
        cout << p->first << " is mapped to value "<< p->second << endl;
    }
}

// void demo_priorityqueue(){
//     priority_queue<int> pq;
//     pq.push(5);
//     pq.push(1);
//     pq.push(100);
//     pq.push(30);
//     pq.push(25);
//     while(!pq.empty()){
//         int e = pq.top(); pq.pop();
//         cout << "pq.pop: " << e << endl;
//     }

//     priority_queue<pii, vector<pii>, greater<pii> > PQ;
//     PQ.push(make_pair(4, 40));
//     PQ.push(make_pair(1, 10));
//     PQ.push(make_pair(9, 900));
//     while(!PQ.empty()){
//         pii e = PQ.top(); PQ.pop();
//         cout << "PQ.pop: (" << e.first << ", " << e.second << ")" << endl;
//     }
// }

int main(){
    //demomap();
    // demo_priorityqueue();
    freopen("text.txt", "r", stdin);
    char word[100]; int n = 0;
    while(!feof(stdin)){
        char c = fgetc(stdin);
        if(c <= 'z' && c >= 'a' || '0' <= c && '9' >= c){
            n++;
            word[n-1] = c;
        }else{
            word[n] = '\0';
            cout << word << endl;
            n = 0;
        }
    }
    
    
    return 0;
}