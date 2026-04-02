#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int>& arr) {
    sort(arr.begin(), arr.end(), greater<int>());
    unordered_set<int> alex, bob;
    long long a = 0, b = 0;
    int turn = 0; // 0 = Alex, 1 = Bob

    for (int i = 0; i < n; i++) {
        if (turn == 0) { // Alex's turn
            if (alex.find(arr[i]) == alex.end()) {
                alex.insert(arr[i]);
                a += arr[i];
                turn = 1;
            }
        } else { // Bob's turn
            if (bob.find(arr[i]) == bob.end()) {
                bob.insert(arr[i]);
                b += arr[i];
                turn = 0;
            }
        }
    }

    if (a > b) return "Alex";
    else return "Bob";
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i_arr = 0; i_arr < n; i_arr++)
        {
        	cin >> arr[i_arr];
        }

        string out_;
        out_ = solve(n, arr);
        cout << out_;
        cout << "\n";
    }
}