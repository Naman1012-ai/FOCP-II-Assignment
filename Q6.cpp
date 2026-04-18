
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class MovieTicket {
    // movieId -> set of customerIds who booked
    unordered_map<string, unordered_set<string>> bookings;
    // movieId -> available tickets (starts at 100 for each movie)
    unordered_map<string, int> availableTickets;

    // Ensure a movie entry exists with default 100 tickets
    void ensureMovie(const string& movieId) {
        if (availableTickets.find(movieId) == availableTickets.end()) {
            availableTickets[movieId] = 100;
        }
    }

public:
    // BOOK X Y: Customer X books ticket for movie Y.
    // Return false if already booked for same movie or movie sold out.
    // Otherwise, mark as booked and return true.
    bool book(const string& customerId, const string& movieId) {
        ensureMovie(movieId);

        // Check if already booked or sold out
        if (bookings[movieId].count(customerId) || availableTickets[movieId] <= 0) {
            return false;
        }

        bookings[movieId].insert(customerId);
        availableTickets[movieId]--;
        return true;
    }

    // CANCEL X Y: Customer X cancels ticket for movie Y.
    // Return false if customer hasn't booked for this movie.
    // Otherwise, cancel and return true.
    bool cancel(const string& customerId, const string& movieId) {
        if (bookings.find(movieId) == bookings.end() ||
            bookings[movieId].find(customerId) == bookings[movieId].end()) {
            return false;
        }

        bookings[movieId].erase(customerId);
        availableTickets[movieId]++;
        return true;
    }

    // IS_BOOKED X Y: Check if customer X has booked for movie Y.
    // Return true if booked, false otherwise.
    bool isBooked(const string& customerId, const string& movieId) {
        if (bookings.find(movieId) == bookings.end()) {
            return false;
        }
        return bookings[movieId].count(customerId) > 0;
    }

    // AVAILABLE_TICKETS Y: Return available tickets for movie Y.
    int availableTicketsCount(const string& movieId) {
        if (availableTickets.find(movieId) == availableTickets.end()) {
            return 100; // Movie not yet seen, all 100 available
        }
        return availableTickets[movieId];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    MovieTicket system;
    vector<string> results;

    while (q--) {
        string operation;
        cin >> operation;

        if (operation == "BOOK") {
            string customerId, movieId;
            cin >> customerId >> movieId;
            bool res = system.book(customerId, movieId);
            results.push_back(res ? "true" : "false");
        }
        else if (operation == "CANCEL") {
            string customerId, movieId;
            cin >> customerId >> movieId;
            bool res = system.cancel(customerId, movieId);
            results.push_back(res ? "true" : "false");
        }
        else if (operation == "IS_BOOKED") {
            string customerId, movieId;
            cin >> customerId >> movieId;
            bool res = system.isBooked(customerId, movieId);
            results.push_back(res ? "true" : "false");
        }
        else if (operation == "AVAILABLE_TICKETS") {
            string movieId;
            cin >> movieId;
            int tickets = system.availableTicketsCount(movieId);
            results.push_back(to_string(tickets));
        }
    }

    for (const auto& r : results) {
        cout << r << "\n";
    }

    return 0;
}
