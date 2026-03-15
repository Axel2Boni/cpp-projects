#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void print_list(double* t, int n)
{
    if (n <= 5) {
        for (int i=0; i<n; i++)
            {cout << "t[" << i <<"] = " << t[i] << endl;}
    }
    else {
        for (int i=0; i<6; i++)
            {cout << "t[" << i <<"] = " << t[i] << endl;}
        {cout << "..." << endl;}
        {cout << "t[" << n-1 <<"] = " << t[n-1] << endl;}
    }
}

void generate_random_list(double* t, int n)
{
    for (int i=0; i<n; i++)
        {t[i] = (int)(100*rand()/(double)RAND_MAX);}
}

void selection_sort(double*t, int n)
{
    for (int i=0; i<n; i++) {
        int min_ind = i;
        for (int j=i+1; j<n; j++) {
            if (t[j] < t[min_ind]) {min_ind = j;}
        }
        //swap
        {double temp = t[i];
        t[i] = t[min_ind];
        t[min_ind] = temp;}
    }
}

int main()
{
    int n = 12;
    double* t = new double[n];
    srand(time(0));
    generate_random_list(t, n);
    cout << "Before sorting:" << endl;
    print_list(t, n);
    cout << "After sorting:" << endl;
    selection_sort(t, n);
    print_list(t, n);
    delete [] t;
    return 0;
}