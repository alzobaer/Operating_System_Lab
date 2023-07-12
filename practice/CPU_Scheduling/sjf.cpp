#include <bits/stdc++.h>
using namespace std;
struct Process
{
    int id;
    int bt;
};

void GanttChart(vector<Process> process, int proc)
{
    // cout << process[0].bt;
    vector<int> wt;
    wt.push_back(0);
    cout << endl
         << "Gantt Chart: " << endl
         << "|";
    for (int i = 0; i < proc; i++)
    {
        for (int j = 0; j < (process[i].bt); j++)
        {
            cout << "``";
        }
        cout << "P" << process[i].id;
        for (int j = 0; j < process[i].bt; j++)
        {
            cout << "``";
        }
        cout << "|";
    }
    cout << endl
         << "|";

    for (int i = 0; i < proc; i++)
    {
        for (int j = 0; j < (process[i].bt); j++)
        {
            cout << "__";
        }
        cout << "__";
        for (int j = 0; j < process[i].bt; j++)
        {
            cout << "__";
        }
        cout << "|";
    }
    cout << endl;

    cout << wt[0];
    for (int i = 0; i < proc; i++)
    {
        cout << " ";
        for (int j = 0; j < process[i].bt; j++)
        {
            cout << "    ";
        }
        wt.push_back(process[i].bt + wt[i]);
        cout << wt[i + 1];
    }
    cout << endl
         << endl;
}

void makeTable(vector<Process> process, int proc)
{
    vector<int> wt, tat;
    wt.push_back(0);
    for (int i = 0; i < proc; i++)
    {
        wt.push_back(wt[i] + process[i].bt);
        tat.push_back(wt[i] + process[i].bt);
    }
    cout << "Table: " << endl
         << "_________________________________________________________________"
         << endl;
    cout << "| Process\tBurst Time\tWaiting Time\tTurnaround Time |";
    for (int i = 0; i < proc; i++)
    {
        cout << endl
             << "|";
        cout << "  " << process[i].id << "\t\t" << process[i].bt << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t|";
    }
    cout << endl
         << "`````````````````````````````````````````````````````````````````" << endl;
}

int main()
{
    int proc, x, id;
    cout << "Enter Number of Process : ";
    cin >> proc;
    // Process process[proc];
    vector<Process> process;
    Process p;

    for (int i = 0; i < proc; i++)
    {
        cout << "Enter the 'Burst Time' for P[" << i + 1 << "] : ";
        cin >> x;
        id = i + 1;
        p.id = id;
        p.bt = x;
        process.push_back(p);
    }
    // sorting burst time
    std::sort(process.begin(), process.end(), [](const Process &a, const Process &b)
              { return a.bt < b.bt; });

    GanttChart(process, proc);

    makeTable(process, proc);

    return 0;
}