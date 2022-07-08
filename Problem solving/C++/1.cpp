#include<iostream>
using namespace std;
bool is_prime(int num, int n){
    if(num<2){
        return false;
    }
    if(num ==2 || num ==3){
        return true;
    }
    if(num%n==0){
        return false;
    }
    if(n <= num/2){
        return true;
    }
    bool b=is_prime(num,n-1);
  return b;
}
void  count_prime(int arr[],int n){
    int sum=0;
for(int i=0;i<n;i++){
    if(is_prime(arr[i],2)==true){
        cout<<arr[i]<<" ";
        sum++;
    }

}
cout<<"\n";
cout<<"#primes="<<sum<<endl;
}
int main(){
    int ar[100],n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

count_prime(ar,n);

}
