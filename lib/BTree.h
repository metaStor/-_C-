#include "stdio.h"
#include "stdlib.h"


typedef int ElemType


typedef struct tnode {
	ElemType data;
	struct tnode *lchild, *rchild;
} BTNode;
