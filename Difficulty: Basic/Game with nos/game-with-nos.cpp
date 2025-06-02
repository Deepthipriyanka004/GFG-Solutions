int* game_with_number(int arr[], int n)
{
    
    // Complete the function
    int* arr2 = new int[n];
    for(int i=0;i<n-1;i++){
        arr2[i]=arr[i]^arr[i+1];
    }
    arr2[n-1] = arr[n-1];
    return arr2;
    
}