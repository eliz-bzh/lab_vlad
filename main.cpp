#include <iostream>
#include <algorithm>
#include <vector>
#define print_contener(first, last) std::for_each(first, last, [](int v){std::cout<<v<<" ";});
#include "stu_alg.h"
#include <cmath>
int main()
{
    int n, m;
    std::cout<<"Input n: ";
    std::cin>>n;
    std::cout<<"Input m: ";
    std::cin>>m;
    int array3[] = {};
    stu::shell(stu::arrays(stu::start(n),n,stu::start(m),m,array3),n+m);
    return 0;
}
