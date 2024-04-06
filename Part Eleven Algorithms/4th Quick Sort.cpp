/*
Quick Sort Algorithm
The program must accept an array of N integers as the input.
The program must sort the N integers using Quick Sort algorithm.
It must print the state of the array whenever a swap occurs by selecting the first element as the pivot in the quick sort algorithm.
Boundary Condition(s):
2 <= N <= 20
1 <= Each integer value <= 10^5
Example Input/Output 1:
Input: 6 35 73 39 71 98 15
Output: 15 73 39 71 98 35
    15 35 39 71 98 73
    15 35 39 71 73 98
Example Input/Output 2:
Input: 5 40 50 10 20 30
Output: 30 50 10 20 40
    30 20 10 50 40
    30 20 10 40 50
Max Execution Time Limit: 50 millisecs
*/


#include <bits/stdc++.h>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) return j;
        swap(arr[i], arr[j]);
        printArray(arr);
    }
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quickSort(arr, low, pivot_index);
        quickSort(arr, pivot_index + 1, high);
    }
}

int main(int argc, char** argv) {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, N - 1);
    return 0;
}
