#include<iostream>
using namespace std;

void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void selection_sort(int arr[] ,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i] , arr[j]);
            }
        }
    }
}

void bubble_sort(int arr[] , int a){
    while(a--){
     for(int i=0;i<a;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i] , arr[i+1]);
        }
     }
    }
}

void insertion_sort(int arr[] ,int n){
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j=i-1;                             
        while(current<arr[j] && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
}
void merge(int arr[] ,int s ,int e ,int mid){
    int n=mid-s+1;
    int m=e-mid;

    int a[n],b[m];
    int mainindex=s;

    for(int i=0;i<n;i++){
        a[i]=arr[mainindex++];
    }
    for(int i=0;i<m;i++){
        b[i]=arr[mainindex++];
    }

    mainindex=s;
    int i=0,j=0;

    while(i<n && j<m){
        if(a[i]<b[j]){
            arr[mainindex++]=a[i++];
        }
        else{
            arr[mainindex++]=b[j++];
        }
    }

    while(i<n){
         arr[mainindex++]=a[i++];
    }
    while(j<m){
        arr[mainindex++]=b[j++];
    }
}

void merge_sort(int arr[] ,int s ,int e){
    if(s>=e){
        return ;
    }

    int mid=(s+e)/2;

    merge_sort(arr ,s,mid);
    merge_sort(arr, mid+1 ,e);

    merge(arr,s,e,mid);
}

int partition(int arr[] , int s, int e){
    int p = arr[s];
    int c=0;
    for(int i=s;i<=e;i++){
        if(arr[i]<arr[s]){
            c++;
        }
    }
    int pivotindex = s+c;
    swap(arr[s],arr[pivotindex]);

    int i=s;
    int j=e;

    while(i<pivotindex && j> pivotindex){
        if(arr[i]>arr[pivotindex] && arr[j]<arr[pivotindex]){
            swap(arr[i++],arr[j--]);
        }
        else if(arr[i]>arr[pivotindex]){
            j--;
        }
        else if(arr[j]<arr[pivotindex]){
            i++;
        }
        else{
            i++; j--;
        }
    }
    return pivotindex;
}
void quick_sort(int arr[], int s ,int e){
    if(s>=e){
        return;
    }
    int p = partition(arr,s,e);

    quick_sort(arr,s,p-1);
    quick_sort(arr,p+1,e);
}

main(){
    system("cls");
    int n=10;
    int arr[n]={14,15,18,1,6,7,10,2,20,16};

    // You can run any above sorting algo(s) just by uncomment it.

    // selection_sort(arr,n);
    // bubble_sort(arr,n);
    // insertion_sort(arr,n);
    // merge_sort(arr,0,n-1);
    // quick_sort(arr,0,n-1);

    print(arr,n);
    
}          

