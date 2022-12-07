#include <queue>
#include <iostream>
using namespace std;

template <class T>
class Queue: public queue<T> {
	protected:
		queue<T> fila;
	public:
	T popQueue(){
		T tmp=fila.front();
		fila.pop();
		return tmp;
	}
	
	
	void popTodos(){				
		while (!fila.empty()){
			cout << popQueue() << endl;
		}
		
    }
    
    void simulaPilha(T novo){
		fila.push(novo);
		while (fila.front() != novo){
			fila.push(popQueue());
		}
		
    }
};

main(){
	Queue<int> fila;
	fila.simulaPilha(1);
	fila.simulaPilha(2);
	fila.simulaPilha(3);

	cout<<fila.front()<<endl;
	cout << fila.popQueue() << endl;
	fila.popTodos();


}
