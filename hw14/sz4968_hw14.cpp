#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> find_min_max(const vector<T>& vec, int low, int high) {
    vector<T> min_max_vec = {vec[low], vec[low]};
    if (low == high){
        return min_max_vec;
    } else if (low == high - 1) {
        min_max_vec[0] = min(vec[low], vec[high]);
        min_max_vec[1] = max(vec[low], vec[high]);
        return min_max_vec;
    } else {
        int mid = (low + high) / 2;
        vector<T> min_max_vec_first_half = find_min_max(vec, low, mid);
        vector<T> min_max_vec_second_half = find_min_max(vec, mid + 1, high);
        min_max_vec[0] = min(min_max_vec_first_half[0], min_max_vec_second_half[0]);
        min_max_vec[1] = max(min_max_vec_first_half[1], min_max_vec_second_half[1]);
        return min_max_vec;
    }
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> min_max_vec = find_min_max(vec, 0, vec.size() - 1);
    cout <<"Min: " << min_max_vec[0] << endl;
    cout <<"Max: " << min_max_vec[1] << endl;

    vector<double> vec2 = {-1.5, -3.14, -1.718, 1.414, 2.718};
    vector<double> min_max_vec2 = find_min_max(vec2, 0, vec2.size() - 1);
    cout <<"Min: " << min_max_vec2[0] << endl;
    cout <<"Max: " << min_max_vec2[1] << endl;

    return 0;
}