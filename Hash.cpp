#include <iostream>
#include <vector>
using namespace std;
enum Estado{
  e,f};
template <class O, class P>
class Table{
private:
//Implementación de encadenamiento
  pair<O *, vector<P> *> t;
  Estado c;
public:
  template <class U, class I>
  friend class HashT;
  Table(){
    t.first = NULL;t.second = new vector<P>;c = e;
  }
  ~Table(){}
};
template <class O, class P>
class HashT{
private:
  Table<O, P> *test;
  unsigned int size;
private:
//Implementación del sondeo lineal.
  int HashF(O key, int i){
    return (key + i) % size;
  }
public:
  HashT(unsigned int size){
    this->size = size;
    test = new Table<O, P>[size];
  }
  ~HashT(){
    for (unsigned int i = 0; i < size; i++){
      if (test[i].t.first != nullptr){
        delete test[i].t.first;
      }
      delete test[i].t.second;
    }
    delete[] test;
  }
  void Insert(O key, P data){
    int i = 0;
    for (unsigned int i = 0; i < size; i++){
      i = HashF(key, i);
      if (test[i].c == e){
        test[i].c = f;
        test[i].t.first = new O(key);
        test[i].t.second->push_back(data);
        return;
      }
      else if (*test[i].t.first == key){
        test[i].t.second->push_back(data);
        return;
      }
    }
    return;
  }
  void Print(){
    cout<<"Index\t"<<"Key\t"<<"Datos\n";
    for (unsigned int i = 0; i < size; i++){
      cout<<i<<"\t";
      if (test[i].t.first == nullptr){
        cout << "NULL\n";
      }else{
        cout << *test[i].t.first << "\t";
        for (const auto &j : *test[i].t.second){
          cout << j << ", ";
        }
        cout << endl;
      }
    }
  }
};
//Función de prueba
int main(){
  HashT<int, string> test(10);
  test.Insert(12, "Guitarra");
  test.Insert(12, "Bajo");
  test.Insert(12, "Ukulele");
  test.Insert(7, "Trompeta");
  test.Insert(7, "Saxofon");
  test.Insert(9, "Timbal");
  test.Insert(9, "Bombo");
  test.Insert(9, "Platillo");
  test.Insert(2, "Otomatone");
  test.Print();
  return 0;
}