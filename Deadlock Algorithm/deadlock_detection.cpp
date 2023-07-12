#include <bits/stdc++.h>
using namespace std;

int n, res, temp;
vector <vector<int>> alloc;
vector <vector<int>> request;
vector <int> available;

void input(){
    freopen("deadlock.txt", "r", stdin);
    cin >> n;   // number of processes
    cin >> res; // number of resource type

    alloc.resize(n, vector<int>(res));
    request.resize(n, vector<int>(res));
    available.resize(res);

    // allocation matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < res; j++)
            cin >> alloc[i][j];
    }
    // request matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < res; j++)
            cin >> request[i][j];
    }
    // available resources
    for (int i = 0; i < res; i++)
        cin >> available[i];
}
bool isSafe(){
    bool visitedProc[n] = {0}; // initially all processes are in deadlock condition
    bool finish[n] = {0};
    // a copy of available resources
    int work[res];
    for(int i = 0; i < res; i++)
        work[i] = available[i];

    int count = 0;
    while (count < n){
        bool found = false;

        for (int i = 0; i < n; i++){
            if(finish[i] == 0){
                int j;
                for(j = 0; j < res; j++){
                    if(request[i][j] > work[j])
                        break;
                }
                if(j == res){
                    for(int k = 0; k < res; k++){
                        work[k] = work[k] + alloc[i][k];
                    }
                    finish[i] = 1;
                    visitedProc[count++] = 1; // release processes
                    found = true;
                }
            }
        }
        if(found == false){
            cout << "Deadlock Detected!! \n";
            cout << "The processes < ";
            for(int i = 0; i < n; i++){
                if(visitedProc[i] == 0){
                    cout << "P" << i << " ";
                }
            }
            cout << "> are in Deadlock condition!\n";
            return false;
        }
    }
    cout << "There is no Deadlock!\n";
    return true;;
}
int main(){
    input();
    isSafe();

    return 0;
}

/* Sample input:

    5 3

    0 1 0
    2 0 0
    3 0 3
    2 1 1
    0 0 2

    0 0 0
    2 0 2
    0 0 0
    1 0 0
    0 0 2

    0 0 0

*/
