#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap;
    bool isMaxHeap; // true for max heap, false for min heap

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    void heapifyDown(int i) {
        int l = left(i), r = right(i), extreme = i;

        if (isMaxHeap) {
            if (l < heap.size() && heap[l] > heap[extreme]) extreme = l;
            if (r < heap.size() && heap[r] > heap[extreme]) extreme = r;
        } else {
            if (l < heap.size() && heap[l] < heap[extreme]) extreme = l;
            if (r < heap.size() && heap[r] < heap[extreme]) extreme = r;
        }

        if (extreme != i) {
            swap(heap[i], heap[extreme]);
            heapifyDown(extreme);
        }
    }

    void heapifyUp(int i) {
        while (i != 0 && 
              ((isMaxHeap && heap[parent(i)] < heap[i]) ||
               (!isMaxHeap && heap[parent(i)] > heap[i]))) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    Heap(bool maxHeap = true) { isMaxHeap = maxHeap; }

    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int extractTop() {
        if (heap.empty()) throw runtime_error("Heap is empty!");
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return root;
    }

    int getTop() {
        if (heap.empty()) throw runtime_error("Heap is empty!");
        return heap[0];
    }

    bool empty() { return heap.empty(); }

    void display() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};


class PriorityQueue {
private:
    Heap maxHeap;
public:
    PriorityQueue() : maxHeap(true) {}

    void insert(int priority) {
        maxHeap.insert(priority);
    }

    int extractHighestPriority() {
        return maxHeap.extractTop();
    }

    void display() {
        cout << "Priority Queue (as heap): ";
        maxHeap.display();
    }
};


void heapSort(vector<int>& arr) {
    Heap maxHeap(true);
    for (int val : arr)
        maxHeap.insert(val);
    for (int i = arr.size() - 1; i >= 0; i--)
        arr[i] = maxHeap.extractTop();
}


int main() {
    cout << "==============================" << endl;
    cout << "       HEAP DEMONSTRATION     " << endl;
    cout << "==============================" << endl;

    int n;
    cout << "Enter number of elements for the heap: ";
    cin >> n;

    Heap h(true); // max heap
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        h.insert(val);
    }

    cout << "\nHeap elements: ";
    h.display();

    cout << "Extracted max: " << h.extractTop() << endl;
    cout << "Heap after extraction: ";
    h.display();

    cout << "\n==========================" << endl;
    cout << "      PRIORITY QUEUE      " << endl;
    cout << "==========================" << endl;

    PriorityQueue pq;
    int m;
    cout << "Enter number of elements for the priority queue: ";
    cin >> m;

    cout << "Enter priorities: ";
    for (int i = 0; i < m; i++) {
        int val; cin >> val;
        pq.insert(val);
    }

    pq.display();
    cout << "Extracted highest priority: " << pq.extractHighestPriority() << endl;
    pq.display();

    cout << "\n=========================" << endl;
    cout << "        HEAP SORT        " << endl;
    cout << "=========================" << endl;

    int s;
    cout << "Enter number of elements to sort: ";
    cin >> s;

    vector<int> arr(s);
    cout << "Enter " << s << " elements: ";
    for (int i = 0; i < s; i++) cin >> arr[i];

    heapSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
