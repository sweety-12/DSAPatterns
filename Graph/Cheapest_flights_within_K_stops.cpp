787. Cheapest Flights Within K Stops
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

APPROACH: DIJIKSTRA
TC: (O(E log V))
SC: (O(V+E))

// //steps
// 1. Convert the flights into adj list and initialize
// 2. Declare the prices vector of size no of nodes and assign -1
// 3. Declare a priority queue with first element as price, 2nd and 3rd as from and to
// 4. Push the src
// 5. while loop , must take care of k

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>>adj(n);

        //convert into adj list
        for(auto it: flights){
            
            adj[it[0]].push_back({it[1], it[2]});   //need to check this if i can store this in pair
        }

        //decalre price vector
        vector<vector<int>>price(n, vector<int>(k+2, 1e9));
        price[src][0] =0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

        //need to push the first element

        pq.push({0, {src, 0}});  //price, src, stops

        while(!pq.empty()){

            int prc = pq.top().first;
            int node = pq.top().second.first;
            int stops = pq.top().second.second;

            pq.pop();

            if(prc > price[node][stops]) continue;

            //if reached the destination
            if(node == dst) return prc;

            //if connot take more flights
            if(stops == k+1) continue;

              for (auto it : adj[node]) {

                int adjNode = it.first;
                int flightCost = it.second;

                int newCost = prc + flightCost;
                int newFlights = stops + 1;

                if (newCost < price[adjNode][newFlights]) {

                    price[adjNode][newFlights] = newCost;

                    pq.push({
                        newCost,
                        {adjNode, newFlights}
                    });
                }
             }
            }

            return -1;

    }
};
