// Merge Sort Algorithm
// The program accepts N integers as the input.
// The program sorts the given N integers in ascending order using Merge Sort algorithm
// and prints them as the output.

// Please fill in the blanks with code so that the program runs successfully.

// Example Input/Output 1:
// Input: 8 70 20 10 50 80 90 30 40
// Output: 10 20 30 40 50 70 80 90

// Max Execution Time Limit: 50 millisecs

// TODO: Add your code here


#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int start1 = left;
    int start2 = mid+1;
    int temp[(mid - left +1) + (right - mid)], tempIndex = 0;

    while(start1 <= mid && start2 <= right) {
        if(arr[start1] <= arr[start2]) {
            temp[tempIndex++] = arr[start1++];
        } else {
            temp[tempIndex++] = arr[start2++];
        }
    }

    while(start1 <= mid) {
        temp[tempIndex++] = arr[start1++];
    }

    while(start2 <= right) {
        temp[tempIndex++] = arr[start2++];
    }

    tempIndex = 0;
    for(int index = left; index <= right; index++) {
        arr[index] = temp[tempIndex++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void sort(int arr[], int N) {
    mergeSort(arr, 0, N-1);
}

int main() {
    int N;
    cin >> N;
    int arr[N];
    for(int index = 0; index < N; index++) {
        cin >> arr[index];
    }
    sort(arr, N);
    for(int index = 0; index < N; index++) {
        cout << arr[index] << " ";
    }
    return 0;
}
