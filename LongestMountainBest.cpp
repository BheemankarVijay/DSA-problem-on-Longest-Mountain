#include <iostream>
#include <vector>
using namespace std;

int findPeakBinary(const vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid overflow.
        
        if ((mid == 0 || arr[mid] >= arr[mid-1]) && 
            (mid == arr.size() - 1 || arr[mid] >= arr[mid+1])) {
            return mid; // Peak found.
        }
        else if (mid > 0 && arr[mid] < arr[mid-1]) {
            high = mid - 1; // Move left.
        } else {
            low = mid + 1; // Move right.
        }
    }
    return high; // No peak found (unlikely in valid input).
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

    int peakIndex = findPeakBinary(arr);
    cout << "Peak element found at index: " << peakIndex << endl;
    return 0;
}
// The time complexity of this code is O(logn) because we are using binary search.