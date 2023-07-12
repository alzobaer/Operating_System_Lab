#include <bits/stdc++.h>
using namespace std;

void GanttChart(int proc, vector<int> vec)
{
    cout << endl
         << "********** Gantt Chart************" << endl;

    for (int i = 0; i < proc; i++)
    {
        cout << "|";
        for (int j = 0; j < vec[i]; j++)
        {
            cout << "``";
        }
        cout << "P" << i + 1;

        for (int j = 0; j < vec[i]; j++)
        {
            cout << "``";
        }
    }
    cout << "|" << endl;

    for (int i = 0; i < proc; i++)
    {
        cout << "|";
        for (int j = 0; j < vec[i]; j++)
        {
            cout << "__";
        }
        cout << "__";

        for (int j = 0; j < vec[i]; j++)
        {
            cout << "__";
        }
    }

    int sum = 0;
    cout << "|" << endl
         << sum;
    for (int i = 0; i < proc; i++)
    {
        cout << " ";
        for (int j = 0; j < vec[i]; j++)
        {
            cout << "    ";
        }
        sum = sum + vec[i];
        cout << sum;
    }
}

void MakeTable(int proc, vector<int> vec)
{

    int twt = 0, ttat = 0;
    float avgwt, avgtat;
    vector<int> wt, tat;
    wt.push_back(0);
    // cout << wt[0];
    //  Waiting Time calculation
    for (int i = 0; i < size(vec); i++)
    {
        wt.insert(wt.begin() + i + 1, wt[i] + vec[i]); // vec.insert(vec.begin() + index, value)
    }
    // for (int i = 0; i < size(vec); i++)
    // {
    //     cout << endl
    //          << wt[i] << endl;
    // }

    // Turn-around Time calculation
    for (int i = 0; i < size(vec); i++)
    {
        tat.push_back(wt[i] + vec[i]);
    }
    // for (int i = 0; i < size(vec); i++)
    // {
    //     cout << endl
    //          << tat[i] << endl;
    // }
    cout << "________________________________________________________________" << endl;
    cout << "| Process\t"
         << "Burst Time\t"
         << "Waiting time\t"
         << "Turnaround Time |" << endl;
    for (int i = 0; i < size(vec); i++)
    {
        cout << "| " << i + 1 << "\t\t" << vec[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t|" << endl;
    }
    cout << "````````````````````````````````````````````````````````````````" << endl;

    // average waiting time and average turn around time calculation
    for (int i = 0; i < size(vec); i++)
    {
        twt = twt + wt[i];
        ttat = ttat + tat[i];
    }
    avgwt = (float)twt / (float)size(vec);
    avgtat = (float)ttat / (float)size(vec);
    cout << "Average Waiting Time : " << avgwt << endl;
    cout << "Average Turnaround Time : " << avgtat << endl;
}

int main()
{
    int proc, bt;
    vector<int> vec;
    cout << "Enter Number of process : ";
    cin >> proc;
    for (int i = 0; i < proc; i++)
    {
        cout << "Enter 'Burst Time' for proc"
             << "[" << i + 1 << "] : ";
        cin >> bt;
        vec.push_back(bt);
    }

    GanttChart(proc, vec);

    cout << endl
         << endl;

    MakeTable(proc, vec);

    return 0;
}