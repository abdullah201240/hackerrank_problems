#include<iostream>
using namespace std;
int sum=0;
int is_palindrome(int b,int c=0)
{
    if(b==0)
    {
        return c;
    }

    c=c*10;
    c=c+(b%10);
    return is_palindrome(b/10,c);




}
void sum_palindrome(int s,int end)
{

    if(s==end+1)
    {
        return;
    }

    if(s<10)
    {
        sum=sum+s;
        cout<<s<<" ";
    }
    else
    {
        if(is_palindrome(s)==s)
        {
            cout<<s<<" ";
            sum=sum+s;
        }

    }




    sum_palindrome(s+1,end);
}
int main()
{
    int start,end;
    cin>>start;
    cin>>end;
    sum_palindrome(start,end);
    cout<<"\n"<<"sum "<<sum<<endl;

}
