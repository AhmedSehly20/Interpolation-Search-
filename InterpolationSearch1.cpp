#include <iostream>
#include <vector>
using namespace std;
int interpolationSearch(const vector<int> &arr,int target)
{
    int low =0;
    int high =arr.size()-1;

    while(low <= high && arr[low] <= target && arr[high] >= target){
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target) {
            return pos;
        }

        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1; // Target not found

    }

int main() {
    vector<int> SortedUniformArray = {1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int targetValue;
    cin>>targetValue;

    int result = interpolationSearch(SortedUniformArray, targetValue);
    
    if (result != -1) {
        cout << "Element " << targetValue << " found at index " << result << endl;
    } else {
        cout << "Element " << targetValue << " not found in the array" << endl;
    }

    return 0;
}
