#include <iostream>
#include <vector>
using namespace std;

int findPeakBruteForce(const vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 0; // Single element is always a peak.
    if (arr[0] >= arr[1]) return 0; // First element is a peak.
    if (arr[n-1] >= arr[n-2]) return n-1; // Last element is a peak.

    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            return i; // Peak found.
        }
    }
    return -1; // No peak found (unlikely for valid input).
}

int main() {
    int n;
    cout << "Enter the number of elements in the vector: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int peakIndex = findPeakBruteForce(arr);
    cout << "Peak element found at index: " << peakIndex << endl;
    return 0;
}