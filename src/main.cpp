#include <iostream>
#include <thread>
#include <vector>
#include <numeric>
#include <mutex>

std::mutex mtx;
long long global_sum = 0;

void worker(const std::vector<int>& data, int start, int end) {
    long long local_sum = 0;
    for (int i = start; i < end; ++i) {
        local_sum += data[i];
    }
    std::lock_guard<std::mutex> lock(mtx);
    global_sum += local_sum;
}

int main() {
    const int N = 1000000;
    std::vector<int> data(N, 1); // 100万個の「1」

    int num_threads = 4;
    std::vector<std::thread> threads;

    int chunk = N / num_threads;
    for (int t = 0; t < num_threads; ++t) {
        int start = t * chunk;
        int end = (t == num_threads - 1) ? N : start + chunk;
        threads.emplace_back(worker, std::cref(data), start, end);
    }

    for (auto& th : threads) th.join();

    std::cout << "Total sum = " << global_sum << std::endl;
    return 0;
}
