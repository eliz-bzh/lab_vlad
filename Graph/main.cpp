#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    std::cout<<"Obhod v shiriny"<<std::endl;
    queue<int> Queue;
    int mas[5][5] =
    {
        { 0, 1, 1, 0, 0},
        { 1, 0, 1, 1, 0},
        { 1, 1, 0, 0, 1},
        { 0, 1, 0, 0, 1},
        { 0, 0, 1, 1, 0}
    };
    int nodes[5];
    for (int i = 0; i < 5; i++)
    {
        nodes[i] = 0;
    }
    Queue.push(nodes[0]);
    while (!Queue.empty())
    {
        int node = Queue.front();
        Queue.pop();
        nodes[node] = 2;
        for (int j = 0; j < 5; j++)
        {
            if (mas[node][j] == 1 && nodes[j] == 0)
            {
                Queue.push(j);
                nodes[j] = 1;
            }
        }
        cout << node  << endl;
    }

    std::cout<<std::endl;
    std::cout<<"Obhod v glubiny"<<std::endl;
    stack<int> Stack;
    for (int i = 0; i < 5; i++)
    {
        nodes[i] = 0;
    }
    Stack.push(nodes[0]);
    while (!Stack.empty())
    {
        int node = Stack.top();
        Stack.pop();
        nodes[node] = 2;
        for (int j = 0; j < 5; j++)
        {
            if (mas[node][j] == 1 && nodes[j] == 0)
            {
                Stack.push(j);
                nodes[j] = 1;
            }
        }
        cout << node << endl;
    }
    return 0;
}
