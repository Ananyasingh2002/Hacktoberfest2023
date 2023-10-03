#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> inputSet = {1, 2, 3};
    int n = inputSet.size();
    int totalSum = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        int subsetSum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subsetSum += inputSet[i];
            }
        }
        totalSum += subsetSum;
    }

    cout << "Sum of all subsets: " << totalSum << endl;

    return 0;
}
