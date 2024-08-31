#include <stdio.h>
int insertion(int *arr,int n, int size){
    int b, i;
    if(size==n){
        printf("The array is full!");
    }
    else{
        int a;
        printf("Enter the element to be inserted: ");
        scanf("%d", &a);
        printf("Enter the index in which the element is to be inserted: ");
        scanf("%d", &b);
        for(i=n;i>=b;i--){
            arr[i+1]=arr[i];
        }
        arr[b]=a;
        return n+1;
    }    
}
int delete(int *arr, int n){
    int a, flag=0, i;
    printf("Enter the element to be deleted: ");
    scanf("%d", &a);
    for(i=0;i<n;i++){
      if(arr[i]==a){
        flag=1;
        break;
      }
    }
    if(flag==0){
        printf("Item not found! ");
    }
    else{
        printf("Current index is %d", i);
        for(int j=i;j<n;j++){
            arr[j]=arr[j+1];
        }
    }
    return n-1;
}
void sort(int *arr, int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
        }
    }
}
void search(int *arr, int n){
    sort(arr, n);
    int a;
    printf("Enter the element to be searched: ");
    scanf("%d", &a);
    int high=n-1;
    int low=0;
    int mid=0;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==a){
            printf("Element is found at index %d after sorting", mid);
            break;
        }
        else if(arr[mid]>a){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
}
void display(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d\t", arr[i]);
    }
}
void main()
{
    int size =10, arr[size], i,n,option;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    while (option!=6){
    printf("\nChoose an option: ");
    printf("\n1. Insert element\n2. Delete element\n3. Display array\n4.Sort Array\n5.Search for element\n6.Exit!");
    scanf("%d", &option);
    switch(option){
        case 1:
        n = insertion(arr,n, size);
        break;

        case 2:
        n = delete(arr, n);
        break;

        case 3:
        display(arr, n);
        break;

        case 4:
        sort(arr, n);
        break;

        case 5:
        search(arr, n);
        break;

        case 6:
        printf("Thank youu!!");
        break;
        
        default:
        printf("Enter a valid option!");
        break;
    }
    }
}
