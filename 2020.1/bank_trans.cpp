#include <bits/stdc++.h>
using namespace std;

// vector<Transaction> transactions;

int inspect_cycle(string &acc, int k, vector<pair<string, string>> &transactions) {
    set<string> visited;
    string currentAccount = acc;
    for (int i = 0; i < k; ++i) {
        auto it = find_if(transactions.begin(), transactions.end(), [&currentAccount](auto &t) {
            return t.first == currentAccount;
        });

        if (it == transactions.end() || visited.find(it->second) != visited.end()) {
            return 0;
        } else {
            currentAccount = it->second;
            if (visited.find(currentAccount) != visited.end()) {
                return 0;
            }
            visited.insert(currentAccount);
        }
    }
    return currentAccount == acc;
}

int main() {
    freopen("bank_data.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string facc;
    int totalTrans = 0;
    int totalMoney = 0;
    set<string> accountSet;
    map<string, int> moneyFromAccount;
    vector<pair<string, string>> transactions;
    do {
        cin >> facc;
        if (facc == "#") continue;
        ++totalTrans;
        string tacc, time_p, atm;
        int money;
        cin >> tacc >> money >> time_p >> atm;
        totalMoney += money;

        accountSet.insert(facc);
        accountSet.insert(tacc);

        moneyFromAccount[facc] += money;
        transactions.push_back(make_pair(facc, tacc));
    } while (facc != "#");

    string type;
    do {
        cin >> type;
        if (type == "#") continue;
        if (type == "?number_transactions") {
            cout << totalTrans << endl;
        } else if (type == "?total_money_transaction") {
            cout << totalMoney << endl;
        } else if (type == "?list_sorted_accounts") {
            for (const auto &acc : accountSet) {
                cout << acc << " ";
            }
            cout << endl;
        } else if (type == "?total_money_transaction_from") {
            string accToCheck;
            cin >> accToCheck;
            if (moneyFromAccount.find(accToCheck) != moneyFromAccount.end()) {
                cout << moneyFromAccount[accToCheck] << endl;
            } else {
                cout << "Account not found." << endl;
            }
        } else if (type == "?inspect_cycle") {
            string accToCheck;
            int k;
            cin >> accToCheck >> k;
            int check = inspect_cycle(accToCheck, k, transactions);
            cout << check << endl;
        }
    } while (type != "#");

    return 0;
}
