#include <bits/stdc++.h> 
int main() 
{ 
    std::queue<int> S;
    std::vector<std::string> myvector;
    freopen("simulation_queue.txt", "r", stdin);
    while(!feof(stdin)){
        std::string line; std::getline(std::cin, line);

        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;
        if (cmd == "#") break;
        else if (cmd == "PUSH") {
            int k;
            if (iss >> k) {
                S.push(k);
            } else {
                std::cerr << "Loi khi doc gia tri tu PUSH." << std::endl;
            }
        } else if (cmd == "POP") {
            if (!S.empty()) {
                int e = S.front();
                S.pop();
                myvector.push_back(std::to_string(e));
            }else if (S.empty()) {
                std::string empT = "NULL";
                myvector.push_back(empT);
            }
        }
    }

    for (std::string value : myvector) {
        std::cout << value << std::endl;
    }

    return 0;
}




