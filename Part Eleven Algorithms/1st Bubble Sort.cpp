/*
Bubble Sort Algorithm The program must accept N integers as the input.
The program must sort the N integers using Bubble Sort algorithm and print all the iterations in the sorting process as the output.
Boundary Condition(s): 2 <= N <= 20
1 <= Each integer value <= 10^8
Input Format: The first line contains N. The second line contains N integers separated by a space.
Output Format: The lines containing all the iterations in the sorting process(bubble sort).
Example Input/Output 1:
Input: 5
50 40 30 20 10
Output: 
40 50 30 20 10
40 30 50 20 10
40 30 20 50 10
40 30 20 10 50
30 40 20 10 50
30 20 40 10 50
30 20 10 40 50
20 30 10 40 50
20 10 30 40 50
10 20 30 40 50
Example Input/Output 2:
Input: 5
45 22 34 79 23
Output: 
22 45 34 79 23
22 34 45 79 23
22 34 45 23 79
22 34 23 45 79
22 23 34 45 79
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
    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < N-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
            printArray(arr);
        }
    }
    return 0;
}