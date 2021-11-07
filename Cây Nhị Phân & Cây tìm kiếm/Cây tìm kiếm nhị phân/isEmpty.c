#include <stdio.h>

typedef int KeyType;
struct Node
{

    int Key;

    struct Node *Left, *Right;
};
typedef struct Node *Tree;

int isEmpty(Tree T)
{
    if (T == NULL)
        return 1;
    return 0;
}


int main()
{
    Tree T = NULL;
    if (isEmpty(T))
    {
        printf("Cay rong");
    }
    else
    {
        printf("Khong rong");
    }
    return 0;
}
