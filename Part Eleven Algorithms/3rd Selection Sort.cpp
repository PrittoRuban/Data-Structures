// Selection Sort Algorithm
// The program must accept N integers as the input.
// The program must sort the N integers using Selection Sort and print all the iterations of the sorting process as the output.

// Boundary Condition(s):
// 2 <= N <= 100
// 1 <= Each integer value <= 1000

// Input Format:
// The first line contains N.
// The second line contains N integers separated by a space.

// Output Format:
// The lines containing all the iterations in the sorting process (selection sort).

// Example Input/Output 1:
// Input:
// 5
// 12 6 15 9 10
// Output:
// 6 12 15 9 10
// 6 9 15 12 10
// 6 9 10 12 15

// Example Input/Output 2:
// Input:
// 6
// 26 43 49 30 3 63
// Output:
// 3 43 49 30 26 63
// 3 26 49 30 43 63
// 3 26 30 49 43 63
// 3 26 30 43 49 63
// 3 26 30 43 49 63

// Max Execution Time Limit: 50 millisecs

#include <iostream>
#include <vector>

void printArray(const std::vector<int>& arr) {
    for(int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    for(int i = 0; i < N-1; i++) {
        int min_idx = i;
        for(int j = i+1; j < N; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[min_idx], arr[i]);
        printArray(arr);
    }
    return 0;
}