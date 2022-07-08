#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'quartiles' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> quartiles(vector<int> arr) {

typedef std::vector<int>::size_type vec_sz;
sort(arr.begin(), arr.end());


  vec_sz mid = arr.size() / 2;
  float median;
  median = arr.size() % 2 == 0 ? (arr[mid] + arr[mid - 1]) / 2 : arr[mid];

  std::vector<float> vecOfQ1;
  std::vector<float> vecOfQ3;

  // Check whether vector.size % 2 == 0
  if (arr.size() % 2 == 0) {
    for (std::vector<int>::size_type i = 0; i <= mid - 1; i++) {
      vecOfQ1.push_back(arr[i]);
    }
    for (std::vector<int>::size_type i = mid; i != arr.size(); i++) {
      vecOfQ3.push_back(arr[i]);
    }
  } else {
    for (std::vector<int>::size_type i = 0; i != mid; i++) {
      vecOfQ1.push_back(arr[i]);
    }

    for (std::vector<int>::size_type i = mid + 1; i != arr.size(); i++) {
      vecOfQ3.push_back(arr[i]);
    }
  }

  // sizeQ1 and sizeQ2 store size of vecOfQ1 and vecOfQ2 respectively
  vec_sz sizeQ1 = vecOfQ1.size();
  vec_sz sizeQ3 = vecOfQ3.size();

  // Q1
  vec_sz midQ1 = sizeQ1 / 2;
  int q1;
  q1 = sizeQ1 % 2 == 0 ? ((vecOfQ1[midQ1] + vecOfQ1[midQ1 - 1]) / 2) : vecOfQ1[midQ1];

  // Q3
  vec_sz midQ3 = sizeQ3 / 2;
  int q3;
  q3 = sizeQ3 % 2 == 0 ? ((vecOfQ3[midQ3] + vecOfQ3[midQ3 - 1]) / 2) : vecOfQ3[midQ3];

  std::cout << "\nMedian = " << median << ", Q1 = " << q1 << ", Q3 = " << q3;
  std::cout << "\n";


vector<int> vec {q1,(int)median,q3};
return vec;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string data_temp_temp;
    getline(cin, data_temp_temp);

    vector<string> data_temp = split(rtrim(data_temp_temp));

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        int data_item = stoi(data_temp[i]);

        data[i] = data_item;
    }

    vector<int> res = quartiles(data);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
