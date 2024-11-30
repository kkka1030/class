#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
#include <algorithm> 

template <typename Comparable>
class HeapSort 
{
public:
    static void sort(std::vector<Comparable>& a) 
    {
        buildHeap(a); 
        for (int i = a.size() - 1; i > 0; --i) 
        {
            std::swap(a[0], a[i]);  
            percDown(a, 0, i);
        }
    }

private:
    //构建堆
    static void buildHeap(std::vector<Comparable>& a) 
    {
        for (int i = a.size() / 2 - 1; i >= 0; --i) 
        {
            percDown(a, i, a.size());
        }
    }
    
    //向下渗透
    static void percDown(std::vector<Comparable>& a, int i, int n) 
    {
        int child;
        Comparable tmp = std::move(a[i]); 

        while (leftChild(i) < n) 
        { 
            child = leftChild(i);
            if (child != n - 1 && a[child] < a[child + 1]) 
            {
                ++child;
            }
            if (tmp < a[child]) 
            {
                a[i] = std::move(a[child]);
                i = child;
            } 
            else 
            {
                break;
            }
        }
        a[i] = std::move(tmp); 
    }

    //计算左孩子的位置
    static int leftChild(int i) 
    {
        return 2 * i + 1;
    }
};

#endif // HEAPSORT_H
