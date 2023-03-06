#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <mutex>
#include <assert.h>

constexpr int N_THREADS = 4;
constexpr int A_SIZE = ((100 / N_THREADS) * N_THREADS);

int reduce(int* a, int size) {

    int ret = 0;

    for (int i = 0; i < size; ++i)
        ret += a[i];

    return ret;
}

int reduceWithThreads(int* a, int size) {

    std::mutex mu; // you may need this for synchronisation
    std::thread threads[N_THREADS];
    int ret = 0;
   
    // TODO implement with threads


    return ret;
}

int reduceWithOMP(int* a, int size) {

    int ret = 0;

   // TODO implement OMP with either atomic or critical

    return ret;
}

int reduceWithOMPReduce(int* a, int size) {

    int ret = 0;

    // TODO implement OMP with reduction

    return ret;
}

int main()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 100);
    generator.seed((unsigned)std::chrono::system_clock::now().time_since_epoch().count());

    int a[A_SIZE];

    // fill array
    for (int i = 0; i < sizeof(a) / sizeof(int); ++i) {   // extra question: why does sizeof know the array size here ?
        a[i] = distribution(generator);
    }

    int redcSerial = reduce(a, A_SIZE);

    int redcThreads = reduceWithThreads(a, A_SIZE);
    assert((redcSerial == redcThreads) && "threading implementation failed");

    int redcOMP = reduceWithOMP(a, A_SIZE);
    assert((redcSerial == redcOMP) && "OMP implementation failed");

    // TODO comment in and implement
    // int redcOMPRed = reduceWithOMPReduce(a, A_SIZE);
    // assert((redcSerial == redcOMPRed) && "OMP reduce implementation failed");
     
    std::cout << "works :)!" << std::endl;
}

