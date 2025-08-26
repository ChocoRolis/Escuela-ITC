#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int optimize(vector<int>& nums, int indice) {
    int suma = 0;
    while (nums[indice] == nums[indice + 1]) {
        suma++;
        indice++;
    }
    return suma;
}

int main() {
    int h1, h2;

    do {
        cin >> h1 >> h2;
        if (h1 == 0 && h2 == 0) break;

        vector<int> nums(h1 + h2);
        vector<int> conflicts;

        for (int i = 0; i < h1; i++) cin >> nums[i];

        for (int i = 0; i < h2; i++) cin >> nums[h1 + i];

        // Sort each individual vector inside nums
        for (int i = 0; i < nums.size(); i++) {
            sort(nums.begin(), nums.end());
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    conflicts.push_back(nums[i]);
                    int desplazar = optimize(nums, i);
                    nums.erase(nums.begin() + i, nums.begin() + i + desplazar);
                }
            }
        }

        for (int i = 0; i < conflicts.size(); i++) {
            cout << conflicts[i] << " ";
        }
        cout << "\n" << nums.size() << "\n";
    } while (h1 != 0 && h2 != 0);
    return 0;
}
