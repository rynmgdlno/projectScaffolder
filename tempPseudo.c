// YAML parser:


// - get number of nodes (size)
int const size = 10;
// - allocate memory for number of nodes w/ sizeof?
// - generate tree / verify it can be made into a tree:

// typing the node and tree:
typedef struct Node
{
  char name[30];
  char type[30];
  struct Node* children[5]; // figure out dynamic arrays
} nodeP;

struct Node Tree[size]; //





char test[] = {0,1,2,3,4};



