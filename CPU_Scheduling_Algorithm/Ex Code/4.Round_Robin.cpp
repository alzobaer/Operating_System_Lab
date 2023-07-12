#include <bits/stdc++.h>
using namespace std;

struct process
{
       int processNumber;
       int burstTime;
};

int waitingTimeForProcess(vector<int> timeTable, int processNumber)
{
       bool previousPresent = false;
       int previousEnd = 0;
       int length = timeTable.size();
       int waitingTime = 0;

       for (int i = 0; i < length; i++)
       {
              if (timeTable[i] == processNumber && !previousPresent)
              {
                     previousPresent = true;
                     waitingTime = waitingTime + i;

                     while (timeTable[i + 1] == timeTable[i])
                     {
                            i++;
                     }

                     previousEnd = (i + 1);
              }

              else if (timeTable[i] == processNumber && previousPresent)
              {
                     waitingTime = waitingTime + (i - previousEnd);

                     while (timeTable[i + 1] == timeTable[i])
                     {
                            i++;
                     }

                     previousEnd = (i + 1);
              }
       }

       return waitingTime;
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

void printEndingTime(vector<int> timeTable)
{
       printf("0");
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
              }
       }
       printf("%d", length);
       printf("\n");

       return;
}
float printGanttChart(vector<int> timeTable, int numberOfProcess)
{
       float totalWaitingTime = 0;
       int waitingTime = 0;
       printLine(timeTable);
       printProcessNumber(timeTable);
       printLine(timeTable);
       printEndingTime(timeTable);

       for (int i = 1; i <= numberOfProcess; i++)
       {
              waitingTime += waitingTimeForProcess(timeTable, i);
       }
       // printf("Waiting Time %d\n", waitingTime);
       totalWaitingTime = (waitingTime * 1.0);
       // printf("Total Waiting Time in gant chart function %f\n", totalWaitingTime);
       return totalWaitingTime;
}

vector<int> RoundRobin(queue<process> processes, int quantam)
{
       vector<int> timeTable;
       int length = processes.size();

       while (!processes.empty())
       {
              process p = processes.front();

              for (int i = 0; i < quantam; i++)
              {
                     timeTable.push_back(p.processNumber);
                     p.burstTime = p.burstTime - 1;
                     if (p.burstTime == 0)
                            break;
              }
              processes.pop();
              if (p.burstTime != 0)
                     processes.push(p);
       }

       return timeTable;
}

int main()
{
       queue<process> processes;
       vector<int> timeTable;
       int quantam;
       int numberOfProcess;
       float totalWaitingTime;
       float averageWaitingTime;
       process temp;
       int burstTime;
       printf("How many number of process: ");
       scanf("%d", &numberOfProcess);

       for (int i = 0; i < numberOfProcess; i++)
       {
              printf("Burst Time of process %d: ", (i + 1));
              scanf("%d", &burstTime);
              temp.processNumber = (i + 1);
              temp.burstTime = burstTime;
              processes.push(temp);
       }

       printf("What is the quantam number: ");
       scanf("%d", &quantam);
       timeTable = RoundRobin(processes, quantam);

       /*printf("Time Table: \n");
       int length = timeTable.size();
       for(int i=0; i<length; i++)
       {
           printf("%d ", timeTable[i]);
       }
       cout << endl;*/
       printf("Gantt Chart is: \n");
       totalWaitingTime = printGanttChart(timeTable, numberOfProcess);
       printf("Total waiting time is %0.2f\n", totalWaitingTime);
       averageWaitingTime = totalWaitingTime / numberOfProcess;
       printf("Average waiting time is %0.2f\n", averageWaitingTime);

       return 0;
}