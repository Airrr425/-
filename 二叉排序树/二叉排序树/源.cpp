template<typename T1,typename T2>
struct BSTNode {
	T1 key;
	T2 data;
	BSTNode* lchild;
	BSTNode* rchild;
	BSTNode(T1 k, T2 d) {
		key = k;
		data = d;
		lchild = rchild = NULL;
	}
};
template<typename T1, typename T2>
class BSTClass {
public:
	BSTNode<T1, T2>* r;
	BSTNode<T1, T2>* f;
};