#include <bits/stdc++.h>
using namespace std;
struct process
{
    int processNumber;
    int BT;
    int priority;
};

vector<int> PS(process processes[], int proc)
{
    process temp;
    vector<int> timeTable;

    for (int i = 0; i < proc; i++)
    {
        for (int j = i + 1; j < proc; j++)
        {
            if (processes[i].priority > processes[j].priority)
            {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    for (int i = 0; i < proc; i++)
    {
        for (int j = 0; j < processes[i].BT; j++)
        {
            timeTable.push_back(processes[i].processNumber);
        }
    }

    return timeTable;
}

void printLine(vector<int> timeTable)
{
    int length = timeTable.size();
    printf("|--");
    for (int i = 1; i < length; i++)
    {
        if (timeTable[i] == timeTable[i - 1])
        {
            printf("--");
        }
        else
        {
            printf("|--");
        }
    }
    printf("|");
    printf("\n");
}

void printProcessNumber(vector<int> timeTable)
{
    int i = 0;
    printf("P%d", timeTable[i]);
    int length = timeTable.size();
    for (int i = 1; i < length; i++)
    {
        if (timeTable[i] == timeTable[i - 1])
        {
            printf("  ");
        }
        else
        {
            printf(" P%d", timeTable[i]);
        }
    }
    printf("\n");
}

int printEndingTime(vector<int> timeTable)
{
    printf("0");
    int totWT = 0;
    int previousEnding = 0;
    int length = timeTable.size();
    for (int i = 1; i < length; i++)
    {
        if (timeTable[i] == timeTable[i - 1])
        {
            printf("  ");
        }
        else
        {
            printf("  %d", i);
            // previousEnding = previousEnding - i;
            totWT = totWT + i;
        }
    }
    printf("%d", length);
    printf("\n");

    return totWT;
}
float printGanttChart(vector<int> timeTable)
{
    float totWT;
    int waitingTime;
    printLine(timeTable);
    printProcessNumber(timeTable);
    printLine(timeTable);
    waitingTime = printEndingTime(timeTable);
    // printf("Waiting Time %d\n", waitingTime);
    totWT = (waitingTime * 1.0);
    // printf("Total Waiting Time in gant chart function %f\n", totWT);
    return totWT;
}

int main()
{
    float totWT;
    float avgWT;
    int proc;
    int BT;
    int priority;
    printf("How many number of Process?");
    cin >> proc;

    process processes[proc];
    vector<int> timeTable;

    for (int i = 0; i < proc; i++)
    {
        cout << "Burst Time for proc[" << i + 1 << "]: ";
        cin >> BT;
        cout << "priority for proc[" << i + 1 << "]: ";
        cin >> priority;

        processes[i].processNumber = (i + 1);
        processes[i].BT = BT;
        processes[i].priority = priority;
    }

    timeTable = PS(processes, proc);

    printf("\n\nGantt Chart: \n");
    totWT = printGanttChart(timeTable);
    avgWT = totWT / (proc * 1.0);
    printf("Average Waiting Time %0.2f\n\n", avgWT);

    return 0;
}