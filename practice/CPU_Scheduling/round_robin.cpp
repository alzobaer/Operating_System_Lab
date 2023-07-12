#include <bits/stdc++.h>
using namespace std;

struct Process
{
       int id;
       int bt;
};

int findMax(int proc, int remain[])
{
       int max = remain[0];
       for (int i = 1; i < proc; i++)
       {
              if (remain[i] > max)
              {
                     max = remain[i];
              }
       }
       return max;
}

void GanttChart(vector<Process> process, int proc, int quantum)
{
       int remain[proc], val = 0;
       for (int i = 0; i < proc; i++)
       {
              remain[i] = process[i].bt;
       }

       findMax(proc, remain);
       cout << "Gantt Chart: " << endl;

       while (findMax(proc, remain) > 0)
       {
              int i = 0;
              if (i == proc - 1)
                     i = 0;
              for (i; i < proc; i++)
              {
                     if (remain[i] > 0 && remain[i] <= quantum)
                     {
                            val = val + remain[i];
                            remain[i] = 0;
                     }
                     else if (remain[i] > quantum)
                     {
                            val = val + quantum;
                            remain[i] = remain[i] - quantum;
                     }
                     cout << val << " ";
              }
       }
}

int main()
{
       vector<Process> process;
       Process p;
       int proc, x, id, quantum;
       cout << "Enter Number of Process : ";
       cin >> proc;
       cout << "Enter Quantum Number : ";
       cin >> quantum;

       for (int i = 0; i < proc; i++)
       {
              cout << "Enter the 'Burst Time' for P[" << i + 1 << "]: ";
              cin >> x;
              id = i + 1;
              p.id = id;
              p.bt = x;

              process.push_back(p);
       }

       GanttChart(process, proc, quantum);

       // cout << process[0].bt;
}