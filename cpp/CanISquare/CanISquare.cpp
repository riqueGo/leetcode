#include<iostream>
#include<cmath>

int main() {
    int t,a;
    long long n, total,root;

    std::cin >> t;

    for(int i = 0; i < t; i++) {
        std::cin >> n;

        total = 0;
        for(int j = 0; j < n; j++) {
            std::cin >> a;
            total += a;
        }

        root = std::sqrt(total);
        if(root*root == total) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
}