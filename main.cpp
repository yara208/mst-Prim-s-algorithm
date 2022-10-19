#include<iostream>
using namespace std;
#define V 7
int m_k(int k[], bool MST[])
{
    int i;
    int minimum = INT_MAX, min_ind;

    for ( i = 0; i < V; i++)
        if (MST[i] != true && k[i] < minimum)
            minimum = k[i], min_ind = i;

    return min_ind;
}

void print (int p[], int g[V][V])
{
    cout<<"edges "<<" -->  " <<" weights"<<endl;
    for (int i = 1; i < V; i++)
        cout<<p[i]<<" - "<<i<<" -->"<<g[i][p[i]]<<endl;
}

void prim(int g[V][V])
{

    int p[V], k[V] ;
    bool MST[V];
    for (int i = 0; i<V; i++)
    {
        k[i] = INT_MAX, MST[i] = false;

        k[0] = 0;
        p[0] = -1; // root
    }


    for (int i = 0; i < V - 1; i++)
    {
        int x = m_k(k, MST);
        MST[x] = true;
        for (int i = 0; i < V; i++)

            if (g[x][i] && MST[i] != true && g[x][i]< k[i])
                p[i] = x, k[i] = g[x][i];
    }

    print(p, g);
}

int main()
{
    int g[V][V] = {{0,2,4,1,0,0,0},{2,0,0,3,10,0,0},{4,0,0,2,0,6,0},{1,3,2,0,7,8,4},{0,10,0,7,0,0,6},{0,0,5,8,0,0,1},{0,0,0,4,6,1,0}};
    prim (g);
    return 0;
}
