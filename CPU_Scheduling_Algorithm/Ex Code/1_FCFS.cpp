#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> gq;
void FCFS(int processes_array[], int number_of_process){
    queue<int> processes;
    for(int i=0; i< number_of_process; i++){
        processes.push(processes_array[i]);
    }

    int process_number = 1;
    vector<int> ending_time;
    int previous_endtime = 0;
    while(!processes.empty()){

        int current_process_burst_time = processes.front();
        previous_endtime = previous_endtime + current_process_burst_time;
        ending_time.push_back(previous_endtime);
        gq.push_back({process_number, previous_endtime});
        processes.pop();
    }

    float total_waitng_time = 0;
    for(int i=0; i<number_of_process-1; i++){
        total_waitng_time += ending_time[i];
    }

    float average_waiting_time = (total_waitng_time * 1.0) / (number_of_process * 1.0);
    printf("Average waiting time is : %0.2f\n", average_waiting_time);

    return;
}

void printLine(int gap)
{
    for(int i=0; i<gap*2; i++)
    {
        printf("-");
    }
    printf("|");
}

void printProcessNumber(int processNumber, int gap)
{

    cout << " p" << processNumber;
    for(int i=1; i<gap*2; i++)
    {
        cout<<" ";
    }
}

void printProcessEndingTime(int processEndingTime, int gap)
{

    cout << "  " << processEndingTime;
    for(int i=1; i<gap*2; i++)
    {
        cout<<" ";
    }
}

void printGanntChart(vector<pair<int, int>> gq){
    int length = gq.size();
    pair<int, int> processInfo;
    int gap = 0;
    printf("|");
    for(int i=0; i<length; i++)
    {
        processInfo =  gq[i];
        gap = processInfo.second - gap;
        printLine(gap);
    }
    cout << "\n";
    gap = 0;
    int processNumber;
    for(int i=0; i<length; i++)
    {
        processInfo =  gq[i];
        processNumber = processInfo.first;
        gap = processInfo.second - gap;
        printProcessNumber(processNumber, gap);
    }
    cout << "\n";
    gap = 0;
    printf("|");
    for(int i=0; i<length; i++)
    {
        processInfo =  gq[i];
        gap = processInfo.second - gap;
        printLine(gap);
    }

    cout << "\n";
    gap = 0;
    int processEndingTime;
    for(int i=0; i<length; i++)
    {
        processInfo =  gq[i];
        processEndingTime = processInfo.second;
        gap = processInfo.second - gap;
        printProcessEndingTime(processEndingTime, gap);
    }


}

int main()
{
    int number_of_process;
    cout << "Enter number of process: ";
    cin >> number_of_process;
    int burst_time;
    int processes[number_of_process];

    for(int i=0; i<number_of_process; i++)
    {
        int process_number = i+1;
        cout << "Enter burst time for process "  << process_number << " : ";
        cin >> burst_time;
        processes[i] = burst_time;
    }
    FCFS(processes, number_of_process);
    printf("\n");
    printf("Gannt Chart: \n");
    printGanntChart(gq);
    return 0;
}
