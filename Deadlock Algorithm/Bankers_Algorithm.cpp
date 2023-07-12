#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> alloc, maxNeed, remNeed;
vector <int> available; // currently available
int n;  // number of processes
int res; // number of resource type

void input(){
	freopen("bankers.txt", "r", stdin);
	cin >> n >> res;

	alloc.resize(n, vector<int> (res));
	maxNeed.resize(n, vector<int> (res));
	remNeed.resize(n, vector<int> (res));
	available.resize(res);

	// allocation matrix
	for(int i = 0; i < n; i++){
		for(int j = 0; j < res; j++){
			cin >> alloc[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < res; j++){
			cin >> maxNeed[i][j];
		}
	}
	for(int i = 0; i < res; i++){
		cin >> available[i];
	}
}

void calculateNeed(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < res; j++){
			remNeed[i][j] = maxNeed[i][j] - alloc[i][j];
		}
	}
}

bool isSafe(){
	int safeSeq[n];
	bool finish[n] = {0};
    // copy of available resources
    int work[res];
    for(int i = 0; i < res; i++){
		work[i] = available[i];
    }

	int count = 0;
	while(count < n){
		bool found = false;

		for(int i = 0; i < n; i++){
			if(finish[i] == 0){
				int j;
				for(j = 0; j < res; j++){
					if(remNeed[i][j] > work[j])
						break;
				}

				if(j == res){
					for(int k = 0; k < res; k++){
						work[k] = work[k] + alloc[i][k];
					}
					safeSeq[count++] = i;
					finish[i] = 1;
					found = true;
				}
			}
		}
		if(found == false){
			cout << "System is not in Safe state";
			return false;
		}
	}
	cout << "System is in Safe state: \nSafe sequence is: < ";
	for(int i = 0; i < n; i++){
		cout << "P" << safeSeq[i] << " ";
	}
	cout << ">\n";

	return true;
}
int main(){
	input();
	calculateNeed();
	isSafe();
	return 0;
}

/*
	5 4

	0 0 1 2
	1 0 0 0
	1 3 5 4
	0 6 3 2
	0 0 1 4

	0 0 1 2
	1 7 5 0
	2 3 5 6
	0 6 5 2
	0 6 5 6

	1 5 2 0

*/
