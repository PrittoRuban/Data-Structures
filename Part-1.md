<h1 align="center">Data Structures</h1>
<h2 align="center">Part - 1</h2>


- <h3>Program No.1</h3>
<p>
Array Implementation of List ADT
Implement the List ADT using an array by implementing the following functions.
</p>
<p>
bool isEmpty()
It returns true if the list is empty. Else, it returns false.
</p>
<p>
void insert(int data, int position)
It inserts the given data at the given position in the list.
If the list is full, then it must print "List is Full".
If the position is invalid, then it must print "Invalid Position".
A valid position is from 1 to X+1 (where X = size of the list).
</p>
<p>
void remove(int data)
If the data is present in the list, then it removes the first occurrence of the data from the list.
Else, it must print "Data not found".
</p>
<p>
void search(int data)
If the data is present in the list, then it must print "Data found at the position" followed by the position of the first occurrence of the data.
Else, it must print "Data not found".
</p>
<p>
void display()
If the list is not empty, then it prints all data in the list separated by a space.
Else, it must print "List is Empty".
</p>
<p>
The query type can be any one of the following types.
1 - Insert
2 - Delete
3 - Search
4 - Display
5 - Print Reverse
Note: The size of the list is always 100.
IMPORTANT: Do not implement the function printReverse() as it is already implemented.
</p>
<p>
Example Input/Output 1:
Input:
31
1 10
1 1
20
2 1
30
3 1
40
1 1
50
1 4
5
3 10
3 20
3 30
3 40
3 50
3 60
2 10
4
2 20
4
2 30
4
2 40
4
2 50
4
2 60
4
1 100
1 1
200
1 1
300
3 1
400
5
4
5
Output:
50 40 10 20 30
30 20 10 40 50
Data found at the position 3
Data found at the position 4
Data found at the position 5
Data found at the position 2
Data found at the position 1
Data not found
50 40 20 30 50 40 30 50 40 50
List is Empty
Data not found
List is Empty
Invalid Position
200 100 300 300 100 200
</p>

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
