#include <bits/stdc++.h>
using namespace std;
#define MAX 100

struct Process{
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};
void TablePrint(Process pr[], int n){
    cout << "+-------+------------+--------------+-----------------+" << endl;
    cout << "|  PID  | Burst Time | Waiting Time | Turnaround Time |" << endl;
    cout << "+-------+------------+--------------+-----------------+" << endl;

    for (int i = 0; i < n; i++){
        printf("|  %2d   |     %2d     |      %2d      |       %2d        |\n",
               pr[i].pid, pr[i].burst_time, pr[i].waiting_time, pr[i].turnaround_time);
        cout << "+-------+------------+--------------+-----------------+" << endl;
    }
}
void Cal_WT_and_TAT(Process pr[], int n){
    for (int i = 0; i < n; i++){
        pr[i + 1].waiting_time = pr[i].waiting_time + pr[i].burst_time;
        pr[i].turnaround_time = pr[i].burst_time + pr[i].waiting_time;
    }
}
void Print_AvgWT_and_AvgTAT(Process pr[], int n){
    int Sum_WT = 0, Sum_TAT = 0, Avg_WT = 0, AVG_TAT = 0;
    for (int i = 0; i < n; i++){
        Sum_WT = Sum_WT + pr[i].waiting_time;
        Sum_TAT = Sum_TAT + pr[i].turnaround_time;
    }
    cout << endl << "Average Waiting Time : " << (double)Sum_WT / (double)n << endl;
    cout << "Average Turnaround Time : " << (double)Sum_TAT / (double)n;
}

void Print_Gantt_Chart(Process pr[], int n){
    cout << "\n\n" << "\t***  Gantt Chart  ***" << endl;
    // print top bar
    cout << " ";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < pr[i].burst_time; j++)
            cout << "--";
        cout << " ";
    }
    // print middle bar
    cout << endl << "|";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < pr[i].burst_time - 1; j++)
            cout << " ";
        cout << "P" << pr[i].pid;
        for (int j = 0; j < pr[i].burst_time - 1; j++)
            cout << " ";
        cout << "|";
    }
    // print bottom bar
    cout << endl << " ";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < pr[i].burst_time; j++)
            cout << "--";
        cout << " ";
    }
    cout << "\n";
}
// printing time line
void Print_Time_Line(Process pr[], int n){
    cout << 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < pr[i].burst_time; j++)
            cout << "  ";
        if (pr[i].turnaround_time > 9)
            printf("\b"); // backspace : remove 1 space
        cout << pr[i].turnaround_time;
    }
}
int main(){
    Process pr[MAX]; // create 100 process
    int n;
    cout << "Enter number of process: ";
    cin >> n;
    cout << "Enter burst time for each process: " << endl;
    for (int i = 0; i < n; i++){
        cout << "\tP[" << i + 1 << "]: ";
        cin >> pr[i].burst_time;

        pr[i].pid = i + 1;
        pr[i].waiting_time = 0;
        pr[i].turnaround_time = 0;
    }
    // calculate waiting time and turn around time
    Cal_WT_and_TAT(pr, n);
    // print table
    TablePrint(pr, n);
    // print average waiting time and average turnaround time
    Print_AvgWT_and_AvgTAT(pr, n);
    // print Gantt Chart
    Print_Gantt_Chart(pr, n);
    // print time line
    Print_Time_Line(pr, n);
}
