
//C++ version
//std::vector<int> v;
//   v.add(x); v.add(y); v.add(z);
//   v.sort();
//boost::list<int> v;


typedef struct {
   int data;
   struct node* next;
} node_t;

node_t *root = NULL;

void deleteall() 
{
   node_t *d = root;
   node_t *prev = NULL;
   while(d) {
      prev = d;
      d = d->next;
      free(prev);
   }
}

void sort()
{
   
}

void insert(node_t* p)
{
   p->next = root;  // hang existing list from new node
   root = p;        // hang new node from root
}

node_t *find(int v)
{
   node_t *p = root;
   while (p) {
      if (p->data == v)
         return p;
      p = p->next;
   }
   return NULL;
}

node_t *remove(node_t* n)
{
   node_t *d = root;   
   node_t *prev = NULL;
   if (!d)
      return NULL;
   while (d != n) {
      prev = d;
      d = d->next;
      if (d == NULL)
         return NULL;
   }      
   if (!prev) 
      root = d->next; 
   else 
      prev->next = d->next; 
   return d;
}

void insert_at_end(node_t* p) //later
{
   return NULL; 
}

int main(int argc, void* argv[]) 
{
	return 0;  
}

