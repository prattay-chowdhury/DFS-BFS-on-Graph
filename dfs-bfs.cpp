// DFS and BFS in a disconneted undirected graph 
//Submitted by Prattay Chowdhury
//Here graph is represented by adjacency matrix 

#include<iostream>
#include<queue>
using namespace std;

class graph {
	private:
		int vertex_count;
		bool** adjacency_matrix;
		bool* visited;
		int* vertex_val;
		queue<int> q;

	public:
		graph(int v_count,int* val);
		void add_edge(int i, int j);
		void print_vertices();
		void print_edges();
		void DFS(int start_index);
		void clear_visit();
		void BFS(int start_index);
};

graph::graph(int v_count, int* val){
	
	//creating empty adjencey matrix with the dimention of vertex count	
	vertex_count=v_count;

	adjacency_matrix = new bool*[vertex_count];
	
	for(int i=0; i<vertex_count; i++){
		adjacency_matrix[i] = new bool[vertex_count];
    
		for(int j=0; j<vertex_count; j++){
			adjacency_matrix[i][j] = 0;
		}
	}
	vertex_val = val;
  
	//creating empty visit flag
	visited = new bool[vertex_count];
	
	for(int k=0; k<vertex_count; k++)
		visited[k]=0;
}


void graph::add_edge(int i, int j){
	//changing value in adjencent matrix to create edge  
    adjacency_matrix[i][j]=1;
    adjacency_matrix[j][i]=1;
  
}

void graph::print_vertices(){
	
	for(int i=0; i<vertex_count; i++){
		cout << vertex_val[i]<<' ';
	}
  
	cout << endl;
}

void graph::print_edges(){
	
	for(int i=0; i<vertex_count; i++){
		for(int j=i; j<vertex_count; j++){
			if(adjacency_matrix[i][j]==1)
			cout << '(' << vertex_val[i] << ',' << vertex_val[j] <<')' << ' ';
		}
	}
  cout << endl;
}





void graph::DFS(int start_index){
	int i,j;

	for (i=start_index; i<vertex_count; i++) { //loop goes on untill 
		
		if (visited[i]==0&&i!=start_index)    //starts traversing from first non visited vertex after one disconnected part is finished
			cout<<"(DFS starting again) ";
		
		if (visited[i]==0) {
			
			cout << vertex_val[i] << ' ';
			visited[i]=1;
			
			for(j=0; j<vertex_count; j++){
				if(adjacency_matrix[i][j]==1 && visited[j]==0)
					DFS(j);
			}
			
		}
	}
}




void graph::clear_visit(){
  
	for(int i=0; i<vertex_count; i++)
		visited[i]=0;
}



void graph::BFS(int start_index){
	int i,j,k;
	int next_vertex;
  
	i=start_index;
	cout << vertex_val[i] << ' ';
	visited[i]=1;
	
	for(j=0; j<vertex_count; j++){
		
		if(adjacency_matrix[i][j]==1 && visited[j]==0){
			q.push(j);
			visited[j]=1;
		}
	}
  
	if(q.empty()){
		
		for (k=0;k<vertex_count;k++)  //search if any disconnected part of graph left to traverse
			if (visited[k]==0){
			cout<<"(BFS starting again) ";
			BFS(k);				  //start BFS again from the first disconnected vertex found 
			}
	
		return;   //return when all vertices are visited
	}	
	
	next_vertex = q.front();
	q.pop();   
	BFS(next_vertex);  
}


int main()
{
	int val[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};  //15 vertices value 
	graph A(15, &val[0]);
  
	//25 edges are created below
	//16 edges between 0 to 9
	A.add_edge(0,1);
	A.add_edge(1,3);
	A.add_edge(0,3);
	A.add_edge(4,0);
	A.add_edge(4,7);
	A.add_edge(4,5);
	A.add_edge(0,5);
	A.add_edge(3,5);
	A.add_edge(3,2);
	A.add_edge(7,5);
	A.add_edge(6,2);
	A.add_edge(6,9);
	A.add_edge(5,9);
	A.add_edge(7,8);
	A.add_edge(8,9);
	A.add_edge(1,2);
  
 
	//9 edges between 10 to 14
	A.add_edge(10,11);
	A.add_edge(10,12);
	A.add_edge(10,13);
	A.add_edge(10,14);
	A.add_edge(11,12);
	A.add_edge(11,14);
	A.add_edge(12,13);
	A.add_edge(12,14);
	A.add_edge(13,14);
 

	cout << "Vertices in the graph: "<<endl;
	A.print_vertices();
	cout << endl << endl;
  
	cout << "Edges in the graph: "<<endl;
	A.print_edges();
	cout << endl << endl;
  
  
	cout << "DFS order: "<<endl;
	A.DFS(0);  //starts from index 0
	A.clear_visit();  //visit is cleared for BFS traversal
	cout << endl << endl;
  

	cout << "BFS order: "<<endl;
	A.BFS(0); //starts from index 0
	cout << endl;

	return 0;
}
