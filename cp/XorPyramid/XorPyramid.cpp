#include <iostream>

bool isOddBinomial(int n, int k) {
    return ((n - 1) & k) == k;
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (isOddBinomial(n, i)) {
            result ^= arr[i];
        }
    }

    std::cout << result << std::endl;
    return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    while (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            arr[i] *= arr[i + 1];  // Multiply adjacent elements
        }
        n--;  // Reduce the pyramid size
    }

    cout << arr[0] << endl;  // The topmost element
    return 0;
}


#include <iostream>
using namespace std;

// Function to compute binomial coefficient C(n-1, k) iteratively
long long binomialCoefficient(int n, int k) {
    long long res = 1;
    for (int i = 0; i < k; i++) {
        res = res * (n - 1 - i) / (i + 1);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    long long arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += binomialCoefficient(n, i) * arr[i];
    }

    cout << result << endl;
    return 0;
}

*/
