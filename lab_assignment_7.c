#include <stdio.h>

void swap(int *arr,int i,int j){
    int temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
}

void bubbleSort(int arr[], int n, int num_swaps[]) {
    int i, j ;
    
    for (i = 0; i < n; i++)
        num_swaps[i] = 0;
    
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                
                swap(arr,j,j + 1);
            
                num_swaps[i]++;
            }
        }
    }
}

int main() {
    int arr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num_swaps[n];
    
    bubbleSort(arr, n, num_swaps);
    
    printf("The number of swaps are: ");
    for (int i = 0; i < n; i++) 
        printf("%d  " , num_swaps[i]);
    
    return 0;
}
