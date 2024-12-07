#include<iostream>
#include<vector>

using std::vector;

bool isValidPartition(const vector<long long>& numbers, const int k, const long long& mid) {
   int groups = 0;
   long long tmpSum = 0;

    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] > mid) {
            return false;
        }

        if(tmpSum + numbers[i] > mid) {
            groups++;
            tmpSum = 0;
        }

        tmpSum += numbers[i];
    }

    if(tmpSum > 0) {
        groups++;
    }

    return groups <= k;
}

int main () {
    int n, k;
    std::cin >> n >> k;

    long long mid, max, minMaxSum, min = 0;

    vector<long long> numbers(n);
    for(int i = 0; i < n; i++) {
        std::cin >> numbers[i];
        max += numbers[i];
        if(numbers[i] > min) {
            min = numbers[i];
        }
    }

    while (min < max) {
        mid = min + ((max - min)/2);

        if(isValidPartition(numbers, k, mid)) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }

    std::cout << min << std::endl;
}