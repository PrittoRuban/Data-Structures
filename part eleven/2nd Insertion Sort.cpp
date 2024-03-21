/*
Insertion Sort Algorithm
- The program must accept an array of N integers as the input.
- The program must print the N integers without any change in the first line.
- Then the program must sort the N integers using Insertion Sort algorithm and print all the iterations in the process of sorting as the output.

Boundary Condition(s):
- 2 <= N <= 100
- -10^8 <= Each integer value <= 10^8

Input Format:
- The first line contains N.
- The second line contains N integers separated by a space.

Output Format:
- The lines containing all the iterations in the sorting process (insertion sort).

Example Input/Output 1:
Input: 
5
7 2 3 1 -5
Output: 
7 2 3 1 -5
2 7 3 1 -5
2 3 7 1 -5
1 2 3 7 -5
-5 1 2 3 7

Example Input/Output 2:
Input: 
7
-9 12 -18 10 11 13 -20
Output: 
-9 12 -18 10 11 13 -20
-9 12 -18 10 11 13 -20
-18 -9 12 10 11 13 -20
-18 -9 10 12 11 13 -20
-18 -9 10 11 12 13 -20
-18 -9 10 11 12 13 -20
-20 -18 -9 10 11 12 13

Max Execution Time Limit: 50 millisecs
*/

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
    printArray(arr);
    for(int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printArray(arr);
    }
    return 0;
}
