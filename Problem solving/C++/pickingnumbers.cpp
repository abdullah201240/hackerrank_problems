#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a)
{


    int i, key, j,sum=0,nsum=-1;
    int z=a.size();
    /*for (i = 1; i < z; i++)
    {
        key = a[i];
        j = i - 1;


        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;

        }
        a[j + 1] = key;
    }*/
    for(int k=1; k<=z; k++)
    {
        for(int j=k+1;j<=z;j++){
            int b=a[k]-a[j];
            if(b==1 ||b==0){

            }
        }


        //cout<<b<<endl;
        if(b==1 ||b==0)
        {
            if(sum==5){
                return sum;
            }
            sum++;

        }
        else
        {
            if(nsum<sum)
            {
                nsum=sum;
            }

            sum=0;
        }


    }

return nsum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);
 cout<<result<<endl;
    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

