#include<bits/stdc++.h>
using namespace std;
const int maxnode=4;
int visit[maxnode], d[maxnode], parent[maxnode], w[maxnode][maxnode], u;

int findmin(int d[maxnode], int visit[maxnode]) //function to extract minimum
{
    int min_loc=0, min = visit[0], tem;
        for(int i=1; i<maxnode; i++)
        {
            if(visit[i] == 0)
            {
                if(visit[i] < min)
                {
                    min = visit[i];
                    min_loc = i;
                }
            }
        }

    visit[min_loc] = 1; //visit array is to keep track of the visited nodes
    return min_loc;
}

void Dijkstra(int G[maxnode][maxnode], int s)
{
    int u,v;
    for(int i=0; i<maxnode; i++)
    {
        visit[i] = 0;
        d[i] = 9999;
        parent[i] = -1;
    }
    d[s] = 0;
    for(int i=1; i<maxnode; i++)
    {
        u = findmin(d, visit);

        visit[u]=1;
        for(int j=1; j<maxnode; j++)
        {
            if(G[u][j] != 0)
            {
                if(d[j] > d[u]+G[u][j])
                {
                    d[j] = d[u]+G[u][j];
                    parent[j] = u;
                }
            }
        }
    }
}
int main()
{
    int G[maxnode][maxnode] = { {0,2,5,10},
                                {0,0,6,0},
                                {0,0,0,1},
                                {0,0,0,0}};
    Dijkstra(G, 0);

    cout << "Vertex:    Distance:     Parent:" << endl;
    for(int i=0; i<maxnode; i++)
    {

        cout << i << "             " << d[i] << "               " << parent[i]<<endl;
    }



    return 0;
}

