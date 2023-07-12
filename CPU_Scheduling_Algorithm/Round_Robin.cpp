#include <bits/stdc++.h>
using namespace std;

struct Process{
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};
vector <Process> pr;

void Gantt_Chart(int n, int quantum){
    puts("\n>>>>>>  GANTT CHART : ROUND ROBIN  >>>>>>>>");
    int temp[n]; // temporary varibles for burst time

    // top bar
    for (int i = 0; i < n; i++)
        temp[i] = pr[i].burst_time;

    cout << " ";
    int flag = n;
    for (int i = 0; i < n; i++){
        if (temp[i] <= quantum && temp[i] > 0){
            for (int j = 0; j < temp[i]; j++)
                cout << "--";

            temp[i] = 0;
            flag--;

            if (i == n - 1)
                i = -1;

            cout << " ";
        }
        else if (temp[i] > quantum){
            for (int j = 0; j < quantum; j++)
                cout << "--";

            temp[i] = temp[i] - quantum;

            if (i == n - 1)
                i = -1;

            cout << " ";
        }
        else{
            if (flag == 0)
                break;
            else if (i == n - 1)
                i = -1;
            else
                continue;
        }
    }
    // middle bar
    flag = n;
    for (int i = 0; i < n; i++)
        temp[i] = pr[i].burst_time;

    cout << "\n|";
    for (int i = 0; i < n; i++){
        if (temp[i] <= quantum && temp[i] > 0){
            for (int j = 0; j < temp[i] - 1; j++)
                cout << " ";

            cout << "P" << i + 1;

            for (int j = 0; j < temp[i] - 1; j++)
                cout << " ";

            temp[i] = 0;
            flag--;

            if (i == n - 1)
                i = -1;

            cout << "|";
        }
        else if (temp[i] > quantum){
            for (int j = 0; j < quantum - 1; j++)
                cout << " ";

            cout << "P" << i + 1;

            for (int j = 0; j < quantum - 1; j++)
                cout << " ";

            temp[i] = temp[i] - quantum;

            if (i == n - 1)
                i = -1;

            cout << "|";
        }
        else{
            if (flag == 0)
                break;
            else if (i == n - 1)
                i = -1;
            else
                continue;
        }
    }

    // boottom bar
    cout << "\n ";
    flag = n;
    for (int i = 0; i < n; i++)
        temp[i] = pr[i].burst_time;

    for (int i = 0; i < n; i++){
        if (temp[i] <= quantum && temp[i] > 0){
            for (int j = 0; j < temp[i]; j++)
                cout << "--";

            temp[i] = 0;
            flag--;

            if (i == n - 1)
                i = -1;

            cout << " ";
        }
        else if (temp[i] > quantum){
            for (int j = 0; j < quantum; j++)
                cout << "--";

            temp[i] = temp[i] - quantum;

            if (i == n - 1)
                i = -1;

            cout << " ";
        }
        else{
            if (flag == 0)
                break;
            else if (i == n - 1)
                i = -1;
            else
                continue;
        }
    }
}

void Time_Line(int n, int quantum){
    int temp[n]; // temporary varibles for burst time

    for (int i = 0; i < n; i++)
        temp[i] = pr[i].burst_time;

    int flag = n;
    int count = 0;
    cout << "\n0";

    for (int i = 0; i < n; i++){
        if (temp[i] <= quantum && temp[i] > 0){
            for (int j = 0; j < temp[i]; j++)
                cout << "  ";

            count = count + temp[i];
            temp[i] = 0;
            flag--;

            if (i == n - 1)
                i = -1;

            if (count < 10)
                cout << count;
            else if (count > 9)
                printf("\b%d", count);
        }
        else if (temp[i] > quantum){
            for (int j = 0; j < quantum; j++)
                cout << "  ";

            temp[i] = temp[i] - quantum;

            if (i == n - 1)
                i = -1;

            count = count + quantum;

            if (count < 10)
                cout << count;
            else if (count > 9)
                printf("\b%d", count);
        }
        else{
            if (flag == 0)
                break;
            else if (i == n - 1)
                i = -1;
            else
                continue;
        }
    }
    cout << "\n\n";
}

int main(){
    Process p;
    int n, quantum;
    cout << "Enter number of process: ";
    cin >> n;
    puts("Enter burst time for each process");

    for (int i = 0; i < n; i++){
        cout << "P[" << i+1 << "]: ";
        cin >> p.burst_time;

        p.pid = i + 1;
        p.waiting_time = 0;
        p.turnaround_time = 0;

        pr.push_back(p);
    }
    cout << "Enter Time Quantum: ";
    cin >> quantum;
    // print gantt chart
    Gantt_Chart(n, quantum);

    // print time line
    Time_Line(n, quantum);
    return 0;
}
