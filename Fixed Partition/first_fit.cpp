#include <iostream>
#include <vector>

using namespace std;

int n; // number of processes
int b; // number of blocks
vector<int> procSize; // size of processes
vector<int> blockSize; // size of blocks

void input(){
    freopen("first.txt", "r", stdin);
    cin >> n >> b;
    procSize.resize(n);
    blockSize.resize(b);

    for (int i = 0; i < n; i++)
        cin >> procSize[i];
    for (int i = 0; i < b; i++)
        cin >> blockSize[i];
}

void firstFit(){
    vector<int> allocation(b, 0); // vector of size b and each value has 0
    vector<bool> flag(b, false);  // vector of size b and each value has false

    cout << "Block No.\tBlock Size\tProcess No.\n";

    for (int i = 0; i < n; i++){
        for (int j = 0; j < b; j++){
            if (!flag[j] && procSize[i] <= blockSize[j]){
                allocation[j] = i + 1;
                flag[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < b; i++){
        cout << i + 1 << "\t\t" << blockSize[i] << "\t\t";
        if (allocation[i] == 0)
            cout << "Not allocated";
        else
            cout << "P" << allocation[i];
        cout << "\n";
    }
}
int main(){
    input();
    firstFit();
    return 0;
}
