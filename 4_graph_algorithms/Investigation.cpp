#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

// Use long long for price due to large constraints (10^9 price * 2*10^5 edges)
typedef long long ll;

// Define the modulus for counting paths
const int MOD = 1e9 + 7;

// Define a large value for infinity
const ll INF = 1e18; 

// Structure to hold the four required properties for a city
struct CityInfo {
    ll min_price;
    int count;
    int min_flights;
    int max_flights;

    // Default constructor: Initial state for all cities except the source
    CityInfo() : min_price(INF), count(0), min_flights(1e9), max_flights(0) {}
};

// Main function to solve the problem
void solve() {
    int n, m;
    cin >> n >> m;

    // Adjacency List: {destination_city, price}
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }

    // Array to store the required information for each city
    vector<CityInfo> info(n + 1);

    // Priority Queue for Dijkstra's: {current_price, current_city}
    // Note: We use greater<> to make it a Min Heap based on price.
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    // ----------------------------------------------------------------------
    // Initialization for Source City (City 1)
    // ----------------------------------------------------------------------
    info[1].min_price = 0;
    info[1].count = 1;
    info[1].min_flights = 0;
    info[1].max_flights = 0;
    pq.push({0, 1}); // {price, city}

    // ----------------------------------------------------------------------
    // Dijkstra's Algorithm with Path Property Updates
    // ----------------------------------------------------------------------
    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Skip if we've found a shorter path previously (obsolete entry)
        if (d > info[u].min_price) {
            continue;
        }

        // Iterate over neighbors (v)
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            ll price = edge.second;
            ll new_price = d + price;

            // Case 1: Found a strictly shorter path to v
            if (new_price < info[v].min_price) {
                info[v].min_price = new_price;
                
                // All properties are reset/updated based on the new shortest path from u
                info[v].count = info[u].count;
                info[v].min_flights = info[u].min_flights + 1;
                info[v].max_flights = info[u].max_flights + 1;
                
                pq.push({new_price, v});
            } 
            // Case 2: Found a path with the same minimum price
            else if (new_price == info[v].min_price) {
                // Update Path Count (modulo operation)
                info[v].count = (info[v].count + info[u].count) % MOD;

                // Update Minimum Flights
                info[v].min_flights = min(info[v].min_flights, info[u].min_flights + 1);

                // Update Maximum Flights
                info[v].max_flights = max(info[v].max_flights, info[u].max_flights + 1);
            }
        }
    }

    // ----------------------------------------------------------------------
    // Output for Lehmälä (City n)
    // ----------------------------------------------------------------------
    
    // Minimum price is already tracked
    cout << info[n].min_price << " ";
    
    // Count is tracked
    cout << info[n].count << " ";
    
    // Minimum flights
    cout << info[n].min_flights << " ";
    
    // Maximum flights
    cout << info[n].max_flights << "\n";
}

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
