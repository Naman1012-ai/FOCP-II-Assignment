#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class BankSystem {
    unordered_map<string, long long> accounts; // userID -> balance

public:
    // CREATE X Y: Create account with ID X and balance Y.
    // If user already exists, add Y to their balance and return false.
    // If user is new, create account with balance Y and return true.
    bool create(const string& userId, long long amount) {
        if (accounts.find(userId) != accounts.end()) {
            // User already exists -> add Y dollars, return false
            accounts[userId] += amount;
            return false;
        }
        // New user -> create account, return true
        accounts[userId] = amount;
        return true;
    }

    // DEBIT X Y: Debit Y dollars from user X.
    // If user not present or balance < Y, do nothing and return false.
    // Otherwise, debit Y and return true.
    bool debit(const string& userId, long long amount) {
        auto it = accounts.find(userId);
        if (it == accounts.end() || it->second < amount) {
            return false;
        }
        it->second -= amount;
        return true;
    }

    // CREDIT X Y: Credit Y dollars to user X.
    // If user not present, do nothing and return false.
    // Otherwise, credit Y and return true.
    bool credit(const string& userId, long long amount) {
        auto it = accounts.find(userId);
        if (it == accounts.end()) {
            return false;
        }
        it->second += amount;
        return true;
    }

    // BALANCE X: Return balance of user X.
    // If user not present, return -1.
    long long balance(const string& userId) {
        auto it = accounts.find(userId);
        if (it == accounts.end()) {
            return -1;
        }
        return it->second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    BankSystem bank;
    vector<string> results;

    while (q--) {
        string operation;
        cin >> operation;

        if (operation == "CREATE") {
            string userId;
            long long amount;
            cin >> userId >> amount;
            bool res = bank.create(userId, amount);
            results.push_back(res ? "true" : "false");
        }
        else if (operation == "DEBIT") {
            string userId;
            long long amount;
            cin >> userId >> amount;
            bool res = bank.debit(userId, amount);
            results.push_back(res ? "true" : "false");
        }
        else if (operation == "CREDIT") {
            string userId;
            long long amount;
            cin >> userId >> amount;
            bool res = bank.credit(userId, amount);
            results.push_back(res ? "true" : "false");
        }
        else if (operation == "BALANCE") {
            string userId;
            cin >> userId;
            long long bal = bank.balance(userId);
            results.push_back(to_string(bal));
        }
    }

    // Output all results
    for (const auto& r : results) {
        cout << r << "\n";
    }

    return 0;
}
