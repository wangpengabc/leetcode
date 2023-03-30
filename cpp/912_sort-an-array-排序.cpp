// https://leetcode.cn/problems/sort-an-array/
// 排序算法汇总

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // if (nums.size() >= 20000) {
        //     return nums;
        // }
        // quick_sort(nums, 0, nums.size()-1);
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }

    void merge_sort(vector<int>& nums, int left, int right) {
        if (left == right) {
            return;
        }

        int middle = (left + right) / 2;

        merge_sort(nums, left, middle);
        merge_sort(nums, middle+1, right);

        // 将排序好的左右分支合并
        vector<int> tmp_nums(right-left+1, 0);
        int tmp_idx = 0;
        int left_idx = left, right_idx = middle+1;
        while(left_idx <= middle && right_idx <= right) {
            if (nums[left_idx] <= nums[right_idx]) {
                tmp_nums[tmp_idx] = nums[left_idx];
                left_idx++;
            } else {
                tmp_nums[tmp_idx] = nums[right_idx];
                right_idx++;
            }
            tmp_idx++;
        }
        while (left_idx <= middle) {
            tmp_nums[tmp_idx] = nums[left_idx];
            left_idx++;
            tmp_idx++;
        }
        while (right_idx <= right) {
            tmp_nums[tmp_idx] = nums[right_idx];
            right_idx++;
            tmp_idx++;
        }
        for (int i=0; i<right-left+1; i++) {
            nums[left+i] = tmp_nums[i];
        }


    }


    void quick_sort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return ;
        }

        // 选择pivot，对数组划分
        int pivot_num = nums[left];
        int pivot_idx = left;
        for (int i=pivot_idx+1; i<=right; i++) {
            if (nums[i] < pivot_num) {
                nums[pivot_idx] = nums[i];
                pivot_idx++;
                nums[i] = nums[pivot_idx];
            }
        }
        nums[pivot_idx] = pivot_num;
        quick_sort(nums, left, pivot_idx-1);
        quick_sort(nums, pivot_idx+1, right);

    }
    
    // 希尔排序
    // Shell sort
    // Reference: https://www.runoob.com/data-structures/shell-sort.html
};

// 堆排序
// #include <iostream>
// #include <vector>

// using namespace std;

// class MinHeap {
//     private:
//         vector<int> heap_v;
//     public:
//         MinHeap(vector<int> heap_v) : heap_v(heap_v) {
//             auto_adjust();
//         }

//         void print() {
//             for (auto item : heap_v) {
//                 cout << item << " ";
//             }
//             cout << endl;
//         }

//         int left(int idx) {
//             return idx*2 + 1;
//         }

//         int right(int idx) {
//             return idx*2 + 2;
//         }

//         int parent(int idx) {
//             return (int)((idx-1)/2);
//         }

//         bool less(int min_idx, int cmp_idx) {
//             return heap_v[min_idx] < heap_v[cmp_idx];
//         }

//         // 交换
//         void swap(int source_idx, int target_idx) {
//             int tmp = heap_v[target_idx];
//             heap_v[target_idx] = heap_v[source_idx];
//             heap_v[source_idx] = tmp;
//         }

//         // 下沉
//         void sink(int node_idx) {
//             while (left(node_idx) < heap_v.size()) {
//                 // 假设最小的是左节点
//                 int min = left(node_idx);
//                 if (right(node_idx)< heap_v.size()  && less(right(node_idx), min)) {
//                     min = right(node_idx);
//                 }
//                 if (!less(node_idx, min)) {
//                     swap(node_idx, min);
//                     node_idx = min;
//                 } else {
//                     break;
//                 }
//             }
//         }

//         // 上浮
//         void swim(int node_idx) {
//             while (parent(node_idx)>=0) {
//                 if (less(node_idx, parent(node_idx))) {
//                     swap(node_idx, parent(node_idx));
//                     node_idx = parent(node_idx);
//                 } else {
//                     break;
//                 }
//             }
//         }

//         // 建立最小堆
//         void auto_adjust() {
//             vector<int> tmp_heap_v = heap_v;
//             heap_v.clear();
//             for (auto item : tmp_heap_v) {
//                 heap_v.push_back(item);
//                 swim(heap_v.size()-1);
//             }
//         }

//         // 升序排序输出
//         void increas_seq() {
//             vector<int> tmp_heap = heap_v;
            
//             while (heap_v.size() > 0) {
//                 swap(heap_v.size()-1, 0);
//                 cout << heap_v.back() << " ";
//                 heap_v.pop_back();
//                 sink(0);
//                 // print();
//             }
//             cout << endl;
//             heap_v = tmp_heap;
//         }
// };


// int main() {
//     vector<int> test_v = {1, 3, 4, 10, 0, 2, 5, 7};
//     MinHeap min_heap(test_v);
//     min_heap.print();
//     min_heap.increas_seq();

//     return 0;
// }
