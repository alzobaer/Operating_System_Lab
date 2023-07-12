#include <bits/stdc++.h>
using namespace std;

int pages;  // number of pages
int frames;  // number of frames
vector <int> page_seq; // page sequences

void input(){
	freopen("fifo.txt", "r", stdin);
	cin >> pages >> frames;
	page_seq.resize(pages); // Resize vector to accommodate the number of pages

	for(int i = 0; i < pages; i++)
		cin >> page_seq[i];

	cout << "Page Sequence: ";
	for(int i = 0; i < pages; i++)
		cout << page_seq[i] << " ";

	cout << "\nNumber of Frames: " << frames;
}

int fifo(){
	int page_faults = 0;
	queue <int> frame_queue;     //queue to store the frames
	map <int, bool> is_present;  // map to track the presence of pages in the frames

	for(int i = 0; i < pages; i++){
		int current_page = page_seq[i];

		// check there exist page fault
		if(!is_present[current_page]){
			page_faults++;

			// Check if the frame queue is full
			if(frame_queue.size() == frames){
				int page_to_remove = frame_queue.front(); // Get the oldest page from the front of the frame queue
				frame_queue.pop(); // Remove the oldest page from the frame queue
				is_present[page_to_remove] = false; // Mark the removed page as not present in the frames
			}

			frame_queue.push(current_page); // Push the current page to the frame queue
			is_present[current_page] = true; // Mark the current page as present in the frames
		}
	}
	return page_faults; //total number of page faults
}

int main(){
	input();
	int page_faults = fifo();
	cout << "\nTotal number of page faults: " << page_faults << "\n";
	return 0; //
}
/*
	sample input:

	15 3
	7 0 1 2 0 3 0 4 2 3 0 3 1 2 0

*/
