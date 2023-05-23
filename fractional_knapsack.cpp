// Write a code to solve fractional knapsack Problem in o(nlgn) time


#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item item1, Item item2) {
    double ratio1 = static_cast<double>(item1.value) / item1.weight;
    double ratio2 = static_cast<double>(item2.value) / item2.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int capacity, Item items[], int size) {
    sort(items, items + size, compare);
    double totalValue = 0.0;
    int currentWeight = 0,remainingWeight;

    for (int i = 0; i < size; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            remainingWeight = capacity - currentWeight;
            totalValue += (static_cast<double>(items[i].value) / items[i].weight) * remainingWeight;
            break;
        }
    }

    return totalValue;
}


int main() {
    int capacity = 50;
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int size = sizeof(items) / sizeof(items[0]);

    double maxValue = fractionalKnapsack(capacity, items, size);

    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
