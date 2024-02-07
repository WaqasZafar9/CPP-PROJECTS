#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Process {
    int arrivalTime;
    int burstTime;
    int remainingTime;
};

bool compareProcessesFCFS(Process a, Process b) {
    return a.arrivalTime < b.arrivalTime;
}

void roundRobin(int n, Process processes[], int timeQuantum) {
    sort(processes, processes + n, compareProcessesFCFS);

    queue<Process> q;
    int ct[30];
    int wt[30];
    int tat[30];
    int currentTime = 0;
    int remainingProcesses = n;

    for (int i = 0; i < n; i++) {
        processes[i].remainingTime = processes[i].burstTime;
    }

    while (remainingProcesses > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                int executionTime = min(processes[i].remainingTime, timeQuantum);
                processes[i].remainingTime -= executionTime;
                currentTime += executionTime;

                if (processes[i].remainingTime == 0) {
                    remainingProcesses--;
                    ct[i] = currentTime;
                    tat[i] = ct[i] - processes[i].arrivalTime;
                    wt[i] = tat[i] - processes[i].burstTime;
                }

                q.push(processes[i]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": CT=" << ct[i] << " TAT=" << tat[i] << " WT=" << wt[i] << endl;
    }
}

int main() {
    int n = 6;
    Process processes[6] = {{0, 3, 0},
                            {1, 4, 0},
                            {3, 4, 0},
                            {4, 5, 0},
                            {5, 2, 0},
                            {6, 6, 0}
    };
    int timeQuantum = 2;

    roundRobin(n, processes, timeQuantum);

    return 0;
}
