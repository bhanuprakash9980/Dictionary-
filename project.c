#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long int c1=0; //to count total words in the dictionary

typedef struct node
{
    char info[1000];
    struct node *left,*right;
}tree_type; 
void insert(tree_type **,char str[]); //function to insert nodes to the bst
void search(tree_type*,char []); //function to search node in the bst
long int display(tree_type*); //function for inorder traversal  of bst
void write1(); //function for adding new word-meaning to the dictionary



int main()
{     
      tree_type *root=NULL;
      FILE *fp;
      int i=0,ch;
      long int cou;
      char str[20],c;


      fp=fopen("words.txt","r");//words.txt is the file containing words and their meanings
      while((c=getc(fp))!=EOF)
      {
        if(c=='\n')
            {
                str[i]='\0';
                insert(&root,str); // inserting each line as a string to the tree
                i=0;
            }
        else
        {
            str[i]=c;
            i++;
        }
    }
    fclose(fp);

do{
               printf("\n1.search for meaning\n2.Exit\n3.view words in the dictionary\n4.Add word to dictionary\nChoice : ");
               scanf("%d",&ch);
               switch(ch)
               {
               
               
                    case 1: printf("Enter the field to be searched: ");
                    scanf("%s",str);
                    search(root,str);
                    break;
                    case 2: exit(0);
	            case 3: cou=display(root);
			    printf("\nnumber of nodes %ld",cou);
			    c1=0;
                            break;
	           case 4:write1();
			  break;
                   default:
                    printf("Enter the correct choice: ");
               }
          }while(ch!=2);
return 0;}
void insert(tree_type **rt,char str[100])
{
     tree_type *p;
     p=(tree_type*)malloc(sizeof(tree_type));
     if(p!=NULL)
     {
          strcpy(p->info,str);

          if(*rt==NULL)
               *rt=p;
          else
          {
   if(strcmp(str,((*rt)->info))<0)//if given string has size less than  root string traverse left subtree
                      insert(&((*rt)->left),str);
                else
                      insert(&((*rt)->right),str); //traverse right subtree for insertion
          }
     }
}
long int display(tree_type *rt) //inorder traversal of bst the words are in alphabetical order 
{
    
    if(rt==NULL)
    {   
	
	return c1;
    }
    else
    {
        display(rt->left);
        for(int i=0;rt->info[i]!='\0';i++)
        printf("%c",rt->info[i]);
        printf("\n");
        c1++;
        display(rt->right);
    }
}
void search(tree_type *rt,char str[20])
{char str1[20];
 int i;
 
      if(rt==NULL)
      {
          printf("NOT FOUND");
          return;
      }
      for( i=0;rt->info[i]!='-';i++)
	      str1[i]=rt->info[i];
      str1[i]='\0';

      if(strcmp(str,str1)==0)
      {
          printf("FOUND\n");
	  printf("%s",rt->info);
          return;
      }
	   else
      {
           if(strcmp(str,rt->info)<0)
                 search(rt->left,str);
           else
                 search(rt->right,str);
      }
}
void write1()
{FILE *fp;
 char str[100];


 printf("\n enter [word]-[meaning]");
gets(str);
fp=fopen("words.txt","a"); //append the word to the file
fflush(stdin);          // To clear extra white space characters in stdin
fgets(str, 100, stdin);
 fputs(str, fp);
 }

