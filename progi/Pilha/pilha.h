#include "trem.h"
#include "node.h"
class stack{
	public:
		node *top;
		int N;
		stack();
		trem Top();
		trem pop();
		bool push(trem x);
		int size();
		bool empty();
		~stack();
};
