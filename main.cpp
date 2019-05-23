#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <time.h>
int* start(int size)
{
    int* A = new int [size];
    for(int i = 0; i!= size; ++i)
    {
        A[i] =1+rand()%10;
        std::cout<<A[i]<<" ";
    }
    std::cout<<std::endl;
    return A;
}
template< class Iter >
void BubbleSort(Iter arr, int size)
{
    for(int i = 0; i < size - 1; ++i)
    {
        for(int j = 0; j < size - 1; ++j)
        {
            if (arr[j + 1] < arr[j])
            {
                std::swap(arr[j],arr[j+1]);
            }
        }
    }
}
template< class Iter >
int* BubbleSort_2(Iter arr, int size)
{
    for(int i = 0; i < size - 1; ++i)
    {
        for(int j = 0; j < size - 1; ++j)
        {
            if (arr[j + 1] < arr[j])
            {
                std::swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0; i<size; ++i)
    {
        std::cout<<arr[i]<<" ";
    }
    return arr;
}
int Search_Binary (int* arr, int left, int right)
{
    int midd = 0;
    int temp = 0;
    while (1)
    {
        midd = (left + right) / 2;
        if(arr[midd] % 3 == 0)
        {
            ++temp;
            arr[midd] = 1;
            return temp;
        }
        else
        {
            temp+=0;
            arr[midd] = 1;
            left+=2;
            midd = (left + right) / 2;
            if(arr[midd] % 3 == 0)
            {
                temp+=1;
                ++temp;
                arr[midd] = 1;
                return temp;
            }
            arr[midd] = 1;
            return temp;
        }
    }
}
void otvet(int* arr1,int left1, int right1, int* arr2, int left2, int right2)
{
    int SumA = 0;
    int SumB = 0;
    for(int i = 0; i!=right1; ++i)
    {
        SumA+=Search_Binary(arr1,left1,right1);
        BubbleSort(arr1,right1);
    }

    for(int j= 0; j!=right2; ++j)
    {
        SumB+=Search_Binary(arr2,left2,right2);
        BubbleSort(arr2,right2);
    }
    //std::cout<<"A: "<<SumA<<std::endl;
    //std::cout<<"B: "<<SumB<<std::endl;
    if(SumA>=SumB)
    {
        std::cout<<"SumA>=SumB"<<std::endl;
//        printmass(Search_Binary2(arr1,0,n),n);
    }
    else
    {
        std::cout<<"SumA<SumB"<<std::endl;
//        printmass(Search_Binary2(arr2,0,m),m);
    }
}
int** start_2 (int n, int m)
{
    int **A;
    A = new int *[n];
    for(int i = 0; i < n; ++i)
    {
        A[i] = new int [m];
    }
    return A;
}
void initializer (int** A, int n, int m)
{
    int sum = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            A[i][j] =1+rand()%10-5;
            std::cout << A[i][j] << " ";
            if(i + j + 1 == m && A[i][j] > 0)
            {
                sum *= A[i][m - 1 - i];
            }
        }
        std::cout << std::endl;
    }
    std::cout <<"Product: "<< sum << std::endl;
}
int average(int*array, int right)
{
    int sum = 0;
    for(int i=0; i!=right; ++i)
    {
        sum+=array[i];
    }
    return sum/right;
}
int a_lr1(int* array, int right, int key)
{
    //int key = accumulate(array,right)/right;
    std::cout<<std::endl;
    std::cout<<"Key: "<<key<<std::endl;
    int start = 0;
    int end = right-1;
    int midd;
    while(start< end)
    {
        midd = (start+end)/2;
        if(array[midd]==key)
        {
            return midd;
        }
        if(array[midd] < key)
        {
            start = midd+1;
        }
        if(array[midd] > key)
        {
            end = midd-1;
        }
    }
    return -1;
}
int b_lr1 (int** A, int n, int m, int key)
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            A[i][j] =1+rand()%10-5;
            std::cout << A[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(A[i][j] == key)
            {
                std::cout<<"Stroka: "<<i+1<<std::endl;
                std::cout<<"Stolbec: ";
                return j+1;
            }
        }
    }
    return -1;
}
int main()
{
    //6 7
    srand(time(NULL));
    int n,m;
    std::cout<<"Input n: ";
    std::cin>>n;
    std::cout<<"Input m: ";
    std::cin>>m;
    std::cout<<std::endl;
    std::cout<<"MasB"<<std::endl;
    otvet(start(n),0,n,start(m),0,m);
    std::cout<<std::endl;
    initializer(start_2(n,m),n,m);
    std::cout<<std::endl;
    int arr[7]= {1,3,2,6,4,5,0};
    std::cout<<a_lr1(BubbleSort_2(arr,7),7,average(arr,7))<<std::endl;
    std::cout<<std::endl;
    std::cout<<b_lr1(start_2(n,m),n,m,0)<<std::endl;
    return 0;
}

