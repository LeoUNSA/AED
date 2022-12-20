#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Grafo{
private:
	int nVert; //Vertices del grafo y lista de adyasencia
	list<int>* adjLists; 
public:
	Grafo(int nVert){
		this->nVert = nVert;adjLists = new list<int>[nVert];
	} 
	~Grafo(){delete [] adjLists;}
	void Insertar(int v, int w){
		adjLists[v].push_back(w);
	}
	void printGraph() const{
		list<int>::iterator j;
		cout << "Vertices\n";
		for(int i = 0; i < nVert; i++){
			cout << i << " - \t";
			if (!adjLists[i].empty()){
				for (j = adjLists[i].begin(); j != adjLists[i].end(); j++){
					cout <<*j<<" ";
				}
			}
			else{
				cout << "NULL";
			}
			cout << endl;
		}
	}
	void BFS(int s){
		vector<bool> vis;
		vis.resize(nVert,false);
		queue<int> queue;
		vis[s] = true;
		queue.push(s);
		cout << "BFS - Desde el vertice " << s << endl;
		while(!queue.empty()){
			s = queue.front();
			cout << s << " ";
			queue.pop();
			for (const auto& adjecent: adjLists[s]){
				if (!vis[adjecent]){
					vis[adjecent] = true;
					queue.push(adjecent);
				}
			}
		}
	}
};
int main(){
	Grafo G1(6);
	G1.Insertar(0, 4);
	G1.Insertar(0, 3);
	G1.Insertar(3, 1);
	G1.Insertar(3, 5);
	G1.Insertar(5, 4);
	G1.Insertar(1, 2);
	G1.Insertar(4, 1);
	G1.Insertar(4, 2);
	G1.printGraph();
	cout << "BFS" << endl;
	G1.BFS(4);
	return 0;
}
