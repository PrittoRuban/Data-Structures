bool Queue::isEmpty() {
    return (head == NULL);
}

void Queue::add(int data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    cout << "Inserted: " << data << endl;
}

int Queue::poll() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return 0;
    } else {
        Node* temp = head;
        int polledData = temp->data;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
        return polledData;
    }
}

void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
