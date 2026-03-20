#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

vector<int> createRandomArray(int n) {
    
    static random_device rd;
    static mt19937 gen(rd());

    static uniform_int_distribution<> dis(0, 999);

    vector<int> randomArray;
    
    for (int i = 0; i < n; ++i) {
        randomArray.push_back(dis(gen));
    }
    return randomArray;
}

void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}



void sortShell(vector<int>& arr) {
    int n = arr.size();
    int step = n / 2;
    while (step > 0) {
        for (int i = step; i < n; i++) {
            int vr_arr = arr[i];
            int j = i;
            while (j >= step && arr[j - step] > vr_arr) {
                arr[j] = arr[j - step];
                j = j - step;

            }
            arr[j] = vr_arr;
        }
    
        step = step / 2;
    }
}

vector <int> joinBuckets(vector<vector<int>> buckets) {
    vector<int> joinArr;
    for (vector<int> bucket : buckets) {
        for (int num : bucket) {
            joinArr.push_back(num);
        }
    }
    return joinArr;
}

void sortforcategory(vector<int>& arr, int category) {
    vector<vector<int>> buckets(10);
    for (int num : arr) {
        int indexBuckets = (num / category) % 10;
        buckets[indexBuckets].push_back(num);
    }
    arr = joinBuckets(buckets);
}

void radixSort(vector<int>& arr) {
    int max_num = *std::max_element(begin(arr), end(arr));;

    int category = 1;
    while (max_num / category > 0) {
        sortforcategory(arr, category);
        category = category * 10;
    }
}

void swap(int& a, int& b) {
    int num = a;
    a = b;
    b = num;
}

int share(vector<int>& arr, int down, int up) {
    int reference = arr[up];
    int i = down - 1;
    for (int j = down; j <= up - 1; j++) {
        if (arr[j] <= reference) {
            i++;
            swap(arr[i], arr[j]);
        }
        
    }
    swap(arr[i + 1], arr[up]);
    return (i + 1);
}

void quikSort(vector<int>& arr, int down, int up) {
    if (down < up) {
        int reference_index = share(arr, down, up);
        quikSort(arr, down, reference_index - 1);
        quikSort(arr, reference_index + 1, up);

    }
}



int main() {
    setlocale(LC_ALL, "rus");
    const int n = 100;

    vector<int> result = createRandomArray(n);
    vector<int> result4 = result;
    vector<int> result2 = result;
    vector<int> result3 = result;

    quikSort(result4, 0, n - 1);
    sortShell(result2);
    radixSort(result3);

    cout << "Случайный массив из " << n << " чисел: ";
    printArray(result);
    cout << std::endl;

    cout << "Отсортированный массив СОРТИРОВКОЙ ШЕЛЛА из " << n << " чисел: ";
    printArray(result2);
    cout << std::endl;

    cout << "Отсортированный массив ПОРАЗРЯДНАЯ СОРТИРОВКА из " << n << " чисел: ";
    printArray(result3);
    cout << std::endl;
    
    cout << "Отсортированный массив БЫСТРАЯ СОРТИРОВКА из " << n << " чисел: ";
    printArray(result4);
    cout << std::endl;


    return 0;
}
