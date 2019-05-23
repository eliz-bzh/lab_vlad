#include<conio.h>
#include<iostream>

int a,b,u,v,n,i,j,ne=1;
int min,mincost=0;

int main()
{
    setlocale(LC_ALL, "Rus");

    int path_index=0;
    std::cout<<"Введи количество вершин  ";
    std::cin>>n;
    std::cout<<"Введи матрицу смежности\n";
    int visited[n+1]= {0};
    int path[n]= {0}; //В этот массив будут записываться вершины, по которым составиться путь
    int cost[n+1][n+1];
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            //std::cout<<i-1<<"-"<<j-1<<" ";
            std::cin>>cost[i][j];
            if(cost[i][j]==0)
            {
                cost[i][j]=100;
            }
        }
        visited[1]=1;
        std::cout<<"\n";
    }


    while(ne < n)
    {
        for(i=1,min=100; i<=n; i++)
            for(j=1; j<=n; j++)
                if(cost[i][j]< min)
                    if(visited[i] == 1)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
        if(visited[u]==0 || visited[v]==0)
        {
            path[path_index]=b;
            path_index++;
            ne++;
            mincost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=100;
    }
    /*
    0
    4
    5
    0
    0
    0
    0
    0
    8
    11
    0
    0
    0
    0
    0
    5
    3
    0
    0
    0
    0
    0
    0
    3
    0
    0
    0
    0
    0
    6
    0
    0
    0
    0
    0
    0
    */

    std::cout<<"\n";
    std::cout<<0;
    for (int i=0; i<n-1; i++)
    {
        std::cout<<" --> "<<path[i]-1;
    }
    std::cout<<"\n Минимальная стоимость  "<<mincost<<std::endl;

    return 0;
}
