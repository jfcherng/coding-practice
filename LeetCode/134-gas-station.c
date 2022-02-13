#include "_leetcode_common.h"

#define debug 1

int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize) {
  int ans = 0; // station idx
  int tank = 0, circuit_gain = 0;

  for (int i = 0; i < gasSize; ++i) {
    int move_gain = gas[i] - cost[i];
    circuit_gain += move_gain;

    // try move to the next station
    tank += move_gain;
    if (tank < 0) {
      // restart from the next station in the next try
      ans = i + 1;
      tank = 0;
    }
  }

  return circuit_gain < 0 ? -1 : ans;
}

int main(int argc, char *argv[]) {
  int size, *gas, *cost;

  size = 5;
  int _gas_1[5] = {1, 2, 3, 4, 5};
  gas = _gas_1;
  int _cost_1[5] = {3, 4, 5, 1, 2};
  cost = _cost_1;
  printf("Ans: %d, expect 3\n", canCompleteCircuit(gas, size, cost, size));

  size = 3;
  int _gas_2[5] = {2, 3, 4};
  gas = _gas_2;
  int _cost_2[5] = {3, 4, 3};
  cost = _cost_2;
  printf("Ans: %d, expect -1\n", canCompleteCircuit(gas, size, cost, size));

  size = 3;
  int _gas_3[5] = {3, 1, 1};
  gas = _gas_3;
  int _cost_3[5] = {1, 2, 2};
  cost = _cost_3;
  printf("Ans: %d, expect 0\n", canCompleteCircuit(gas, size, cost, size));

  size = 5;
  int _gas_4[5] = {7, 1, 0, 11, 4};
  gas = _gas_4;
  int _cost_4[5] = {5, 9, 1, 2, 5};
  cost = _cost_4;
  printf("Ans: %d, expect 3\n", canCompleteCircuit(gas, size, cost, size));

  return 0;
}
