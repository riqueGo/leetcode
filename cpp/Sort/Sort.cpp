#include<iostream>
#include<vector>

using std::vector;
using std::swap;

//All algorithms is in ascending order

class Sort {

public:
    void selectionSort(vector<int>& arr) {
        int minIndex;

        for(int i = 0; i < arr.size(); i++) {
            minIndex = i;

            for(int j = i+1; j < arr.size(); j++) {
                if(arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            if(minIndex != i) {
                swap(arr[i], arr[minIndex]);
            }
        }
    }

    void bubbleSort(vector<int>& arr) {

        bool hasSwapped = true;
        int limit = arr.size();
        while (hasSwapped) {
            hasSwapped = false;

            for(int i = 1; i < limit; i++) {
                if(arr[i] < arr[i-1]) {
                    swap(arr[i], arr[i-1]);
                    hasSwapped = true;
                }
            }
            limit--;
        }
    }

    int quickSortPartition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for(int j = low; j <= high-1; j++) {
            if(arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[high]);
        return i+1;
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if(low < high) {
            int pi = quickSortPartition(arr, low, high);
            quickSort(arr, low, pi-1);
            quickSort(arr, pi+1, high);
        }
    }
};

int main() {
    vector<int> arr = {3,1,7,5,8,9,2};
    Sort s;
    s.bubbleSort(arr);

    for(int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " | ";
    }
    std::cout << std::endl;
}