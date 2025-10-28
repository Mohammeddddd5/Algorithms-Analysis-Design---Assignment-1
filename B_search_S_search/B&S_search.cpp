#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class sequential {
private:
    vector<T> data;
    T goal;
public:

    sequential(vector<T> input, T v) {
        data = input;
        goal = v;
    }

    int it_sequential() {
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == goal) {
                return i;
            }
        }
        return -1;
    }

    int re_sequential(int i = 0) {
        if (i >= data.size()) {
            return -1;
        }
        if (data[i] == goal) {
            return i;
        }
        return re_sequential(i + 1);
    }

};


template<typename T>
class binary {
    private:
    vector<T> data;
    T goal;

    public:
    binary(vector<T> input, T v) {
        data = input;
        goal = v;
    }

    int it_binary() {
        int L = 0;
        int R = data.size() - 1;
        while (L <= R) {
            int mid = L + (R - L) / 2;
            if (data[mid] == goal) {
                return mid;
            } else if (data[mid] < goal) {
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        return -1;
    }

    int re_binary(int L, int R) {
        if (L > R) {
            return -1;
        }
        int mid = L + (R - L) / 2;
        if (data[mid] == goal) {
            return mid;
        } else if (data[mid] < goal) {
            return re_binary(mid + 1, R);
        } else {
            return re_binary(L, mid - 1);
        }
    }

    
};


int main() {
    vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 7;

    sequential<int> search(vec, target);
    binary<int> srh(vec,15);

    cout << "Iterative Sequential Search: " << search.it_sequential() << endl;
    cout << "Recursive Sequential Search: " << search.re_sequential() << endl;
    cout << "Iterative Binary Search: " << srh.it_binary() << endl;
    cout << "Recursive Binary Search: " << srh.re_binary(0, vec.size() - 1) << endl;

    return 0;
}   