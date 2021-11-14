#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define MAXSIZE 1000


typedef int Status;
typedef int ElemType;

typedef struct LNode
{
    ElemType            data;
    struct LNode        *next;
}LNode, *LinkList;

/*
-------	Todo List -------
Change ListInsert to i version;
Compare List LocateElem compare函数的编写、测试，函数指针的学习;

*/

Status InitaList(LinkList* L);
Status DestroyList(LinkList* L);
Status ClearList(LinkList* L);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Status GetElem(LinkList L,int i,ElemType* e);
Status LocateElem(LinkList L,ElemType e,Status (*compare)(ElemType,ElemType));
// int compare();
Status PriorElem(LinkList L,ElemType cur_e,ElemType* pre_e);
Status NextElem(LinkList L,ElemType cur_e,ElemType* next_e);
Status ListInsert(LinkList* L,int i,ElemType e);
Status ListDelete(L,i,e);
// Status ListTraverse(L,visit());

void main(void){
  LinkList L;  int op = 1; int length =0;
  int position=0; ElemType data=0;
  int flag;
  ElemType cur_e,pre_e,next_e;
  while(op){
	system("clear");	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. IntiaList       7. LocateElem\n");
	printf("    	  2. DestroyList     8. PriorElem\n");
	printf("    	  3. ClearList       9. NextElem \n");
	printf("    	  4. ListEmpty     	10. ListInsert\n");
	printf("    	  5. ListLength     11. ListDelete\n");
	printf("    	  6. GetElem       	12. ListTrabverse\n");
	printf("    	  0. Exit\n");
	printf("-------------------------------------------------\n");
	printf("    请选择你的操作[0~12]:");
	scanf("%d",&op);
    switch(op){
		// Init an empty link list
	   	case 1:
			if(InitaList(&L)==OK) printf("线性表创建成功\n");
			else printf("线性表创建失败\n");
			getchar();getchar();
			break;
		// Destory a link list
	   	case 2:
			if(DestoryList(&L)==OK) printf("链表销毁成功\n");
			else printf("线性表销毁失败！\n");    
			getchar();getchar();
			break;
		// make an unempty list as a list
	   case 3:
			if(ClearList(&L)==OK) printf("链表清空成功\n");
		    else printf("线性表清空失败\n");       
			getchar();getchar();
			break;
		// judge if a link list is empty
		case 4:
		 	// printf("\n----ListEmpty功能待实现！\n");    		
			if(ListEmpty(L)){
				printf("链表为空链表\n");
			}else{
				printf("链表不为空链表\n");
			}
		 	getchar();getchar();
		 	break;
		// get list length
	   	case 5:
			length = ListLength(L);
			if(length == INFEASTABLE){printf("链表不存在，请初始化链表\n");}
			else{
				if(length == 0){
					printf("链表为空表");
				}else{printf("链表长度为:%d",length);}
			}
			getchar();getchar();
			break;
	   	case 6:
			// printf("\n----GetElem功能待实现！\n");     
			printf("请输入要查询的元素的位置(%d-%d):\n",1,ListLength(L));
			scanf("%d",&position);
			flag =  GetElem(L,position,&data);

			printf("所查询的元素为:%d\n",data);
			getchar();getchar();
			break;
	   	case 7:
			printf("----LocateElem功能待实现！\n");     
			getchar();getchar();
			break;
	   	case 8:
			printf("请输入需要查询前驱节点的数据元素:\n");  
			scanf("%d",&cur_e);
			if(PriorElem(L,cur_e,&pre_e) == OK)printf("所查询数据元素的前驱节点为:%d",pre_e);
			else printf("所查找的元素不存在或不存在前驱节点");   
			getchar();getchar();
			break;
	   	case 9:
			printf("请输入需要查询前驱节点的数据元素:\n");  
			scanf("%d",&cur_e);
			if(PriorElem(L,cur_e,&next_e) == OK)printf("所查询数据元素的前驱节点为:%d",next_e);
			else printf("所查找的元素不存在或不存在前驱节点");        
			getchar();getchar();
			break;
	   	case 10:
			// printf("\n----ListInsert功能待实现！\n");
			printf("请输入要插入的位置:");
			scanf("%d",&position);
			printf("\n请输入要插入的数字(1,%d):",ListLength(L)+1);
			scanf("%d",&data);
			if(ListInsert(&L,position,data) == OK)printf("数据元素插入成功\n");
			else printf("数据元素插入失败");
			getchar();getchar();
			break;
	   	case 11:
			printf("\n----ListDelete功能待实现！\n");     
			getchar();getchar();
			break;
	   	case 12:
		 //printf("\n----ListTrabverse功能待实现！\n");     
		//  if(!ListTrabverse(L)) printf("线性表是空表！\n");                                           
			getchar();getchar();
			break;
	   	case 0:
         	break;
	}//end of switch
  }//end of while
  printf("欢迎下次再使用本系统！\n");
}

