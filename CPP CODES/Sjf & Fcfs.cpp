#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

void FCFS(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                swap(p[j], p[j + 1]);
                swap(p[j].burst_time,p[j+1].burst_time);
                swap(p[j].arrival_time,p[j+1].arrival_time);
            }
        }
    }

    p[0].completion_time = p[0].arrival_time + p[0].burst_time;
    for (int i = 1; i < n; i++) {
        if (p[i - 1].completion_time < p[i].arrival_time) {
            p[i].completion_time = p[i].arrival_time + p[i].burst_time;
        } else {
            p[i].completion_time = p[i - 1].completion_time + p[i].burst_time;
        }
        p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
    }
}

void SJF(Process p[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].burst_time > p[j].burst_time) {
                swap(p[i], p[j]);
                swap(p[j].burst_time,p[j+1].burst_time);
                swap(p[j].arrival_time,p[j+1].arrival_time);
            }
        }
    }

    p[0].completion_time = p[0].arrival_time + p[0].burst_time;
    for (int i = 1; i < n; i++) {
        if (p[i - 1].completion_time < p[i].arrival_time) {
            p[i].completion_time = p[i].arrival_time + p[i].burst_time;
        } else {
            p[i].completion_time = p[i - 1].completion_time + p[i].burst_time;
        }
        p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
    }
}

void Print(Process p[], int n) {
    cout << " Scheduling" << endl;
    cout << "PID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t\t" << p[i].arrival_time << "\t\t" << p[i].burst_time << "\t\t"
             << p[i].completion_time << "\t\t" << p[i].turn_around_time << "\t\t" << p[i].waiting_time << endl;
    }
}

int main() {
    int n = 4;
    Process p[] = {{1, 1, 1, 0, 0, 0},
                   {2, 3, 2, 0, 0, 0},
                   {3, 2, 1, 0, 0, 0},
                   {4, 0, 4, 0, 0, 0}
    };

    FCFS(p, n);
    Print(p, n);

    SJF(p, n);
    Print(p, n);

    return 0;
}
