#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

int main() {
    freopen("lru.txt", "r", stdin);

    // Read input frame size and page size
    int frame_size;
    int page_size;
    cin >> page_size >> frame_size;

    // Read the page sequence
    vector<int> page_seq(page_size);
    for (int i = 0; i < page_size; i++)
        cin >> page_seq[i];

    // Initialize data structures
    map<int, list<int>::iterator> pages;  // Map to track page numbers and their position in the list

    list<int> page_list;  // List to maintain the page order
    int faults = 0;  // Counter to track page faults

    // Process the page sequence
    for (int i = 0; i < page_size; i++) {
        int page = page_seq[i];

        // Check if the page is already in memory
        if (pages.find(page) != pages.end()) {  //If the element with the specified key is found, i.e., pages.find(page) does not return pages.end()
            // Page found, so remove its position from the list
            page_list.erase(pages[page]);
        }
        else {
            // Page not found, so it's a page fault
            if (pages.size() >= frame_size) {
                // If the page list is full, remove the least recently used page
                int lru_page = page_list.front();
                //cout << lru_page << " ";
                pages.erase(lru_page);
                page_list.pop_front();
            }
            faults++;
        }

        // Add the page to the end of the list and update its position in the map
        page_list.push_back(page);
        auto last = page_list.end();
        last--;
        pages[page] = last;
        //cout << distance(page_list.begin(), pages[page]) << " ";  // print position of the map
    }

    // Output the total number of page faults
    cout << "Total page faults = " << faults << endl;
	//cout << page_list.size();
    return 0;
}
