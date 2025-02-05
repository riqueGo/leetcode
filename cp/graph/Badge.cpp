#include<iostream>
#include<vector>

using std::vector;

int main() {
    int n;
    std::cin >> n;
    n++;

    vector<int> p(n, 0);
    for(int i = 1; i < n; i++) {
        std::cin >> p[i];
    }

    vector<bool> v(n, false);

    int j;
    for (int i = 1; i < n; i++) {
        j = i;
        while (!v[j]) {
            v[j] = 1;
            j = p[j];
        }
        std::cout << j << " ";
        fill(v.begin(), v.end(), 0);
    }
}