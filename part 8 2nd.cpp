void insert(vector<int> &minHeap, int val) {
    if(minHeap.size()-1== MAXSIZE){
        cout<<"Heap is full" <<endl;
        return;
    }
    minHeap.push_back(val);
    int child = minHeap.size() - 1;
    int parent = child / 2;
    while (child > 1) {
        if (minHeap[child] < minHeap[parent]) {
            int x = minHeap[child];
            minHeap[child] = minHeap[parent];
            minHeap[parent] = x;
            child = parent;
            parent = child / 2;
        } else {
            break;
        }
    }
}

int extractMin(vector<int>&minHeap){
    if(minHeap.size()==1){
        return minHeap[1];
    }
    int x = minHeap[1];
    minHeap[1] = minHeap[minHeap.size() - 1];
    minHeap.pop_back();
    int parent = 1;
    int child;
    while (true) {
        child = 2 * parent;
        if (child >= minHeap.size()) {
            break;
        }
        if (child + 1 < minHeap.size() && minHeap[child + 1] < minHeap[child]) {
            child++;
        }
        if (minHeap[parent] > minHeap[child]) {
            int t = minHeap[parent];
            minHeap[parent] = minHeap[child];
            minHeap[child] = t;
            parent = child;
        } else {
            break;
        }
    }
    return x;
}