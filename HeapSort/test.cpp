#include <iostream>
#include <vector>
#include <algorithm> 
#include <chrono>    
#include "HeapSort.h" 


template <typename Comparable>
bool check(const std::vector<Comparable>& data) 
{
    for (size_t i = 1; i < data.size(); ++i) 
    {
        if (data[i - 1] > data[i]) 
        {
            return false; 
        }
    }
    return true;
}

// 随机序列
std::vector<int> RandomSequence(size_t size) 
{
    std::vector<int> sequence(size);
    for (size_t i = 0; i < size; ++i) 
    {
        sequence[i] = rand();
    }
    return sequence;
}

// 有序序列
std::vector<int> OrderedSequence(size_t size) 
{
    std::vector<int> sequence(size);
    for (size_t i = 0; i < size; ++i) 
    {
        sequence[i] = i;
    }
    return sequence;
}

// 逆序序列
std::vector<int> ReverseOrderedSequence(size_t size) 
{
    std::vector<int> sequence(size);
    for (size_t i = 0; i < size; ++i) 
    {
        sequence[i] = size - i;
    }
    return sequence;
}

// 部分元素重复序列
std::vector<int> RepetitiveSequence(size_t size) 
{
    std::vector<int> sequence(size);
    for (size_t i = 0; i < size; ++i) 
    {
        sequence[i] = i % 666; 
    }
    return sequence;
}

//测试函数
template <typename Comparable>
void testS(const std::string& testName, std::vector<Comparable> sequence) 
{
    std::cout << "测试: " << testName << std::endl ;

    auto sequence_ = sequence;

    auto start = std::chrono::high_resolution_clock::now();
    HeapSort<Comparable>::sort(sequence);
    auto end = std::chrono::high_resolution_clock::now();
    auto durationHeapSort = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    if (check(sequence)) 
    {
        std::cout << "my heapsort生成正确. 时间为: " << durationHeapSort << " ms\n";
    } else 
    {
        std::cout << "Incorrect.\n";
    }

    
    start = std::chrono::high_resolution_clock::now();
    std::make_heap(sequence_.begin(), sequence_.end());
    std::sort_heap(sequence_.begin(), sequence_.end());
    end = std::chrono::high_resolution_clock::now();
    auto durationSTLHeap = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    if (check(sequence_)) 
    {
        std::cout << "std::sort_heap 生成正确. 时间为: " << durationSTLHeap << " ms\n";
    } else {
        std::cout << "Incorrect.\n";
    }
    std::cout << "---------------------------------------------------------\n";
}

int main() {
    const size_t dataSize = 1000000; 
    testS("random sequence", RandomSequence(dataSize));
    testS("ordered sequence", OrderedSequence(dataSize));
    testS("reverse sequence", ReverseOrderedSequence(dataSize));
    testS("repetitive sequence", RepetitiveSequence(dataSize));

    return 0;
}
