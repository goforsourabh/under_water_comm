#include<bits.stdc++.h>
using namespace std;
//function return which is the closest master node to the given node 
//function returns the node number to us

//this function basically minimises the relay connection loss for us
int  jumps(vector<pair<int,double>>graph[size],int threshold ,vector<pair<int,int>>&p1,set<int>&master,int s)
{
	int size= p1.size();// this is the  no of nodes we have
	bool visited[size];
	memset(visited, false, sizeof(visited));
	visited[s]= true;
	pair<int,pair<int,double>>p1;//data type to store our queue data
	queue<pair<int,pair<int,double>>>q1;//first is the jump ,second is the index (node no), third is the loss
	p1.push(make_pair(0,make_pair(s,0)));//start bfs
	while(!queue.empty()) 
    { 
        
        p1 = queue.front(); 
        int s= p1.second.first;
        int loss=p1.second.second;
        int jumpno=p1.first;
        queue.pop_front(); 
  		if( master.find(s)!=master.end())
  		{
  			return s;
  		}
        
        for (int i = graph[s].begin(); i != graph[s].end(); ++i) 
        { 
            if (!visited[graph[s][i]] && loss<=threshold) 
            { 
                visited[graph[s][i].first] = true; 
                queue.push_back(make_pair(p1.first+1,make_pair(graph[s][i].first,loss +graph[s][i].second))); 
            } 
        } 
    } 
} 
int connectedcomponentsutility (vector<pair<int,double>>graph[size],int threshold,vector<bool>&visited ,vector<pair<int,int>>&p1,set<int>&master,int s)
{

int size= p1.size();// this is the  no of nudes we have
	
	visited[s]= true;
	pair<int,pair<int,double>>p1;//data type to store our queue data
	queue<pair<int,pair<int,double>>>q1;//first is the jump ,second is the index (node no), third is the loss
	p1.push(make_pair(0,make_pair(s,0)));//start bfs
	while(!queue.empty()) 
    { 
        
        p1 = queue.front(); 
        int s= p1.second.first;
        int loss=p1.second.second;
        int jumpno=p1.first;
        queue.pop_front(); 
  		
        
        for (int i = graph[s].begin(); i != graph[s].end(); ++i) 
        { 
            if (!visited[graph[s][i]] && loss<=threshold) 
            { 
                visited[graph[s][i].first] = true; 
                queue.push_back(make_pair(p1.first+1,make_pair<graph[s][i].first,loss +graph[s][i].second)); 
            } 
        } 
    } 
} 
int connectedcomponentswrapper (vector<pair<int,double>>graph[size],int threshold ,vector<pair<int,int>>&p1,set<int>&master,int s)
{
	int size= p1.size();
	vector<int>visited(size,0);
	int count =0;
	for( int i-0 ; i< size ; i++)
	{
		if(!visited[i])
		{
		connectedcomponentsutility (vector<pair<int,double>>graph[size],int threshold,vector<bool>&visited ,vector<pair<int,int>>&p1,set<int>&master,int i)
		count++;
		}
	}
	return count ;

}
void masternodes (int graph[][V], int size, int threshold)  
{  
	int V= size;
    /* dist[][] will be the output matrix  
    that will finally have the shortest  
    distances between every pair of vertices */
    int dist[V][V], i, j, k;  
  
    
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
  
    
    for (k = 0; k < V; k++)  
    {  
        // Pick all vertices as source one by one  
        for (i = 0; i < V; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            for (j = 0; j < V; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
    //dekho yahan ki exact location best kaise nikal sakt  hai yahan hum
    //ye function teels us kitne nodes are connected given our threshold communication loss value;
  	for( int i=0 ; i< V ; i++)
  	{
  		for( int j=0 ; j<V ; j++)
  		{
  			if(dist[i][j]>threshold)
  			{
  				dist[i][j]=0;
  			}
  			else 
  			{
  				dist[i][j]=1;
  			}
  		}
  	}
    
    printSolution(dist);  
}  
  
/* A utility function to print solution */
void printSolution(int dist[][V])  
{  
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<dist[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
}  



