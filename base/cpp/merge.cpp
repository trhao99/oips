#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> sequence1 = {1, 3, 7, 9, 22};
    vector<int> sequence2 = {2, 8, 10, 17, 33, 44};

    vector<int> result(sequence1.size() + sequence2.size());

    merge(sequence1.begin(), sequence1.end(), sequence2.begin(), sequence2.end(), result.begin());

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
