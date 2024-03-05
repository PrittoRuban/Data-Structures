bool isEmpty() {
    return (top == -1);
}

void push(int value) {
    if (top >= MAXSIZE - 1) {
        cout << "Overflow" << endl;
    } else {
        arr[++top] = value;
    }
}

int pop() {
    if (isEmpty()) {
        cout << "Underflow" << endl;
        return 0;
    } else {
        return arr[top--];
    }
}

int peek() {
    if (isEmpty()) {
        cout << "Underflow" << endl;
        return 0;
    } else {
        return arr[top];
    }
}