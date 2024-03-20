void BinarySearchTree::insert(int data) {
    Node *newNode = new Node(data);
    if (root == NULL) {
        root = newNode;
        return;
    }
    Node *current = root, *parent = NULL;
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

bool BinarySearchTree::search(int data) {
    Node *current = root;
    while (current != NULL) {
        if (data == current->data) {
            return true;
        }
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

Node* deleteRec(Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data) {
        root->left = deleteRec(root->left, data);
    } else if (data > root->data) {
        root->right = deleteRec(root->right, data);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteRec(root->right, temp->data);
    }
    return root;
}

void BinarySearchTree::deleteNode(int data) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }
    if (!search(data)) {
        cout << "Node not found" << endl;
        return;
    }
    root = deleteRec(root, data);
}

void preOrderTraversal(Node *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

void BinarySearchTree::printPreOrder() {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }
    preOrderTraversal(root);
    cout << endl;
}
