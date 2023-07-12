#include <bits/stdc++.h>
using namespace std;

int pages;  // number of pages
int frames;  // number of frames
vector <int> page_seq; // page sequences

void input(){
	freopen("fifo.txt", "r", stdin);
	cin >> pages >> frames;
	page_seq.resize(pages);

	for(int i = 0; i < pages; i++)
		cin >> page_seq[i];

	cout << "Page Sequence: ";
	for(int i = 0; i < pages; i++)
		cout << page_seq[i] << " ";
	cout << "\nNumber of Frames: " << frames;
}
int fifo(){
	int page_faults = 0;
	queue <int> frame_queue;
	map <int, bool> is_present;

	for(int i = 0; i < pages; i++){
		int current_page = page_seq[i];

		if(!is_present[current_page]){
			page_faults++;

			if(frame_queue.size() == frames){
				int page_to_remove = frame_queue.front();
				frame_queue.pop();
				is_present[page_to_remove] = false;
			}
			frame_queue.push(current_page);
			is_present[current_page] = true;
		}
	}
	return page_faults;
}

int main(){
	input();
	int page_faults = fifo();
	cout << "\nTotal number of page faults: " << page_faults << "\n";
	return 0;
}
