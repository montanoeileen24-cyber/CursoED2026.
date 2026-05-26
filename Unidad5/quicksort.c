#include <stdio.h> 

// Función para intercambiar dos elementos 
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int partition(int arr[], int low, int high) 
{ 
    // CAMBIO 
    int pivot = arr[low]; 
    
   
    int i = low; 

    // CAMBIO 
    for (int j = low; j < high; j++) 
    { 
        
        if (arr[j] < pivot) 
        { 
            i++;  
            swap(&arr[i], &arr[j]); 
        } 
    } 
    
    // CAMBIO 
    swap(&arr[i], &arr[low]); 
    
    return i;
} 


void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) { 
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high); 
    } 
}

int main() { 
    int data[] = {6, 2, 4, 1, 5, 8, 12, 3, 9, 7}; 
    int n = sizeof(data) / sizeof(data[0]); 
    
    quickSort(data, 0, n - 1); 
    
   
    for (int i = 0; i < n; i++) { 
        printf("%d ", data[i]); 
    } 
    return 0; 
}