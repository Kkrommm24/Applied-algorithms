#include <bits/stdc++.h> 

using namespace std;

int main() 
{ 
    queue<int> S;
    vector<string> myvector;
    freopen("simulation_queue.txt", "r", stdin);
    while(!feof(stdin)){
        string line; getline(cin, line);

        istringstream iss(line);
        string cmd;
        iss >> cmd;
        if (cmd == "#") break;
        else if (cmd == "PUSH") {
            int k;
            if (iss >> k) {
                S.push(k);
            } else {
                cerr << "Loi khi doc gia tri tu PUSH." << endl;
            }
        } else if (cmd == "POP") {
            if (!S.empty()) {
                int e = S.front();
                S.pop();
                myvector.push_back(to_string(e));
            } else if (S.empty()) {
                string empT = "NULL";
                myvector.push_back(empT);
            }
        }
    }

    for (string value : myvector) {
        cout << value << endl;
    }

    return 0;
}
