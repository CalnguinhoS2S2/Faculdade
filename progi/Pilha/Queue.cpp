#include <iostream>
#include <queue>
using namespace std;
int main(){
	queue<int> n;
	n.push(1);
	n.push(2);
	n.push(3);
	n.push(4);
	n.push(5);
	n.push(6);
	cout<<"tamanho: "<<n.size()<<endl;
	cout<<"head: "<<n.front()<<endl;
	cout<<"tail: "<<n.back()<<endl;
	n.pop();
	n.pop();
	n.push(7);
	cout<<"tamanho: "<<n.size()<<endl;
	cout<<"head: "<<n.front()<<endl;
	cout<<"tail: "<<n.back()<<endl;
}
