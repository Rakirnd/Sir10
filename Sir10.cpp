#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

int nr_siruri = 0;

int count_subarr(int n)
{

    return (pow(n, 2) - (3 * n) + 2) / 2;

}

void find_siruri(int n, int step)
{

    if ((n / step) < 3)
        return;

    int new_step = step + 1;

    if (n % step == 0)
    {

        nr_siruri += step * count_subarr(n/step);
        find_siruri(n, new_step);

    }
    else
    {

        int remainder = n % step;

        nr_siruri += remainder * count_subarr((n + 1)/step) + (step - remainder) * count_subarr(n/step);
        find_siruri(n, new_step);

    }

}


int main()
{
    
    ifstream f("sir10.in");
    ofstream g("sir10.out");

    int n;
    int starting_point = 1;
    int step = 1;

    f >> n;

    find_siruri(n, 1);

    if (n < 3 || n > 20000)
        g << "Numarul n nu se incadreaza in intervalul specificat";
    else
        g << nr_siruri;

    f.close();
    g.close();

    return 0;

}

