#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

int partition(std::vector<int> &arr, int lo, int hi){
    int pivot_idx = lo + (std::rand() % (hi - lo + 1));
    std::swap(arr[hi], arr[pivot_idx]);
    int pivot = arr[hi];
    int m = lo - 1;
    for (int i = lo;i <= hi;i++){
        if (arr[i] < pivot){
            ++m;
            std::swap(arr[i], arr[m]);
        }
    }
    std::swap(arr[hi], arr[m + 1]);
    return m + 1;
}

void quicksort(std::vector<int> &arr, int start, int end){
    if (start < end){
        int pivot_idx = partition(arr, start, end);
        quicksort(arr, start, pivot_idx - 1);
        quicksort(arr, pivot_idx + 1, end);
    }
}

void display(std::vector<int> &arr){
    std::cout << "[";
    int i;
    for (i = 0;i < arr.size() - 1;i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[i] << "]\n";
}

int main(){
    clock_t begin = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    srand(time(0));
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0;i < n;i++) std::cin >> a[i];
    quicksort(a, 0, n - 1);
    display(a);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}