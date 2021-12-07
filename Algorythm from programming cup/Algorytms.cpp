#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
std::string toString(T val)
{
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

string FindSolution(int n, int m, int k)
{
    string str[50];
    for (size_t i = 0; i < 50; ++i)
    {
        str[i] = "";
        for (size_t c = 0; c < n; ++c)
        {
            int temp = rand() % 2;
            str[i] += toString(temp);
        }
    }
    sort(begin(str), end(str));
    int size = 2;
    for (size_t i = 0; i < n; ++i)
    {
        size *= 2;
    }
    string* ar = new string[size];
    int count = 0;
    bool contains = false;
    for (size_t i = 0; i < 49; ++i)
    {
        if (str[i] != str[i + 1])
        {
            ar[count++] = str[i];

        }
    }
    string underStr;
    string result;
    string secondStr;
    string* unders = new string[n - m + 1];
    string* sUnders = new string[n - m];
    int* countOfOne = new int[n - m + 1];
    int* ones = new int[n - m];
    bool firstUsl;
    bool secondUsl;
    for (size_t i = 0; i < size; ++i)
    {
        result = ar[i];
        for (size_t q = 0; q < n; ++q)
        {
            firstUsl = true;
            secondUsl = true;
            for (size_t v = 0; v < n - m + 1; ++v)
            {
                unders[v] = "";
                for (size_t a = v; a < v + m; ++a)
                {
                    if (n - v >= m)
                        unders[v] += ar[i][a];
                }
            }
            for (size_t i = 0; i < n - m + 1; ++i)
            {
                countOfOne[i] = 0;
                string s = unders[i];
                for (size_t p = 0; p < m; ++p)
                {
                    countOfOne[i] += s[p] == '1' ? 1 : 0;
                }
            }

            for (size_t i = 0; i < n - m + 1; ++i)
            {
                if (countOfOne[i] > k)
                {
                    firstUsl = false;
                    i = n - m + 1;
                }
            }
            if (firstUsl)
            {
                for (size_t b = 0; b < n - m; ++b)
                {
                    sUnders[b] = "";
                    for (size_t a = b; a < b + m + 1; ++a)
                    {                
                        if (n - b >= m + 1)
                            sUnders[b] += ar[i][a];
                    }

                }
                for (size_t zz = 0; zz < n - m; ++zz)
                {
                    ones[zz] = 0;
                    for (size_t x = 0; x < sUnders[zz].length(); ++x)
                    {
                        ones[zz] += sUnders[zz][x] == '1' ? 1 : 0;

                    }
                }
                for (size_t mm = 0; mm < n - m; ++mm)
                {
                    if (ones[mm] < k)
                    {
                        secondUsl = false;
                        mm = n - m;
                    }

                }
                if (secondUsl)
                    return result;
            }
        }
        underStr = "";
        result = "";
        secondStr = "";
    }
    return "-1";
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    cout << FindSolution(n, m, k);
}