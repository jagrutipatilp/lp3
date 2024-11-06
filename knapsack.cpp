#include<iostream>
#include<algorithm>
using namespace std;

struct Item {
    int profit;
    int weight;
    double ratio;
};

// Comparator function to sort items by profit-to-weight ratio in descending order
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n = 0;
    cout << "Enter the number of items: ";
    cin >> n;

    int profits[n], weights[n];
    Item items[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the profit and weight of item " << i + 1 << ": ";
        cin >> profits[i] >> weights[i];
        
        // Store profit, weight, and profit-to-weight ratio in the Item array
        items[i] = {profits[i], weights[i], (double)profits[i] / weights[i]};
    }

    int capacity = 0;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;

    // Sort items by profit-to-weight ratio
    sort(items, items + n, compare);

    double maxProfit = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // If we can take the whole item, add its full profit
            maxProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            // If only part of the item can be taken, take fractionally
            maxProfit += items[i].ratio * capacity;
            break; // Knapsack is full, so exit
        }
    }

    cout << "The maximum profit is: " << maxProfit << endl;
    return 0;
}







void selectionSort(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (items[j].ratio > items[maxIdx].ratio) {
                maxIdx = j;
            }
        }
        // Swap items[i] with items[maxIdx]
        Item temp = items[i];
        items[i] = items[maxIdx];
        items[maxIdx] = temp;
    }
}
