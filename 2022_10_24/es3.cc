#include <iostream>
using namespace std;

#define MAX 99
#define MIN 0
#define MAX_LENGTH 20

void merge(int vec[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
   
    int left[n1], right[n2];
 
    
    for (int it = 0; it < n1; it++){
        left[it] = vec[l + it];
    }
    for (int it = 0; it < n2; it++){
        right[it] = vec[m + 1 + it];
    }
 
  
    i = 0; 
    j = 0; 
    k = l;
     
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            vec[k] = left[i];
            i++;
        }
        else {
            vec[k] = right[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        vec[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort_rec(int arr[], int l, int r)
{
    if (l < r) {
        int mid = l + (r - l) / 2; // equal to (r + l) / 2
 
        merge_sort_rec(arr, l, mid);
        merge_sort_rec(arr, mid + 1, r);
 
        merge(arr, l, mid, r);
    }
}
 
void merge_sort(int vec[], int length){
    merge_sort_rec(vec, 0, length - 1);
}

void init_vec(int v[], int length){
    for(int i = 0; i < length; i++){
        v[i] = rand() % (MAX - MIN + 1) + MIN;
    }
}

void print_vec(int v[], int length){
    for(int i = 0; i < length; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    srand(time(NULL));
    int v[MAX_LENGTH];
    init_vec(v, MAX_LENGTH);
    print_vec(v, MAX_LENGTH);
    merge_sort(v, MAX_LENGTH);
    print_vec(v, MAX_LENGTH);
}