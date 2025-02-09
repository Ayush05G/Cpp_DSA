class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> stations) {
        if (startFuel >= target) return 0; // Edge case: target reachable without stops

        int stops = 0;
        int dist = 0;
        int i = 0;
        int fuel = startFuel;
        priority_queue<int> pq; // Max-heap for fuel amounts

        while (dist < target) {
            // Push all stations within reach into the heap
            while (i < stations.size() && stations[i][0] <= dist + fuel) {
                pq.push(stations[i][1]); // Add station fuel
                ++i;
            }

            // If no station is reachable and target is not yet reached
            if (pq.empty()) {
                return -1;
            }

            // Refuel with the best (max) fuel option
            fuel += pq.top();
            pq.pop();
            ++stops;

            // Move as far as possible with the available fuel
            dist += fuel;
            fuel = 0;
        }

        return stops;
    }
};
