

#include <iostream>
using namespace std;

void heapify(int arr[],int n,int i){
    int large =i;
    int left =2*i;
    int right = 2*i+1;
    if (left<=n && arr[large]<arr[left]){
        large =left;
    }
    if (right <= n && arr[large]<arr[right]){
        large = right;
    }
    if (large != i){
        swap (arr[large],arr[i]);
        heapify(arr,n,large);
    }
}
void heapsort(int arr[], int n){
    int size = n;
    while(size>1) {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr,size,1);
    }
};

int main(){

    int arr[6] = {54,55,32,40,50,53};
int n =5;

for (int i =  ; i>0; i--){
   heapify(arr,n,i);
}cout<< endl;
for (int i=1;i<=n;i++){
    cout<<arr[i]<<" ";
}cout<< endl;

heapsort(arr,n);
    for (int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<< endl;
    return 0;
}
