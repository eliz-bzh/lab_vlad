#include <iostream>
using namespace std;
int i, j;
const int size = 5;
int GR[size][size] =
{
    {0,9,0,0,0},
    {0,0,0,7,2},
    {0,0,0,0,1},
    {0,0,2,0,0},
    {8,0,0,0,0}
};
/*int GR[size][size] =
{
    {0,0,0,6,1},
    {0,0,0,0,3},
    {0,0,0,0,0},
    {0,2,8,0,0},
    {0,0,0,0,0}
};*/
void FU(int D[][size], int V)
{
    int k;
    for (i=0; i<V; i++)
    {
        D[i][i]=0;
    }

    for (k=0; k<V; k++)
    {
        for (i=0; i<V; i++)
        {
            for (j=0; j<V; j++)
            {
                if (D[i][k] && D[k][j] && i!=j)
                {
                    if (D[i][k]+D[k][j]<D[i][j] || D[i][j]==0)
                    {
                        D[i][j]=D[i][k]+D[k][j];
                    }
                }
            }
        }
    }

    for (i=0; i<V; i++)
    {
        for (j=0; j<V; j++)
        {
            if(D[i][j] == 0 && i!=j)
            {
                cout<<"~"<<"\t";
            }
            else
            {
                cout<<D[i][j]<<"\t";
            }

        }
        cout<<endl;
    }
}
int main()
{
    cout<<"Matrix short way:"<<endl;
    FU(GR, size);
    return 0;
}
