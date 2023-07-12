#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int pageFaults(int n, int c, const vector<int>& pages) {
    int count = 0;
    vector<int> v;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        auto it = find(v.begin(), v.end(), pages[i]);
        if (it == v.end()) {
            if (v.size() == c) {
                // If memory is full, remove the least frequently used page
                mp[v[0]]--;  // Decrease the frequency
                v.erase(v.begin());  // Remove the first element as it is least frequently used
            }
            v.push_back(pages[i]);  // Add the element at the end of memory
            mp[pages[i]]++;  // Increase its frequency
            count++;  // Increment the count for page faults
        } else {
            int page = *it;
            v.erase(it);  // Remove the element
            v.push_back(page);  // Add it at the end
            mp[page]++;  // Increase its frequency
        }

        int k = v.size() - 2;
        while (k >= 0 && mp[v[k]] > mp[v[k + 1]]) {
            // Sort the pages based on their frequency and time at which they arrive
            // If frequency is the same, the page arriving first must be placed first
            swap(v[k], v[k + 1]);
            k--;
        }
    }

    return count;
}

int main() {
    vector<int> pages = {1, 2, 3, 4, 2, 1, 5};
    int n = pages.size();
    int c = 3;

    // Calculate the page faults and page hits
    int faultCount = pageFaults(n, c, pages);
    int hitCount = n - faultCount;

    // Output the results
    cout << "Page Faults = " << faultCount << endl;
    cout << "Page Hits = " << hitCount << endl;

    return 0;
}
