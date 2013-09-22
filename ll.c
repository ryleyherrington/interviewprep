
//C++ version
//std::vector<int> v;
//   v.add(x); v.add(y); v.add(z);
//   v.sort();
//boost::list<int> v;


typedef struct {
   int data;
   struct node* next;
} node_t;

typedef struct {
   node_t* root;
   int     count;
} list_t;

void deleteall(list_t *list) 
{
   node_t *d = list->root;
   node_t *prev = NULL;
   while(d) {
      prev = d;
      d = d->next;
      free(prev);
   }
}

int compare(const void*v1, const void*v2)
{
    node_t *p1 = (node_t*)v1;
    node_t *p2 = (node_t*)v2;
    return (p1->data - p2->data);
}

void sort(list_t* list)
{
   node_t* arr = (node_t*) calloc(sizeof(node_t*), list->count);
   node_t* p = list->root; 
   for( int i=0; i<list->count; i++) {
      arr[i]= p;
      p = p->next;
   }
   qsort(arr, list->count, sizeof(node_t*), compare); 

   list->root = arr[0];
   p = arr[0];
   for (int j=0; j<list->count; j++) {
      if (j+1 == list->count)
         p-> = NULL;
      p->next = arr[j+1];
      p = arr[j+1];
   }

   free(arr);
}

void insert(list_t* list, node_t* p)
{
   p->next = list->root;  // hang existing list from new node
   list->root = p;        // hang new node from root
   list->count++;        // hang new node from root
}

node_t *find(list_t* list, int v)
{
   node_t *p = list->root;
   while (p) {
      if (p->data == v)
         return p;
      p = p->next;
   }
   return NULL;
}

node_t *remove(list_t* list, node_t* n)
{
   node_t *d = list->root;   
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
      list->root = d->next; 
   else 
      prev->next = d->next; 
   list->count--;
   return d;
}

void insert_at_end(list_t* list, node_t* p) //later
{
   return NULL; 
}

int main(int argc, void* argv[]) 
{
    list_t list.root = NULL;
    list_t list.count = 0;
	return 0;  
}

