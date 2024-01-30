<h1 align="center">Data Structures</h1>
<h2 align="center">Part - 1</h2>

- <h3>Program No.1</h3>
```cpp
#include <iostream>
#define MAXSIZE 100
using namespace std;

int arr[MAXSIZE], listSize = 0;

bool isEmpty() {
    return listSize == 0;
}

void insert(int data, int position) {
    if (listSize == MAXSIZE) {
        cout << "List is Full" << endl;
        return;
    }
    if (position < 1 || position > listSize + 1) {
        cout << "Invalid Position" << endl;
        return;
    }
    for (int i = listSize; i >= position; i--)
        arr[i] = arr[i - 1];
    arr[position - 1] = data;
    listSize++;
}

void remove(int data) {
    int index = -1;
    for (int i = 0; i < listSize; i++) {
        if (arr[i] == data) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Data not found" << endl;
        return;
    }
    for (int i = index; i < listSize - 1; i++)
        arr[i] = arr[i + 1];
    listSize--;
}

void search(int data) {
    for (int i = 0; i < listSize; i++) {
        if (arr[i] == data) {
            cout << "Data found at the position " << i + 1 << endl;
            return;
        }
    }
    cout << "Data not found" << endl;
}

void display() {
    if (isEmpty()) {
        cout << "List is Empty" << endl;
        return;
    }
    for (int i = 0; i < listSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printReverse() {
    if(!isEmpty()) {
        for(int index = listSize-1; index >= 0; index--) {
            cout << arr[index] << " ";
        }
        cout << endl;
    } else {
        cout << "List is Empty" << endl;
    }
}

int main() {
    int N, queryType, data, position;
    cin >> N;
    for(int query = 1; query <= N; query++) {
        cin >> queryType;
        switch(queryType) {
            case 1:
                cin >> data >> position;
                insert(data, position);
                break;
            case 2:
                cin >> data;
                remove(data);
                break;
            case 3:
                cin >> data;
                search(data);
                break;
            case 4:
                display();
                break;
            case 5:
                printReverse();
                break;
        }
    }
    return 0;
}
```
