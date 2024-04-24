#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void parallel_bubble_sort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
#pragma omp parallel for shared(arr, swapped)
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // If no swap occurred, the array is already sorted
    }
}

int main() {
    // Example usage
    vector<int> arr = {5, 3, 4, 1,2};

    cout << "Before sorting: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    parallel_bubble_sort(arr);

    cout << "After sorting: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
