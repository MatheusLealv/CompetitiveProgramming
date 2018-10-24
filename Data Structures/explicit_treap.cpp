
struct node
{
	int val, w, sz;

	node *l, *r;

	node(int x)
	{
		val = x, w = rand(), sz = 1;

		l = r = NULL;
	}
};

node *root = NULL;

int n;

inline int Sz(node *root){
	return (root ? root->sz : 0);
}

inline void upd(node *root)
{
	if(!root) return;

	root->sz = Sz(root->l) + Sz(root->r) + 1;
}

void Merge(node *&root, node *l, node *r)
{
	if(!l or !r) root = (l ? l: r);

	else
	{
		if(l->w > r->w) Merge(l->r, l->r, r), root = l;

		else Merge(r->l, l, r->l), root = r;

		upd(root);
	}
}

void Split(node *root, node *&l, node *&r, int x)
{
	if(!root) l = r = NULL;

	else
	{
		if(root->val < x) Split(root->r, root->r, r, x), l = root;

		else Split(root->l, l, root->l, x), r = root;

		upd(root);
	}
}


bool Find(node *root, int x)
{
	if(!root) return false;

	if(root->val == x) return true;

	if(x > root->val) return Find(root->r,  x);

	return Find(root->l, x);
}

inline void insert(int x)
{
	if(Find(root, x)) return;

	node *l = NULL, *r = NULL, *novo = new node(x);

	Split(root, l, r, x);

	Merge(l, l, novo);

	Merge(root, l, r);
}

inline void erase(int x)
{
	if(!Find(root, x)) return;

	node *l = NULL, *r = NULL, *l1 = NULL, *r1 = NULL;

	Split(root, l, r, x + 1);

	Split(l, l1, r1, x);

	Merge(root, l1, r);
}

inline int Smaller_than(int x)
{
	node *l = NULL, *r = NULL, *l1 = NULL, *r1 = NULL;

	Split(root, l, r, x);

	int ans = Sz(l);

	Merge(root, l, r);

	return ans;
}

inline int Kth_element(node *root, int k)
{
	int p = Sz(root->l) + 1;

	if(p == k) return root->val;

	if(p > k) return Kth_element(root->l, k);

	return Kth_element(root->r, k - p);
}
