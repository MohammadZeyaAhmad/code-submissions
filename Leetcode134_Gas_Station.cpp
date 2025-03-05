class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0, total_cost = 0, curr_gas = 0, start_index = 0;

        for (int i = 0; i < gas.size(); i++) {
            total_gas += gas[i];
            total_cost += cost[i];
            curr_gas += gas[i] - cost[i];

            // If at any point, gas becomes negative, reset and pick the next station
            if (curr_gas < 0) {
                start_index = i + 1;
                curr_gas = 0;
            }
        }

        return (total_gas >= total_cost) ? start_index : -1;
    }
};
