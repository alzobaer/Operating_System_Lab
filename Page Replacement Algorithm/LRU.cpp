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
    // Map to track page numbers and their position in the list
    map<int, list<int>::iterator> pages;

    list<int> page_list;  // List to maintain the page order
    int faults = 0;  // Counter to track page faults

    // Process the page sequence
    for (int i = 0; i < page_size; i++) {
        int page = page_seq[i];

        // Check if the page is already in memory
        if (pages.find(page) != pages.end()) {
            // Page found, so remove its position from the list
            page_list.erase(pages[page]);
        }
        else {
            // Page not found, so it's a page fault
            if (pages.size() >= frame_size) {
                // If the page list is full, remove the least recently used page
                int lru_page = page_list.front();
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
    }
    cout << "Total page faults = " << faults << endl;

    return 0;
}
