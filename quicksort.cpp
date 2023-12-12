#include <bits/stdc++.h>  
using namespace std;  
  
void quicksort(vector<float> &v) {  
    int length = v.size();  
    if (length <= 1) {  
        return;  
    }  
    //长度小于等于1，递归结束
    int middle = length / 2;  
  
    vector<float> v_left(v.begin(), v.begin() + middle);  
    vector<float> v_right(v.begin() + middle, v.end());  
    //创建两个vector，把原来的分为两边
    quicksort(v_left);  
    quicksort(v_right);  
    //分别把两边排序
    int j = 0;  
    int k = 0;  
    int i = 0;  
    while (j < v_left.size() && k < v_right.size()) {  
        if (v_left[j] <= v_right[k]) {  
            v[i] = v_left[j];  
            j++;  
        } else {  
            v[i] = v_right[k];  
            k++;  
        }  
        i++;  
    }  
    //把排序好的两边进行合并
    while (j < v_left.size()) {  
        v[i] = v_left[j];  
        j++;  
        i++;  
    }  
  
    while (k < v_right.size()) {  
        v[i] = v_right[k];  
        k++;  
        i++;  
    }  
}  
  
int main() {  
    int n;  
    cin >> n;  
  
    vector<float> v;  
  
    for (int i = 0; i < n; i++) {  
        float u;  
        cin >> u;  
        v.push_back(u);  
    }  
  
    quicksort(v);  
  
    for (int i = 0; i < n; i++) {  
        cout << v[i] << " ";  
    }  
  
    return 0;  
}  