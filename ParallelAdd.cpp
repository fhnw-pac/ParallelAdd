#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <mutex>
#include <assert.h>

#define N_THREADS 4
#define A_SIZE ((100/N_THREADS)*N_THREADS)

using namespace std;

int reduce(int* a, unsigned size) {

    int ret = 0;

    for (int i = 0; i < size; ++i)
        ret += a[i];

    return ret;
}

int reduceWithThreads(int* a, unsigned size) {

    mutex mu; // you will need this for synchronisation
    thread threads[N_THREADS];
    int ret = 0;
   
    // TODO implement with threads


    return ret;
}

int reduceWithOMP(int* a, unsigned size) {

    int ret = 0;

   // TODO implement OMP with either atomic or critical

    return ret;
}

int reduceWithOMPReduce(int* a, unsigned size) {

    int ret = 0;

    // TODO implement OMP with reduction

    return ret;
}

int main()
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, 100);
    generator.seed(chrono::system_clock::now().time_since_epoch().count());

    int a[A_SIZE];

    // fill array
    for (int i = 0; i < sizeof(a) / sizeof(int); ++i) {   // extra question: why does sizeof know the array size here ?
        a[i] = distribution(generator);
    }

    int redcSerial = reduce(a, A_SIZE);

    int redcThreads = reduceWithThreads(a, A_SIZE);
    assert(redcSerial == redcThreads, "threading implementation failed");

    int redcOMP = reduceWithOMP(a, A_SIZE);
    assert(redcSerial == redcOMP, "OMP implementation failed");

    // TODO comment in and implement
    // int redcOMPRed = reduceWithOMPReduce(a, A_SIZE);
    // assert(redcSerial == redcOMPRed, "OMP reduce implementation failed");
     
    cout << "works :)!" << endl;
}

