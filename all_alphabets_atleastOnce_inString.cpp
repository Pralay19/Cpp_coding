#include <bits/stdc++.h>
using namespace std;

int least_size(string str, int arr[26]) {
    int n = str.size();
    int i = 0, j = 0, count = 0;
    int minLen = INT_MAX;

    

    // First loop to find the first valid window containing all characters
    while (j < n) {
        if (arr[str[j] - 'A'] == 0) {
            count++;
        }
        arr[str[j] - 'A']++;//updating in freq array
        j++;

        // When all characters are present, start minimizing the window
        while (count == 26) {
            minLen = min(minLen, j - i);
            arr[str[i] - 'A']--;
            if (arr[str[i] - 'A'] == 0) {
                count--;
            }
            i++;
        }
    }

    return (minLen == INT_MAX) ? -1 : minLen;
}

int main() {
    string str;
    cin >> str;
    int arr[26] = {0};
    int result = least_size(str, arr);
    if (result != -1)
        cout << result;
    else
        cout << "No substring contains all characters";
    return 0;
}
