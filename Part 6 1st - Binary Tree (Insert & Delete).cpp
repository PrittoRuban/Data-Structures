void insertNode(Node* node, int rootData, int data, char pos)
{
    if (node != nullptr)
    {
        if (node->data == rootData)
        {
            if (pos == 'L' && node->left == nullptr)
            {
                node->left = createNode(data);
            }
            else if (pos == 'R' && node->right == nullptr)
            {
                node->right = createNode(data);
            }
            else
            {
                std::cout << "Left & Right Nodes are already present" << std::endl;
            }
            return;
        }
        insertNode(node->left, rootData, data, pos);
        insertNode(node->right, rootData, data, pos);
    }
}
Node* search(Node* parent, Node* node, int nodeToSearch, char childPos)
{
    if (node != nullptr)
    {
        if (node->data == nodeToSearch)
        {
            Node* temp = node;
            if (node == root && childPos == 'P')
            {
                if (node->left != nullptr && node->right != nullptr)
                {
                    std::cout << "Cannot merge two nodes" << std::endl;
                }
                else if (node->left == nullptr && node->right == nullptr)
                {
                    root = nullptr;
                }
                else if (node->left != nullptr)
                {
                    root = node->left;
                }
                else
                {
                    root = node->right;
                }
                return node;
            }
            if (node->left == nullptr && node->right == nullptr)
            {
                if (childPos == 'L')
                {
                    parent->left = nullptr;
                }
                else if (childPos == 'R')
                {
                    parent->right = nullptr;
                }
            }
            else if (node->left != nullptr && node->right != nullptr)
            {
                std::cout << "Cannot merge two nodes" << std::endl;
            }
            else if (node->left != nullptr && node->right == nullptr)
            {
                if (childPos == 'L')
                {
                    parent->left = node->left;
                }
                else if (childPos == 'R')
                {
                    parent->right = node->left;
                }
            }
            else if (node->left == nullptr && node->right != nullptr)
            {
                if (childPos == 'L')
                {
                    parent->left = node->right;
                }
                else if (childPos == 'R')
                {
                    parent->right = node->right;
                }
            }
            return node;
        }
        Node* ptr = search(node, node->left, nodeToSearch, 'L');
        if (ptr != nullptr)
        {
            return ptr;
        }
        return search(node, node->right, nodeToSearch, 'R');
    }
    return nullptr;
}
void deleteNode(Node* rootNode, int X)
{
    Node* newNode = search(nullptr, rootNode, X, 'P');
    if (newNode == nullptr)
    {
        std::cout << "Not found" << std::endl;
        return;
    }
    if (newNode->left == nullptr || newNode->right == nullptr)
    {
        delete newNode;
    }
}
void printPreorder(Node* node)
{
    if (node != nullptr)
    {
        std::cout << node->data << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }
}
