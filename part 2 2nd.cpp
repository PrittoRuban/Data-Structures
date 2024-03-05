bool Stack::isEmpty() {
    return (head == NULL);
}

void Stack::push(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return 0;
    } else {
        Node* temp = head;
        int poppedData = temp->data;
        head = head->next;
        delete temp;
        return poppedData;
    }
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack Empty" << endl;
        return 0;
    } else {
        return head->data;
    }
}