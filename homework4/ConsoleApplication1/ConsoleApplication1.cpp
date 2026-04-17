#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex mtx;
int active_threads = 1;

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

void quikSort(vector<int>& arr, int down, int up, int num_threads) {
    if (down < up) {
        int reference_index = share(arr, down, up);


        mtx.lock();
        if (active_threads < num_threads) {
            
            active_threads++;
            mtx.unlock();

            thread t(quikSort, ref(arr), down, reference_index - 1, num_threads);

            quikSort(arr, reference_index + 1, up, num_threads);

            t.join(); 

            mtx.lock();
            active_threads--; 
            mtx.unlock();
        }
        else {
            mtx.unlock();

            quikSort(arr, down, reference_index - 1, num_threads);
            quikSort(arr, reference_index + 1, up, num_threads);
        }
    }
}


int main() {
    setlocale(LC_ALL, "rus");
    const int n = 2000000;
    vector<int> arr = createRandomArray(n);

    int threads_to_test = 8; 

    cout << "Сортировка массива на " << n << " элементов" << endl;

    auto start = chrono::high_resolution_clock::now();

    quikSort(arr, 0, n - 1, threads_to_test);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> time = end - start;

    cout << "Потоков: " << threads_to_test << " | Время: " << time.count() << " сек" << endl;

    return 0;

}