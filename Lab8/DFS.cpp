#include <iostream>
#include <list>
#include <vector>
using namespace std;
class Grafo{
private:
	int nVert;
	list<int>* adjL;
public:
	Grafo(int nVert){
		this->nVert=nVert;adjL=new list<int>[nVert];
	}
	~Grafo(){delete [] adjL;}
	void Insertar(int src, int dest){
		adjL[src].push_front(dest);
	}
	void Print() const{
		list<int>::iterator j;cout<<"Vertices\n";
		for (int i=0;i<nVert;i++){
			cout<<i<<" - \t";
			if (!adjL[i].empty()){
				for (j = adjL[i].begin(); j != adjL[i].end(); j++){
					cout<<*j<< " ";
				}
			}
			else{
				cout<<"NULL";
			}
			cout<<endl;
		}
	}
	void DFS(int vertex){
		vector<bool> vis;
		vis.resize(nVert,false);
		vis[vertex]=true;
		list<int> adjList = adjL[vertex];
		cout<<vertex<<" ";
		list<int>::iterator i;
		for (i = adjList.begin(); i != adjList.end(); ++i)
			if (!vis[*i]){
				DFS(*i);
		}			
	}
};
int main() {
	Grafo G1(6);
	G1.Insertar(0, 4);
	G1.Insertar(0, 3);
	G1.Insertar(3, 1);
	G1.Insertar(3, 5);
	G1.Insertar(5, 4);
	G1.Insertar(1, 2);
	G1.Insertar(4, 1);
	G1.Insertar(4, 2);
	G1.Print();
	cout << "DSF:\n";
	G1.DFS(4);
  return 0;
}
