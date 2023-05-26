//Write a code to solve Job sequencing with deadline Problem in O(n^2) time

#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int profit;
    int deadline;
};

bool compareJobs(Job j1, Job j2) {
    return (j1.profit > j2.profit);
}

void jobSequencing(Job jobs[], int n) {
    sort(jobs, jobs + n, compareJobs);
    
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    
    char result[maxDeadline];
    bool slot[maxDeadline];
    
    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = false;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = jobs[i].id;
                slot[j] = true;
                break;
            }
        }
    }
    
    cout << "Job sequence with maximum profit: ";
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i]) {
            cout << result[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    Job jobs[] = { {'a', 100, 2}, {'b', 19, 1}, {'c', 27, 2}, {'d', 25, 1}, {'e', 15, 3} };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    
    jobSequencing(jobs, n);
    
    return 0;
}
