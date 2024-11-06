#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cout << "Enter the number of items: ";
    cin >> n;

    int capacity = 0;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;

    int price[n + 1] = {0};
    int weight[n + 1] = {0};  // Corrected: array size should be n+1, not capacity
    int dp[n + 1][capacity + 1];

    // Input profits and weights
    for (int i = 1; i <= n; i++) {
        cout << "Enter the profit and weight of item " << i << ": ";
        cin >> price[i] >> weight[i];
    }

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weight[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - weight[i]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "The maximum profit is: " << dp[n][capacity] << endl;
    return 0;
}
