<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

int find_min_idx(std::vector<int> &arr, int start, int end){
    int min_idx = start;
    int min_ele = arr[min_idx];
    for (int i = start + 1;i <= end;i++){
        if (min_ele > arr[i]){
            min_ele = arr[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void selection_sort(std::vector<int> &arr){
    int n = arr.size();
    for (int i = 0;i < n - 1;i++){
        int min_idx = find_min_idx(arr, i + 1, n - 1);
        if (arr[min_idx] < arr[i]){
            std::swap(arr[min_idx], arr[i]);
        }
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

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0;i < n;i++) std::cin >> a[i];
    selection_sort(a);
    display(a);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
=======
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

int find_min_idx(std::vector<int> &arr, int start, int end){
    int min_idx = start;
    int min_ele = arr[min_idx];
    for (int i = start + 1;i <= end;i++){
        if (min_ele > arr[i]){
            min_ele = arr[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void selection_sort(std::vector<int> &arr){
    int n = arr.size();
    for (int i = 0;i < n - 1;i++){
        int min_idx = find_min_idx(arr, i + 1, n - 1);
        if (arr[min_idx] < arr[i]){
            std::swap(arr[min_idx], arr[i]);
        }
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

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0;i < n;i++) std::cin >> a[i];
    selection_sort(a);
    display(a);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}