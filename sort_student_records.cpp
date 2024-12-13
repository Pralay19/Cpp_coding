#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort by section lexicographically and by roll number numerically
bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    // Vector to store student records
    vector<pair<string, int>> records;
    
    // Input handling
    string section;
    int roll;
    while (cin >> section >> roll) {
        records.push_back(make_pair(section, roll));
    }
    
    // Sort the records using the custom comparator
    sort(records.begin(), records.end(), compare);
    
    // Output the sorted records
    for (const auto& record : records) {
        cout << record.first << " " << record.second << endl;
    }
    
    return 0;
}
