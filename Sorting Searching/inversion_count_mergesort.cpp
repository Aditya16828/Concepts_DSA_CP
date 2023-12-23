/*
Inversion Count: number of pairs that satifies the condition: for i < j, a[i] > a[j]
i.e., number of integers > a[i] in the left half of a[i].
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

int inv_count = 0;
void merge(std::vector<int> &arr, int start, int mid, int end) {
    int i = start, j = mid + 1;
    std::vector<int> res;
    while ((i <= mid) and (j <= end)) {
        if (arr[i] <= arr[j]) {
            res.push_back(arr[i]);
            i++;
        } else {
            inv_count += (mid + 1 - i);
            res.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        res.push_back(arr[i]);
        i++;
    }
    while (j <= end) {
        res.push_back(arr[j]);
        j++;
    }
    for (int x = start; x <= end; x++)
        arr[x] = res[x - start];
}

void merge_sort(std::vector<int> &arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void display(std::vector<int> &arr) {
    std::cout << "[";
    int i;
    for (i = 0; i < arr.size() - 1; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[i] << "]\n";
}

int main() {
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
    for (int i = 0; i < n; i++) std::cin >> a[i];
    merge_sort(a, 0, n - 1);
    std::cout << inv_count << "\n";
    display(a);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}