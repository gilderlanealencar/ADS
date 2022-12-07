#include <stack>
#include <iostream>
using namespace std;

template <class T>
class Stack: public stack<T> {
	protected:
		stack<T> pilha;
	public:
	T popStack(){
		T tmp=pilha.top();
		pilha.pop();
		return tmp;
	}
	
	
	void popTodos(){
		while (!pilha.empty()){
			cout << popStack() << endl;
		}	
    }
	
	void simulaFila(T novo){
		stack<T> maniPilha;
		while (!maniPilha.empty()){
			maniPilha.push(popStack());
		}
		pilha.push(novo);

		while (!maniPilha.empty()){
			pilha.push(maniPilha.top());
			maniPilha.pop();
		}

		free(&maniPilha);
	}
	
};

main(){
	Stack<int> fila;
	fila.simulaFila(1);
	fila.simulaFila(2);
	fila.simulaFila(4);
	fila.simulaFila(8);
	fila.simulaFila(12);
	fila.popTodos();

}
