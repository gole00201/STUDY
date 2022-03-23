#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
int main()
{
    std::vector<int> Start_Arr;
    std::vector<int> Ham_Arr;
    int io = 2; int Minput = 0; int Hiput = 0; /* int Execption = 0; */; int Counter = 0;
    std::cout << "Enter M: "; std::cin >> Minput;
    std::cout << "Enter hmin: "; std::cin >> Hiput;
    for (int n = 2; n < 33554432; n = 1 << io)
    {
        for (int hmin = 1; hmin <= io ; ++hmin)
        {
            for (int i = 0; i <= pow(2 , io) - 1 ; ++i)//Генерация стартовой последовательности
                Start_Arr.push_back(i);
            Ham_Arr.push_back(Start_Arr[0]);

            for (int i = 1; i <= pow(2 , io) - 1; ++i)//Первая итерация проверки нулевой со всмеи и заполнение массива
                if (__builtin_popcount(Start_Arr[0] ^ Start_Arr[i]) >= hmin) Ham_Arr.push_back(Start_Arr[i]);

            for (int i = 0; i <= Ham_Arr.size(); ++i)//Вторая итерация првоерка каждый с каждым
                for (int j = 0; j <= Ham_Arr.size(); ++j)
                    if ((i != j)&&(Ham_Arr[j] != 0))
                        if (__builtin_popcount(Ham_Arr[i] ^ Ham_Arr[j]) < hmin)
                            Ham_Arr[j] = 0;     
            Ham_Arr.erase(std::remove(Ham_Arr.begin(), Ham_Arr.end(), 0), Ham_Arr.end());

            if (Minput == Ham_Arr.size() && hmin == Hiput)//Проверка на соотвествие инпутам
            {
                std::cout <<"\n"; std::cout <<"\n";
                std::cout << "M = "<< Ham_Arr.size() << " hmin = " << hmin << " n = " << io << '\n';
                std::cout <<"\n";
                std::cout <<"[ ";
                for (int OutPut : Ham_Arr)
                {
                    if (Counter >= 8)
                    {
                            std::cout << "\n";
                            Counter  = 0;
                    }
                    std::cout << OutPut << " ";
                    ++Counter;
                }
                std::cout << "]";
            }

            Ham_Arr.clear();
            Start_Arr.clear();  
            Counter = 0;
        }
        ++io;
    }
}
