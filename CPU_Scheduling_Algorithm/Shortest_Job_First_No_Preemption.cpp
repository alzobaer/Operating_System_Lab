#include <bits/stdc++.h>
using namespace std;

struct Process{
    int pid;
    int burst_time;
    int waiting_time;
    int turnaroud_time;
};
vector<Process> pr;

void sort_by_burst_time(int n){
    Process temp;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(pr[i].burst_time > pr[j].burst_time){
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
        pr[i].turnaroud_time = pr[i].burst_time + pr[i].waiting_time;
    }
}

void Print_Table(int n){
    cout << "\n TABLE:\n";
    puts("+-------+------------+--------------+-----------------+");
    puts("|  PID  | Burst Time | Waiting Time | Turnaround Time |");
    puts("+-------+------------+--------------+-----------------+");

    for (int i = 0; i < n; i++){
        printf("|  P%d   |    %2d      |     %2d       |       %2d        |\n",
               pr[i].pid, pr[i].burst_time, pr[i].waiting_time, pr[i].turnaroud_time);
        puts("+-------+------------+--------------+-----------------+");
    }
}
void Print_avg_WT_and_TAT(int n){
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++){
        total_wt = total_wt + pr[i].waiting_time;
        total_tat = total_tat + pr[i].turnaroud_time;
    }
    cout << "\nAverage Waiting Time = " << (double)total_wt / (double)n;
    cout << "\nAverage Waiting Time = " << (double)total_tat / (double)n << "\n";
}

void Print_Gantt_Chart(int n){
    cout << "\n\t>>>>>  Gantt Chart  <<<<<\n";
    // top bar
    cout << " ";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < pr[i].burst_time; j++)
        {
            cout << "--";
        }
        cout << " ";
    }
    // middle bar
    cout << "\n|";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < pr[i].burst_time - 1; j++)
            cout << " ";
        cout << "P" << pr[i].pid;
        for (int j = 0; j < pr[i].burst_time - 1; j++)
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
    cout << "0";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < pr[i].burst_time; j++)
            cout << "  ";
        temp = temp + pr[i].burst_time;
        if (temp > 9)
            cout << "\b";
        cout << temp;
    }
    cout << endl
         << endl;
}

int main(){
    Process p;

    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter the burst time for each process: " << endl;
    for (int i = 0; i < n; i++){
        p.pid = i + 1;
        cout << "\tP[" << p.pid << "]: ";
        cin >> p.burst_time;
        p.waiting_time = 0;
        p.turnaroud_time = 0;

        pr.push_back(p);
    }
    // sort processes by their burst tume
    sort_by_burst_time(n);

    // caculate waiting time and average turnover time
    Cal_WT_and_TAT(n);
    // make table
    Print_Table(n);
    // print average waiting time and average turnover time
    Print_avg_WT_and_TAT(n);
    // Make gantt chart
    Print_Gantt_Chart(n);
    // make time line
    Print_Time_Line(n);

    return 0;
}
