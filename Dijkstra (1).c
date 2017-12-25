#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX],int n,int startnode);
int x[10] = {};
char* cities[11] = {"","New Delhi","Jaipur","Mumbai","Panaji","Bangalore","Kochi","Chennai","Hyderabad","Bhubaneshwar","Guwahati"};


int main()
{
    int distances[10][10] = {   {0,261,1402,1845,2153,2700,2190,1564,1666,1976},
                                {261,0,1146,1588,2002,2194,1567,1710,2020},
                                {1402,1146,0,571,985,1540,1338,708,1668,2881},
                                {1845,1588,571,0,593,789,945,665,1710,3298},
                                {2153,2002,985,593,0,548,346,570,1417,2860},
                                {2700,2558,1540,789,548,0,693,1116,1851,0},
                                {2190,2194,1338,945,346,693,0,627,1228,2670},
                                {1564,1567,708,665,570,1116,627,0,1050,2492},
                                {1666,1710,1668,1710,1417,1851,1228,1050,0,1442},
                                {1976,2020,2881,3298,2860,0,2670,2492,1442,0}
                            };

    int G[MAX][MAX],i,j,n,u;
    printf("CITIES TO VISIT IN INDIA \n1.New Delhi \n2.Jaipur \n3.Mumbai \n4.Panaji \n5.Bangalore \n6.Kochi \n7.Chennai \n8.Hyderabad \n9.Bhubaneshwar \n10.Guwahati\n");
    printf("Enter the no. of cities to visit");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter serial no. of city no.%d:",i+1);
        scanf("%d",&x[i]);
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
                G[i][j] = distances[x[i]-1][x[j]-1];

    printf("\nEnter the serial no. of starting city:");
    scanf("%d",&u);
    dijkstra(G,n,u);

    return 0;
}

void dijkstra(int G[MAX][MAX],int n,int startnode)
{

    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;

    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the cost matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];

    //initialize pred[],distance[] and visited[]
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=INFINITY;

        //nextnode gives the node at minimum distance
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }

            //check if a better path exists through nextnode
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }
    //print the path and distance of each node
    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            printf("\nDistance to %s=%d",cities[x[i]],distance[i]);
            printf("\nPath=%d",i);

            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j);
            }while(j!=startnode);
    }


}
