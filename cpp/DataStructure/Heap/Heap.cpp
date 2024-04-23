#include <iostream>

class MaxHeap
{
    private:
        int* arr;
        int maxSize;
        int heapSize;

        void swap(int x, int y)
        {
            int temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
        }

    public:
        MaxHeap(int maxSize)
        {
            heapSize = 0;
            this->maxSize = maxSize;
            arr = new int[maxSize];
        }

        int parentIndex(int i)
        {
            return (i-1)/2;
        }

        int leftChildIndex(int i)
        {
            return 2*i+1;
        }

        int rightChildIndex(int i)
        {
            return 2*i+2;
        }

        int getMax()
        {
            return arr[0];
        }

        int size()
        {
            return heapSize;
        }

        void heapfy(int i)
        {
            int left = leftChildIndex(i);
            int right = rightChildIndex(i);
            int largest = i;

            if(left < heapSize && arr[left] > arr[i]) largest = left;
            if(right < heapSize && arr[right] > arr[largest]) largest = right;
            if (largest != i)
            {
                swap(i, largest);
                heapfy(largest);
            }
        }

        void increaseKey(int index, int newValue)
        {
            arr[index] = newValue;
            while (index != 0 && arr[index] > arr[parentIndex(index)])
            {
                swap(index, parentIndex(index));
                index = parentIndex(index);
            }
            
        }

        void insert(int x)
        {
            if (heapSize == maxSize)
            {
                std::cout << "\nOverflow: Could not insert\n";
                return;
            }

            heapSize++;
            int i = heapSize-1;
            arr[i] = x;

            while (i != 0 && arr[parentIndex(i)] < arr[i])
            {
                swap(i, parentIndex(i));
                i = parentIndex(i);
            }
        }

        int pop()
        {
            if (heapSize == 0) return INT_MIN;

            heapSize--;

            if (heapSize == 1) return arr[0];

            int root = arr[0];
            arr[0] = arr[heapSize];

            heapfy(0);
            return root;
        }

        void removeIndex(int index)
        {
            if (index >= heapSize || index < 0)
                std::cout << "\nIndex Out Of Inbound\n";

            increaseKey(index, INT_MAX);
            pop();
        }

        void print()
        {
            if (heapSize == 0)
            {
                std::cout << "\nEmpty Heap\n";
                return;
            }

            for(int i = 0; i < heapSize; i++)
            {
                std::cout << "|" << arr[i];
            }
            std::cout << "|\n";
        }
};

int main () {
    MaxHeap h(15);
    h.insert(3);
    h.insert(10);
    h.insert(12);
    h.insert(8);
    h.insert(2);
    h.insert(14);

    std::cout << "The current size of heap is " << h.size() << "\n";
    std::cout << "The current maximum element is " << h.getMax() << "\n";
    
    h.print();
    h.pop();
    h.print();

    h.insert(15);
    h.insert(5);
    std::cout << "The current size of heap is " << h.size() << "\n";
    std::cout << "The current maximum element is " << h.getMax() << "\n";
    h.print();
    h.removeIndex(4);
    h.print();
}