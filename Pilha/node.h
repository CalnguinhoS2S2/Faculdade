#include "trem.h"
class node{
	public:
		trem D;
		node *next;
		static node *montaNode(trem Dat);
		static trem desmontaNode(node *P);
};
