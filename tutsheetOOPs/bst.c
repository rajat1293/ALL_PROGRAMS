#include<stdio.h>
#include<stdlib.h>
int i=1,j=0,l=0;
struct node
{
  int key_value;
  struct node *left;
  struct node *right;
};
struct node *leaf = 0,*p;
void destroy_tree(struct node *leaf)
{
  if( leaf != 0 )
  {
      destroy_tree(leaf->left);
      destroy_tree(leaf->right);
      free( leaf );
  }
}
 void insert(int key, struct node **leaf)
{
    if( *leaf == 0 )
    {
        *leaf = (struct node*) malloc( sizeof( struct node ) );
        if(i==1) 
	 p = *leaf;
        (*leaf)->key_value = key;
        i++;
        /* initialize the children to null */
        (*leaf)->left = 0;    
        (*leaf)->right = 0;  
    }
    else if(key < (*leaf)->key_value)
    {
        insert( key, &(*leaf)->left );
    }
    else if(key > (*leaf)->key_value)
    {
        insert( key, &(*leaf)->right );
    }
}

struct node *search(int key, struct node *leaf)
{
  if( leaf != 0 )
  {
      if(key==leaf->key_value)
      {
          return leaf;
      }
      else if(key<leaf->key_value)
      {
          return search(key, leaf->left);
      }
      else
      {
          return search(key, leaf->right);
      }
  }
  else return 0;
}
inorder(struct node *root)
{if(root)
{
  inorder(root->left);
	printf("%d",root->key_value);
	inorder(root->right);
	
}}
height(struct node*p)
{

	
	if(p)
	{
		height(p->left);
		j++;
	}

	}
	height1(struct node*p)
{

	
	if(p)
	{
		l++;
		height1(p->right);
		
	}

	}
	
	
main()
{
//	struct node *leaf=root;
//	leaf=(struct node*)malloc(sizeof(struct node));
 insert(5,&leaf);
insert(6,&leaf);
insert(7,&leaf);
insert(8,&leaf);
inorder(leaf);
height(p);
height1(p);
printf("......%d",p->key_value);
if(j>l)
	printf("\n%d",j);	
	else
	printf("\n%d",l);
}
	
	
	
	
	


	




