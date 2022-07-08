#include<iostream>
using namespace std;
int sum=0;
void selectionSort(int a[], int n) {
   int i, j, min, temp;
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
      if (a[j] < a[min]){
        min = j;
        sum++;
      }

      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
   }
}
int main() {
   int a[] = { 10,9,8,7,6,5,4,3,2,1 };
   int n = sizeof(a)/ sizeof(a[0]);
   int i;
   cout<<"Given array is:"<<endl;
   for (i = 0; i < n; i++)
   cout<< a[i] <<" ";
   cout<<endl;
   selectionSort(a, n);
   cout<<sum<<endl;
   printf("\nSorted array is: \n");

   for (i = 0; i < n; i++)
   cout<< a[i] <<" ";

   return 0;
}

