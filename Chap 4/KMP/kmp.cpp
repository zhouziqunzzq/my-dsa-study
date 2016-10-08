#include <iostream>
#include <cstring>
using namespace std;
int* buildNext(char* P)
{
    size_t m = strlen(P), j = 0;
    int *N = new int[m];
    int t = N[0] = -1;
    while(j < m - 1)
    {
        if(0 > t || P[j] == P[t])
        {
            ++j;
            ++t;
            N[j] = (P[j] != P[t] ? t : N[t]);
        }
        else
            t = N[t];
    }
    return N;
}

int kmp(char* P, char* T)
{
    int* next = buildNext(P);
    int n = (int)strlen(T), i = 0;
    int m = (int)strlen(P), j = 0;
    while(j < m && i < n)
    {
        if(0 > j || T[i] == P[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    delete[] next;
    return i - j;
}

int main()
{
    while(true)
    {
        char P[256], T[256];
        cout<<"Input original string T:";
        cin>>T;
        cout<<"Input string P:";
        cin>>P;
        int result = kmp(P, T);
        if(result == strlen(T))
            cout<<"No match found!"<<endl;
        else
            cout<<"Match found at position "<<result + 1<<endl;
    }
    return 0;
}
