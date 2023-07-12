#include <stdio.h>
#include <bits/stdc++.h> // This is a non-standard header file, and may not be available on all systems.
                         // It includes many commonly-used headers, such as <iostream>, <vector>, <string>, etc.
using namespace std;
struct process
{
    int processNumber;
    int burstTime;
    int arrivalTime;
    int waitingTime;
};

void printProcesses(vector<process> processes)
{
    int length = processes.size();

    for (int i = 0; i < length; i++)
    {
        cout << "Process Number: " << processes[i].processNumber << endl;
        cout << "Burst Time: " << processes[i].burstTime << endl;
        cout << "Arrival Time: " << processes[i].arrivalTime << endl;
        cout << "Waiting Time: " << processes[i].waitingTime << endl;
        cout << endl;
    }
}

vector<process> sort(vector<process> processes) // "sort" is a reserved keyword in C++, so using it as a function name is not recommended.
                                                // It may also cause conflicts with the <algorithm> header file.
{
    int length = processes.size();
    process temp;
    for (int i = 0; i < (length - 1); i++)
    {
        for (int j = i + 1; j < length; j++)
            if (processes[j].burstTime < processes[i].burstTime) // This is a simple bubble sort to sort the processes by their burst times.
            {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
    }

    return processes;
}

vector<int> shortestRemainingJobFirst(vector<process> processes, int timingTable[], int totalBurstTime)
{
    int length;

    for (int i = 0; i < totalBurstTime; i++)
    {
        processes = sort(processes); // Sort the processes by their burst times.
        length = processes.size();
        for (int j = 0; j < length; j++)
        {
            if (processes[j].arrivalTime <= i) // If a process has arrived, decrement its burst time by 1.
            {
                processes[j].burstTime -= 1;
                timingTable[i] = processes[j].processNumber; // Record the process number in the timing table.

                if (processes[j].burstTime <= 0) // If the process has completed its execution, remove it from the list of processes.
                    processes.erase(processes.begin() + j);

                break;
            }
        }
    }

    vector<int> chart;
    for (int i = 0; i < totalBurstTime; i++) // Convert the timing table to a Gantt chart.
    {
        chart.push_back(timingTable[i]);
    }

    return chart;
}

int gapCalculation(vector<int> timingTable, int digit) // This function calculates the gap between two consecutive occurrences of a process in the Gantt chart.
{
    int length = timingTable.size();
    vector<int> posOfDigit; // This vector stores the positions of the process in the Gantt chart.
    for (int i = 0; i < length; i++)
    {
        if (timingTable[i] == digit)
            posOfDigit.push_back(i);
    }

    length = posOfDigit.size();
    int gap = posOfDigit[0];
    for (int i = 1; i < length; i++)
    {
        if (posOfDigit[i] != posOfDigit[i - 1] + 1) // If the current position is not

        {
            gap = gap + (posOfDigit[i] - (posOfDigit[i - 1] + 1));
        }
    }
    // cout << endl;

    return gap;
}

int waitingTime(process process, vector<int> timingTable)
{
    int gap = gapCalculation(timingTable, process.processNumber);
    int time = gap - process.arrivalTime;

    // cout << "Gap Time of Process " <<  process.processNumber << " : " << gap << endl;
    // cout << "Waitng Time of Process " <<  process.processNumber << " : " << time << endl;
    return time;
}

void averageWaitingTimeCalculation(vector<process> processes, vector<int> timingTable)
{
    int length = processes.size();
    int totalWaitingTime = 0;
    for (int i = 0; i < length; i++)
    {
        processes[i].waitingTime = waitingTime(processes[i], timingTable);
        totalWaitingTime += processes[i].waitingTime;
    }

    float averageWaitingTime = (totalWaitingTime * 1.0) / (length * 1.0);
    cout << "Average Waitng Time: " << averageWaitingTime;

    return;
}

void printLine(vector<int> arr)
{
    int length = arr.size();
    printf("|--");
    for (int i = 1; i < length; i++)
    {
        if (arr[i] == arr[i - 1])
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

void printProcessNumber(vector<int> arr)
{
    int i = 0;
    printf("P%d", arr[i]);
    int length = arr.size();
    for (int i = 1; i < length; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            printf("  ");
        }
        else
        {
            printf(" P%d", arr[i]);
        }
    }
    printf("\n");
}

void printEndingTime(vector<int> arr)
{
    printf("0");
    int length = arr.size();
    for (int i = 1; i < length; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            printf("  ");
        }
        else
        {
            printf("  %d", i);
        }
    }
    printf("%d", length);
    printf("\n");
}
void printGanttChart(vector<int> arr)
{
    printLine(arr);
    printProcessNumber(arr);
    printLine(arr);
    printEndingTime(arr);
}

int main()
{
    int numberofProcesses;
    vector<process> processes;
    process p;
    int totalBirstTime = 0;
    cout << "Give the number of processes: ";
    cin >> numberofProcesses;

    for (int i = 0; i < numberofProcesses; i++)
    {

        p.processNumber = (i + 1);
        cout << "Arival Time of process " << (i + 1) << ": ";
        cin >> p.arrivalTime;
        cout << "Burst Time of process " << (i + 1) << ": ";
        cin >> p.burstTime;
        totalBirstTime += p.burstTime;
        processes.push_back(p);
    }

    int timingTable[totalBirstTime];
    memset(timingTable, 0, sizeof(timingTable));
    // int length = processes.size();
    vector<int> processTimeTable;
    processTimeTable = shortestRemainingJobFirst(processes, timingTable, totalBirstTime);
    // int chartLength = processTimeTable.size();

    printGanttChart(processTimeTable);
    averageWaitingTimeCalculation(processes, processTimeTable);

    return 0;
}