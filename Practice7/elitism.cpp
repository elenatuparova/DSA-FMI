#include <iostream> 
#include <iomanip>
using namespace std;

int areBalanced(int maxSize, int minSize)
{
    if (maxSize > minSize)
    {
        return 1;
    }
    if (maxSize < minSize)
    {
        return -1;
    }
    return 0;
}

class MaxHeap
{
public:
    MaxHeap(int N)
    {
        heap = new double[N];
        size = 0;
        maxSize = N;
    }
    
    void siftUp(int idx)
    {
        while (idx>0 && heap[parent(idx)] < heap[idx])
        {
            swap(heap[parent(idx)], heap[idx]);
            idx = parent(idx);
        }
    }

    void siftDown(int idx)
    {
        int maxIdx = idx;
        int left = leftChild(idx);
        if (left < size && heap[left] > heap[maxIdx])
        {
            maxIdx = left;
        }
        int right = rightChild(idx);
        if (right < size && heap[right] > heap[maxIdx])
        {
            maxIdx = right;
        }
        if (idx != maxIdx)
        {
            swap(heap[idx], heap[maxIdx]);
            siftDown(maxIdx);
        }
    }

    void print()
    {
        for (int i = 0; i<size; i++)
        {
            cout << heap[i] << " ";
        }
    }

    double getTop()
    {
        if (size <= 0)
        {
            return 0;
        }
        return heap[0];
    }

    int getSize()
    {
        return size;
    }

    void insert(double input)
    {
        if (size < maxSize)
        {
            size++;
            heap[size - 1] = input;
            siftUp(size - 1);
        }
    }

    double extractTop()
    {
        double toDelete = -1;
        if (size)
        {
            toDelete = heap[0];
            swap(heap[0], heap[size - 1]);
            size--;
            siftDown(0);
        }
        return toDelete;
    }

protected:
    double* heap;
    int size;
    int maxSize;
    
    int leftChild(int parent)
    {
        return 2 * parent + 1;
    }

    int rightChild(int parent)
    {
        return 2 * (parent + 1);
    }

    int parent(int child)
    {
        if (child <= 0)
        {
            return -1;
        }
        return (child - 1) / 2;
    }
};

class MinHeap
{
public:
    MinHeap(int N)
    {
        heap = new double[N];
        size = 0;
        maxSize = N;
    }

    void siftUp(int idx)
    {
        while (idx>0 && heap[parent(idx)] > heap[idx])
        {
            swap(heap[parent(idx)], heap[idx]);
            idx = parent(idx);
        }
    }

    void siftDown(int idx)
    {
        int minIdx = idx;
        int left = leftChild(idx);
        if (left < size && heap[left] < heap[minIdx])
        {
            minIdx = left;
        }
        int right = rightChild(idx);
        if (right < size && heap[right] < heap[minIdx])
        {
            minIdx = right;
        }
        if (idx != minIdx)
        {
            swap(heap[idx], heap[minIdx]);
            siftDown(minIdx);
        }
    }

    void print()
    {
        for (int i = 0; i<size; i++)
        {
            cout << heap[i] << " ";
        }
    }

    double getTop()
    {
        if (size <= 0)
        {
            return 0;
        }
        return heap[0];
    }

    int getSize()
    {
        return size;
    }

    void insert(double input)
    {
        if (size < maxSize)
        {
            size++;
            heap[size - 1] = input;
            siftUp(size - 1);
        }
    }

    double extractTop()
    {
        double toDelete = -1;
        if (size)
        {
            toDelete = heap[0];
            swap(heap[0], heap[size - 1]);
            size--;
            siftDown(0);
        }
        return toDelete;
    }

protected:
    double* heap;
    int size;
    int maxSize;
    
    int leftChild(int parent)
    {
        return 2 * parent + 1;
    }

    int rightChild(int parent)
    {
        return 2 * (parent + 1);
    }

    int parent(int child)
    {
        if (child <= 0)
        {
            return -1;
        }
        return (child - 1) / 2;
    }
};

void getMedian(double input, double &currentMedian, MaxHeap &max, MinHeap &min)
{
    int balance = areBalanced(max.getSize(), min.getSize());
    if (balance == 1)
    {
        if (input < currentMedian)
        {
            double toMove = max.extractTop();
            min.insert(toMove);
            max.insert(input);
        }
        else
        {
            min.insert(input);
        }
        currentMedian = (min.getTop() + max.getTop()) / 2.0;
    }
    else if (balance == -1)
    {
        if (input < currentMedian)
        {
            max.insert(input);
        }
        else
        {
            double toMove = min.extractTop();
            max.insert(toMove);
            min.insert(input);
        }
        currentMedian = (min.getTop() + max.getTop()) / 2.0;
    }
    else if (balance == 0)
    {
        if (input < currentMedian)
        {
            max.insert(input);
            currentMedian = max.getTop();
        }
        else
        {
            min.insert(input);
            currentMedian = min.getTop();
        }
    }
    cout << setprecision(1) << currentMedian << endl;
}

int main()
{
    int N = 0;
    cin >> N;
    double input = 0;
    double currentMedian = 0;
    MaxHeap  maxHeap(N);
    MinHeap minHeap(N);
    cout << fixed;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        getMedian(input, currentMedian, maxHeap, minHeap);
    }
    return 0;
}