/* 
--------init a list--------
give the pointer of head node;
malloc a space of LNode;
judge if malloc is success;
the header should be: data = 0 && next pointer is NULL;
*/
Status InitaList(LinkList* L){
	// malloc a space of LNode;
    *L = (LinkList)malloc(sizeof(LNode));
	// judge if malloc is success;
    if((*L) == NULL)return OVERFLOW;
    (*L)->data = 0;
    (*L)->next = NULL;
    return OK;
}

Status DestoryList(LinkList *L){
    LinkList p;
    if((*L) == NULL)return OK;
    while(*L){
        p = (*L)->next;
        free((*L));
        (*L) = p;
    }
    return OK;
}

Status ClearList(LinkList *L){
    LinkList p;
    LinkList head = (*L);
    while(head->next){
        p = head->next;
        head->next = p->next;
        free(p);
    }
    return OK;
}


Status ListEmpty(LinkList L){
    if(L->next == NULL)return TRUE;
    return FALSE;
}

/* --------get list length--------
	init a new LinkLisk as cursor to iter;
	the length don't conclude the head pointer;
	so ListLength(InitaList(&L)) == 0;
*/
int ListLength(LinkList L){
	if(L==NULL)return INFEASTABLE;
    int i = 0;
    LinkList head = L;
	// iter;	if head->next == NULL; break out;
    while(head->next){
        i++;
        head = head->next;
    }
    return i;
}

Status GetElem(LinkList L,int i,ElemType *e){
    LinkList p = L;
    int iter = 0;

    if(i<=0 || i>ListLength(L)){
        printf("所查询的位置不存在\n");
        return ERROR;
    }

    while(p){
        if(iter == i){
            *e = p->data;
        }
        iter++;
        p = p->next;
    }
    return OK;
}

Status PriorElem(LinkList L,ElemType cur_e,ElemType* pre_e){
    LinkList p = L->next;
    while (p->next)
    {
        if(p->next->data == cur_e){
            *pre_e = p->data; 
            return OK;
        } 
        p = p->next;
    }
    return ERROR;
}

Status NextElem(LinkList L,ElemType cur_e,ElemType* next_e){
    LinkList p = L->next;
    while (p->next)
    {
        if(p->data == cur_e){
            *next_e = p->next->data; 
            return OK;
        } 
        p = p->next;
    }
    return ERROR;
}

/*
*/
Status ListInsert(LinkList* L,int i,ElemType data){
	int length = ListLength(*L);
	if(length == MAXSIZE){
		printf("链表已经达到最大长度，无法插入\n");
		return INFEASTABLE;
	}
	if(i > (length+1) || i<=0){
        printf("插入位置不存在\n");
        return INFEASTABLE;
    }
    int iter = 0;
    LinkList p = (LinkList)malloc(sizeof(LNode));
    if(p==NULL)return OVERFLOW;
    p->data = data;
    p->next = NULL;
    LinkList head = (*L);
    // initial a head pointer
    while(head->next){
        iter ++;
        if(iter == i){
			// use a temp *LNode to save head->next;
            LinkList temp = head->next;
            p->next = temp;
            break;
        }
        head = head->next;
    }
    head->next = p;
    return OK;
}

Status ListDelete(LinkList* L,int i,ElemType* e){
    LinkList p = (*L);
    int iter = 0;
    if(i<=0 && i >= ListLength(L))return ERROR;
    while(p && iter<i-1){
        p = p->next;
        iter ++;
    }
    LinkList temp = p->next;
    (*e) = temp->data;
    p->next = temp->next;
    free(temp);
    return OK;
}