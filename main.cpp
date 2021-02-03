#include<bits/stdc++.h>
#include <vector>

using namespace std;

struct Graph{
    int maxVertex;


    void addEdge(int matrix[], int max){
        this->maxVertex = max;
        int x, y;
        vector<int> edges [max];
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

};

// function for finding minimum no. of edge
// using BFS
int minEdgeBFS(vector <int> edges[], int u,
							int v, int n)
{
	// visited[n] for keeping track of visited
	// node in BFS
	vector<bool> visited(n, 0);

	// Initialize distances as 0
	vector<int> distance(n, 0);

	// queue to do BFS.
	queue <int> Q;
	distance[u] = 0;

	Q.push(u);
	visited[u] = true;
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		for (int i=0; i<edges[x].size(); i++)
		{
			if (visited[edges[x][i]])
				continue;

			// update distance for i
			distance[edges[x][i]] = distance[x] + 1;
			Q.push(edges[x][i]);
			visited[edges[x][i]] = 1;
		}
	}
	return distance[v];
}

void checkMatrix(int matrix[], int m){

}

// function for addition of edge
void addEdge(vector <int> edges[], int u, int v)
{
edges[u].push_back(v);
edges[v].push_back(u);
}

// Driver function
int main()
{   

    int n, m, x;
    int max = 0;

    //num of graphs
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>m;
        int **matrix = new int*[m];
        //single graph
        for(int j = 0; j<m; j++){
            //row of connections
            int *mat = new int[2];
            for(int k = 0; k<2; k++){
                cin>>x;
                mat[k] = x;
            }
            matrix[j] = mat;
        }
        cout<<endl;
        for(int x = 0; x<m; x++){
            for(int y = 0; y<2; y++){
                cout<<matrix[x][y]<<" ";
            }
            cout<<endl;
        }
    }

	// To store adjacency list of graph
	// int n = 9;
	// vector <int> edges[6];
	// addEdge(edges, 0, 1);
	// addEdge(edges, 0, 2);
	// addEdge(edges, 0, 3);
	// addEdge(edges, 1, 3);
	// addEdge(edges, 3, 5);
    // addEdge(edges, 4, 4);

	// int u = 2;
	// int v = 5;
	// cout << minEdgeBFS(edges, u, v, n);
	return 0;
}
