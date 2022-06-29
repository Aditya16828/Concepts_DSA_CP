#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

void insertion_sort(std::vector<int> &arr){
    int n = arr.size();
    for (int i = 1; i < n; i++){
        bool placed = false;
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 and (not placed)){
            if (temp < arr[j]){
                arr[j + 1] = arr[j];
            } else{
                arr[j + 1] = temp;
                placed = true;
            }
            j--;
        }
        if (not placed) arr[0] = temp;
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
    insertion_sort(a);
    display(a);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}