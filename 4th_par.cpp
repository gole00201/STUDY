//BINSORT
/* #include <iostream>

int main(void)
{
    int Upper = 100; int Lower = 1; int Middle = 0; int Gnum = 0;
    std::cout << "Enter the number: " << '\n'; std::cin >> Gnum;
    while (Upper > Lower)
    {
        Middle = (Upper + Lower) / 2; 
        (Gnum <= Middle) ? Upper = Middle : Lower = Middle + 1;
    }
    std::cout << "Your number is: " << Upper << '\n';
} */

//BINPOW
/* int binpow(int a, int n) {
    int res = 1;
    while (n != 0) {
        if (n & 1)
            res *= a;
        a *= a ;
        n >>= 1;
    }
    return res;
} */

//PRIMENUMBERS
/* #include <iostream>
#include <vector>
int main(void)
{
    int n;
    int p = 0;
    int buff = 0;
    std::vector<int> v;
    n = 100;
    for (int i = 2; i <= n ; ++i)
        v.push_back(i);
    for (int i = 0 ; i <= n ; ++i)
        for (int j = 2; j <=n; ++j)
            if ((v[i] % j == 0) && (v[i] != j))  
                v[i] = 0;
    for (int x : v)
        if (x != 0)
            std::cout << x << '\n';
} */


