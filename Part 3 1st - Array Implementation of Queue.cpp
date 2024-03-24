bool isEmpty() {
    return (qsize == 0);
}

void add(int value) {
    if (qsize >= MAXSIZE) {
        cout << "Queue is full" << endl;
    } else {
        int rear = (front + qsize) % MAXSIZE;
        arr[rear] = value;
        qsize++;
    }
}

int poll() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return 0;
    } else {
        int value = arr[front];
        front = (front + 1) % MAXSIZE;
        qsize--;
        return value;
    }
}

int peek() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return 0;
    } else {
        return arr[front];
    }
}
