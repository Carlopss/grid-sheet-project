#include<stdio.h>
#include<string.h>

int main()
{int l,n,j,h,k,max=0,len,side,m,p,rh,rv,sh,sv;
 char name[10][6],z[5],a[4],b[6],board[l][l][51];
 int x[10],y[10];
 
  for(j=0;j<l;j++)//emptying board
 {for(k=0;k<l;k++)
  board[j][k][0]='\0';}//emptying board
  
 scanf("%s%d%d",z,&l,&n);//init
 while(strcmp(z,"init")!=0 || n>10 )
 {printf("error\n");
  scanf("%s%d%d",z,&l,&n);}//init
 
 
 for(j=0;j<n;j++)//input of data
 {scanf("%s %d %d",&name[j],&x[j],&y[j]);
  while(x[j]<0||y[j]<0 || strlen(name[j])>5)
  {printf("error\n"); 
   j--;}}//input of data
    
 scanf("%s",a);
 while(strcmp(a,"add")==0||strcmp(a,"rm")==0||strcmp(a,"mov")==0||strcmp(a,"vis")==0)
 { if(strcmp(a,"add")==0)// add
  {if(n==10)
   printf("you have reached the maximum allowed number\n");
   else 
   {scanf("%s %d %d",&name[n],&x[n],&y[n]);
    n++;}}//add
  
  else if(strcmp(a,"rm")==0)//remove
  {scanf("%s",b);
   for(h=0;h<n;h++)
  {if(strcmp(name[h],b)==0)
  {for(k=h;k<n;k++)
    name[k][5]=name[k+1][5];
    x[k]=x[k+1];
    y[k]=y[k+1];}
	n--;}}//remove
  
  else if(strcmp(a,"mov")==0)//move
  {scanf("%s %d %d %d %d",b,&rh,&sh,&rv,&sv);
   while((rh!=1&&rh!=-1&&rh!=0)||(rv!=1&&rv!=-1&&rv!=0))
  {printf("error\n");
  scanf("%s %d %d %d %d",b,&rh,&sh,&rv,&sv);}
   for(h=0;h<n;h++)
  {if(strcmp(name[h],b)==0)
  {switch(rh)
  {case 1:if(x[h]+sh<l)
   x[h]+=sh;
   else 
   x[h]=(2*l)-x[h]-sh-1;
   break;
   case -1:if(x[h]-sh>=0)
   x[h]-=sh;
   else
   x[h]=(2*l)-x[h]-sh-1;
   break;
   case 0:x[h]+=0;break;}
   
   switch(rv)
  {case -1:if(y[h]+sv<l)
   y[h]+=sv;
   else 
   y[h]=(2*l)-y[h]-sv-1;
   break;
   case 1:if(y[h]-sv>=0)
   y[h]-=sv;
   else
   y[h]=(2*l)-y[h]-sv-1;
   break;
   case 0:y[h]+=0;break;}
   }}}//move
  
  else if(strcmp(a,"vis")==0)
  {for(j=0;j<l;j++)//adding to board
  {for(k=0;k<l;k++)
  {for(h=0;h<n;h++)
  {if(x[h]==k&&y[h]==j)
  strcat(board[k][j],name[h]);
  }}}//adding to board
  
  for(j=0;j<l;j++)//finding max length
 {for(k=0;k<l;k++)
 {len=strlen(board[k][j]);
  if(len>max)
  max=len;}}//finding max length
  
  for(j=0;j<l;j++)//spaces
 {for(k=0;k<l;k++)
 {if(strcmp(board[k][j],"\0")==0)
  strcat(board[k][j]," ");}}//spaces
  j=0;
  while(j*j<max)
  {j++;}
  side=j;//finding side of small squares
  
  if(l>10)//number's row
  printf(" ");
  printf("  ");
  for(k=0;k<l;k++)
  {printf("%d",k);
  for(h=0;h<side;h++)
  {if(l>10)
  {if(k<10)printf("  ");
  else printf(" ");}
  else printf(" ");}}//number's row
  printf("\n ");
  
  if(l>10)//print top row
  {printf(" -");
  for(k=0;k<l;k++)
  {for(h=0;h<side;h++)printf("--");}  
  printf("\n");}
  else{for(k=0;k<l;k++)
  {for(h=0;h<side;h++)printf("--");}}  
  printf("-\n");//print top row
  
  for(m=0;m<l-1;m++) //left column
  {printf("%d",m);
  if(l>10 && m<10)
  printf(" ");
  for(j=0;j<l;j++)//the inside column
  {printf("|%s",board[m][j]);
  if(strlen(board[m][j])<side)
  {for(p=0;p<side-strlen(board[m][j]);p++)
   printf(" ");}
  if(l>10)
  printf(" ");} 
  printf("|\n ");
  
  if(l>10)//print inside row
  {printf(" -");
  for(k=0;k<l;k++)
  {for(h=0;h<side;h++)printf("--");}  
  printf("\n");}
  else{for(k=0;k<l;k++)
  {for(h=0;h<side;h++)printf("--");}}  
  printf("-\n");}//print inside row
  
  printf("%d",m);
  for(j=0;j<l;j++)//last column
  {printf("| ");
  if(strlen(board[m][j])<side)
  {for(p=0;p<side-strlen(board[m][j]);p++)
   printf(" ");}
  if(l>10)
  printf(" ");} 
  printf("|\n ");//last column
  
  if(l>10)//print last row
  {printf(" -");
  for(k=0;k<l;k++)
  {for(h=0;h<side;h++)printf("--");}  
  printf("\n");}
  else{for(k=0;k<l;k++)
  {for(h=0;h<side;h++)printf("--");}}  
  printf("-\n");//print last row
  }//end of vis
  
  scanf("%s",a);
 }//end of while loop
 
 
 
}
