#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // number of processes
int b; // number of blocks
vector <int> procSize; // size of processes
vector <int> blockSize; // size of blocks

void input(){
    freopen("best.txt", "r", stdin);
    cin >> n >> b;
    procSize.resize(n);
    blockSize.resize(b);

    for (int i = 0; i < n; i++)
        cin >> procSize[i];
    for (int i = 0; i < b; i++)
        cin >> blockSize[i];
}
void bestFit(){
    vector<int> allocation(b, 0);
    vector<bool> flag(b, false);

    cout << "Block No.\tBlock Size\tProcess No.\n";

    for (int i = 0; i < n; i++){
        int bestIdx = -1;
        for (int j = 0; j < b; j++){
            if (!flag[j] && procSize[i] <= blockSize[j] && (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]))
                bestIdx = j;
        }
        if (bestIdx != -1){
            allocation[bestIdx] = i + 1;
            flag[bestIdx] = true;
        }
    }
    for (int i = 0; i < b; i++){
        cout << i + 1 << "\t\t" << blockSize[i] << "\t\t";
        if (allocation[i] == 0)
            cout << "Not allocated" << "\n";
        else
            cout << "P" << allocation[i] << "\n";
    }
}
int main(){
    input();
    bestFit();

    return 0;
}
