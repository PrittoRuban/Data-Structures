void insert(vector<int> &maxHeap, int val) {
    if(maxHeap.size()-1 == MAXSIZE){
        cout<<"Heap is full" <<endl;
        return;
    }
    maxHeap.push_back(val);
    int child = maxHeap.size() - 1;
    int parent = child / 2;
    while (child > 1 && maxHeap[parent] < maxHeap[child]) {
        swap(maxHeap[child], maxHeap[parent]);
        child = parent;
        parent = child / 2;
    }
}

int extractMax(vector<int>&maxHeap){
    if(maxHeap.size() <= 1){
        cout << "Heap is empty" << endl;
        return -1;
    }
    int maxVal = maxHeap[1];
    maxHeap[1] = maxHeap[maxHeap.size() - 1];
    maxHeap.pop_back();
    int parent = 1;
    int child;
    while (true) {
        child = 2 * parent;
        if (child >= maxHeap.size()) {
            break;
        }
        if (child + 1 < maxHeap.size() && maxHeap[child + 1] > maxHeap[child]) {
            child++;
        }
        if (maxHeap[parent] >= maxHeap[child]) {
            break;
        }
        swap(maxHeap[parent], maxHeap[child]);
        parent = child;
    }
    return maxVal;
}