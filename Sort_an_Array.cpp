/********************************************************************* C++ ****************************************************************************/
//Approach-1 (Counting Sort)
//T.C : O(n+k)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minE = *min_element(begin(nums), end(nums));
        int maxE = *max_element(begin(nums), end(nums));
        
        unordered_map<int, int> mp;
        
        for(int &num : nums)
            mp[num]++;
        
        int i = 0;
        
        for(int num = minE; num <= maxE; num++) {
            while(mp[num] > 0) {
                nums[i] = num;
                i++;
                mp[num]--;
            }   
        }
        return nums;
    }
};

//Approach-2 (Merge Sort)
//T.C : O(nlogn)
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }

 private:
  void mergeSort(vector<int>& A, int l, int r) {
    if (l >= r)
      return;

    const int m = (l + r) / 2;
    mergeSort(A, l, m);
    mergeSort(A, m + 1, r);
    merge(A, l, m, r);
  }

  void merge(vector<int>& A, int l, int m, int r) {
    vector<int> sorted(r - l + 1);
    int k = 0;      // sorted's index
    int i = l;      // left's index
    int j = m + 1;  // right's index

    while (i <= m && j <= r)
      if (A[i] < A[j])
        sorted[k++] = A[i++];
      else
        sorted[k++] = A[j++];

    // Put the possible remaining left part into the sorted array.
    while (i <= m)
      sorted[k++] = A[i++];

    // Put the possible remaining right part into the sorted array.
    while (j <= r)
      sorted[k++] = A[j++];

    copy(sorted.begin(), sorted.end(), A.begin() + l);
  }
};


//Approach-3 (Heap Sort)
//T.C : O(nlogn)

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    heapSort(nums);
    return nums;
  }

 private:
  void heapSort(vector<int>& A) {
    buildMaxHeap(A);
    int heapSize = A.size();
    for (int i = A.size() - 1; i > 0; --i) {
      swap(A[i], A[0]);
      --heapSize;
      maxHeapify(A, 0, heapSize);
    }
  }

  void buildMaxHeap(vector<int>& A) {
    for (int i = A.size() / 2; i >= 0; --i)
      maxHeapify(A, i, A.size());
  }

  void maxHeapify(vector<int>& A, int i, int heapSize) {
    const int l = 2 * i + 1;
    const int r = 2 * i + 2;
    int largest = i;
    if (l < heapSize && A[largest] < A[l])
      largest = l;
    if (r < heapSize && A[largest] < A[r])
      largest = r;
    if (largest != i) {
      swap(A[largest], A[i]);
      maxHeapify(A, largest, heapSize);
    }
  }
};

//Approach-4 (Quick Sort)
//T.C : O(nlogn)
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }

 private:
  void quickSort(vector<int>& A, int l, int r) {
    if (l >= r)
      return;

    const int m = partition(A, l, r);
    quickSort(A, l, m - 1);
    quickSort(A, m + 1, r);
  }

  int partition(vector<int>& A, int l, int r) {
    const int randIndex = rand() % (r - l + 1) + l;
    swap(A[randIndex], A[r]);
    const int pivot = A[r];
    int nextSwapped = l;
    for (int i = l; i < r; ++i)
      if (A[i] <= pivot)
        swap(A[nextSwapped++], A[i]);
    swap(A[nextSwapped], A[r]);
    return nextSwapped;
  }
};