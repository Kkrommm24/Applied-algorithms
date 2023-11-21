#include <bits/stdc++.h>

int main() {
    std::map<std::string, int> wordFreq;
    std::string line;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string word;

        while (iss >> word) {
            wordFreq[word]++;
        }
    }

    for (const auto& pair : wordFreq) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}
