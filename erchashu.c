#include <stdio.h>
 #include <stdlib.h>
 typedef struct Node
 {
     int data;
     struct Node *lchild, *rchild;
 } BiTNode, *BiTree;
 int N;
 
 BiTree CreateBiTree(int *nodelist, int position)
 {
     BiTree P;
     
     if (position > N || nodelist[position-1] == 0)
         return NULL;
     else
     {
         P = (BiTree)malloc(sizeof(BiTNode));
         P->data = nodelist[position-1]; 
         P->lchild = CreateBiTree(nodelist, 2 * position);
         P->rchild = CreateBiTree(nodelist, 2 * position + 1);
         return P;
     }
     return NULL;
 }
 
 int Get_Value(int oper, int oper1, int oper2)
 {
     switch ((char)oper)
     {
         case '+': return oper1 + oper2;
         case '-': return oper1 - oper2;
         case '*': return oper1 * oper2;
         case '/': 
             if (oper2 == 0) {
                 printf("错误：除数不能为0！\n");
                 return 0;
             }
             return oper1 / oper2;
         default: 
             printf("错误：非法运算符 %c\n", (char)oper);
             return 0;
     }
    
     return 0;
 }
 
 int Calculate(BiTree T)
 {
     int oper1 = 0;
     int oper2 = 0;
     if ((T->lchild == NULL) && (T->rchild == NULL))
         return T->data - '0';
     else
     {
         oper1 = Calculate(T->lchild);
         oper2 = Calculate(T->rchild);
         return Get_Value(T->data, oper1, oper2);
     }
     return 0;
 }
 int main()
 {
     BiTree T = NULL;
     int cal_result;
     
     int nodelist[7] = {'*', '+', '-', '1', '2', '6', '3'};
     N = 7;
     T = CreateBiTree(nodelist, 1);
     cal_result = Calculate(T);
     printf("Calculate result is [ %d ]\n", cal_result);
    
     return 0;
 }