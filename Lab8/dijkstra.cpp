#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include <limits>
using namespace std;
struct Nodo {
	 int d;
	 int c;
   friend std::ostream &operator<<(std::ostream &os, const Nodo &n) { 
       return os << "{" << n.d << "," << n.c << "}";
   }
};
class Graph {
private:
	int nVert;
	list<Nodo>* adjL;
public:
	Graph(int nVert) {
		this->nVert = nVert;
		adjL = new list<Nodo>[nVert];
	}
	~Graph(){
		delete [] adjL;
	}
	void Print() const{
		list<Nodo>::iterator j;
		cout << "Vertices\n";
		for (int i = 0; i < nVert; i++){
			cout << i << " -->\t";
			if (!adjL[i].empty()){
				for (j = adjL[i].begin(); j != adjL[i].end(); j++){
					cout << *j << " ";
				}
			}
			else{
				cout << "NULL";
			}
			cout << endl;
		}
	}
	void Insertar(int src, int d, int c) {
		Nodo n;
		n.d = d;
		n.c = c;
		adjL[src].push_back(n);
	}
	void dijkstra(const int start){
		int* dis = new int[nVert];
		int* aVert = new int[nVert];
		for(int u = 0; u < nVert; u++) {
			dis[u] = std::numeric_limits<int>::max();   
			aVert[u] = -1;    
		}
		dis[start] = 0;   
		set<int> S;       
		list<int> Q;
		for(int u = 0; u < nVert; u++) {
			Q.push_back(u);    
		}
		while(!Q.empty()) {
			list<int> :: iterator i;
			i = min_element(Q.begin(), Q.end());
			int u = *i; 
			Q.remove(u);
			S.insert(u); 
			list<Nodo> :: iterator it;
			for(it = adjL[u].begin(); it != adjL[u].end();it++){
				if((dis[u]+(it->c)) < dis[it->d]){
					dis[it->d] = (dis[u]+(it->c));
					aVert[it->d] = u;
				}
			}
		}
		for(int i = 0; i < nVert; i++){
			if(i != start){
				cout<<start<<" a "<<i<<", coste = "<<dis[i]<<", vertice anterior = "<<aVert[i]<<endl;
			}
		}
		delete [] aVert, dis;
	}
};
int main(){
	Graph G1(6);
	G1.Insertar(0, 2, 5);
	G1.Insertar(0, 1, 3);
	G1.Insertar(1, 3, 1);
	G1.Insertar(1, 4, 2);
	G1.Insertar(2, 4, 3);
	G1.Insertar(2, 5, 4);
	G1.Insertar(3, 6, 2);
	G1.Insertar(4, 5, 2);
	G1.Print();
	cout << "Dijkstra" << endl;
	G1.dijkstra(0);
	return 0;
}
