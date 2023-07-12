#include <bits/stdc++.h>
using namespace std;

struct Process{
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};
vector<Process> pr;

void sort_by_priority(int n){
    Process temp;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (pr[i].priority > pr[j].priority){
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
            }
        }
    }
}

void Cal_WT_and_TAT(int n){
    pr[0].waiting_time = 0;
    for (int i = 0; i < n; i++){
        pr[i + 1].waiting_time = pr[i].waiting_time + pr[i].burst_time;
        pr[i].turnaround_time = pr[i].waiting_time + pr[i].burst_time;
    }
}

void Print_Table(int n){
    puts("+------+------------+----------+--------------+-----------------+");
    puts("| PID  | Burst Time | Priority | Waiting Time | Turnaround Time |");
    puts("+------+------------+----------+--------------+-----------------+");

    for (int i = 0; i < n; i++){
        printf("|  P%d  |     %2d     |    %2d    |      %2d      |       %2d        |\n",
               pr[i].pid, pr[i].burst_time, pr[i].priority, pr[i].waiting_time, pr[i].turnaround_time);
        puts("+------+------------+----------+--------------+-----------------+");
    }
}

void Print_avg_WT_and_TAT(int n){
    int tot_wt = 0, tot_tat = 0;
    for (int i = 0; i < n; i++){
        tot_wt = tot_wt + pr[i].waiting_time;
        tot_tat = tot_tat + pr[i].turnaround_time;
    }
    cout << "\n Average waiting time = " << (double)tot_wt / (double)n;
    cout << "\n Average turnaround time = " << (double)tot_tat / (double)n << "\n\n";
}

void Print_Gantt_Chart(int n){
    puts(">>>>>>>  Gantt Chart  <<<<<<<");
    // top bar
    cout << " ";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < pr[i].burst_time; j++)
            cout << "--";
        cout << " ";
    }
    // middle bar
    cout << "\n|";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < pr[i].burst_time - 1; j++)
            cout << " ";
        cout << "P" << pr[i].pid;
        for (size_t j = 0; j < pr[i].burst_time - 1; j++)
            cout << " ";
        cout << "|";
    }
    // bottom bar
    cout << "\n ";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < pr[i].burst_time; j++)
            cout << "--";
        cout << " ";
    }
    cout << "\n";
}

void Print_Time_Line(int n){
    int temp = 0;
    cout << temp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < pr[i].burst_time; j++)
            cout << "  ";
        temp = temp + pr[i].burst_time;
        if (temp > 9)
            cout << "\b" << temp;
        else
            cout << temp;
    }
    cout << "\n\n";
}

int main(){
    Process p;

    int n;
    cout << "Enter number of Process: ";
    cin >> n;
    puts("Enter the burst time and priority for each process");

    for (int i = 0; i < n; i++){
        p.pid = i + 1;
        cout << "P[" << p.pid << "]: \n";
        cout << "Burst Time: ";
        cin >> p.burst_time;
        cout << "Priority: ";
        cin >> p.priority;

        p.waiting_time = 0;
        p.turnaround_time = 0;

        pr.push_back(p);
        cout << endl;
    }

    // sort processes by their priority
    sort_by_priority(n);

    // calculate waiting time and turnaround time
    Cal_WT_and_TAT(n);

    // print table
    Print_Table(n);

    // print average waiting time and turnaround time
    Print_avg_WT_and_TAT(n);

    // print gantt chart
    Print_Gantt_Chart(n);
    Print_Time_Line(n);

    return 0;
}

/*

    5
    10 3
    1 1
    2 4
    1 5
    5 2

*/
