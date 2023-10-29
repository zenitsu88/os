#include<stdio.h>
#include<stdlib.h>
void fifo(int p[],int size,int frame)
{
int i,j,k,m,fault=0,large=99,flag;
int number=1,a[frame+1][size],arr[10],no[10];
for(i=0;i<frame;i++)
arr[i]=-1;
for(i=0;i<size;i++)
a[frame][i]=-1;
for(i=0;i<frame;i++)
{
arr[i]=p[i];
no[i]=number++;
fault++;
a[frame][i]=fault;
for(m=0;m<frame;m++)
a[m][i]=arr[m];
}
if(size==frame)
{
printf("\nPAGE FAULT : %d",fault);
return;
}
for(;i<size;i++)
{
flag=0;
for(j=0;j<frame;j++)
if(p[i]==arr[j])
{
flag=1;
break;
}
if(flag==1)
{
for(m=0;m<frame;m++)
a[m][i]=arr[m];
continue;
}
large=99;
for(j=0;j<frame;j++)
if(large>no[j])
{
large=no[j];
k=j;
}
arr[k]=p[i];
no[k]=number++;
fault++;
a[frame][i]=fault;
for(m=0;m<frame;m++)
a[m][i]=arr[m];
}
for(i=0;i<size;i++)
printf("%d",p[i]);
printf("\n\n");
for(i=0;i<frame;i++)
{
for(j=0;j<size;j++)
if(a[i][j]==-1)
printf("|-| ");
else
printf("|%d|",a[i][j]);
printf("\n");
}
printf("\n");
for(i=0;i<size;i++)
if(a[frame][i]!=a[frame][i-1] && a[frame][i]!=-1)
if(a[frame][i]>9)
printf("%d",a[frame][i]);
else
printf("%d",a[frame][i]);
else
printf(" -  ");		
printf("\nPAGE FAULTS : %d\n",fault);
}
void lru(int p[],int size,int frame)
{
int i,j,k,m,n,fault=0,no[10],large,flag,temp;
int a[30][30],arr[10];
for(i=0;i<frame;i++)
arr[i]=-1;
for(i=0;i<size;i++)
a[frame][i]=-1;
for(i=0;i<frame;i++)
{
arr[i]=p[i];
fault++;
a[frame][i]=fault;
for(m=0;m<frame;m++)
a[m][i]=arr[m];
}
if(size==frame)
{
printf("\nPAGE FAULT : %d",fault);
return;
}
for(;i<size;i++)
{
flag=0;
for(j=0;j<frame;j++)
if(p[i]==arr[j])
{
flag=1;
break;
}
if(flag==1)
{
temp=arr[0];
for(m=0;m<frame-1;m++)
arr[m]=arr[m+1];
arr[m]=temp;
for(m=0;m<frame;m++)
a[m][i]=arr[m];
continue;
}
for(n=0;n<frame;n++)
{
for(j=i-1;j>=0;j--)
if(p[j]==arr[n])
{
no[n]=j;
break;
}
if(j<0)
no[n]=-99;
}
large=999;
for(j=0;j<frame;j++)
if(large>no[j])
{
large=no[j];
k=j;
}
arr[k]=p[i];
fault++;
a[frame][i]=fault;
temp=arr[0];
for(m=0;m<frame-1;m++)
arr[m]=arr[m+1];
arr[m]=temp;
for(m=0;m<frame;m++)
a[m][i]=arr[m];
}
for(i=0;i<size;i++)
printf(" %d  ",p[i]);
printf("\n\n");
for(i=frame-1;i>=0;i--)
{
for(j=0;j<size;j++)
if(a[i][j]==-1)
printf("|-| ");
else
printf("|%d|",a[i][j]);
printf("\n");
}
printf("\n");
for(i=0;i<size;i++)
if(a[frame][i]!=a[frame][i-1] && a[frame][i]!=-1)
if(a[frame][i]>9)
printf("%d",a[frame][i]);
else
printf("%d ",a[frame][i]);
else
printf(" -  ");		
printf("\nPAGE FAULTS : %d\n",fault);
}
void optimal(int p[],int size,int frame)
{
int i,j,k,m,n,fault=0,small,flag,nn=99;
int a[30][30],arr[10],no[10];
for(i=0;i<frame;i++)
arr[i]=-1;
for(i=0;i<size;i++)
a[frame][i]=-1;
for(i=0;i<frame;i++)
{
arr[i]=p[i];
fault++;
a[frame][i]=fault;
for(m=0;m<frame;m++)
a[m][i]=arr[m];
}
if(size==frame)
{
printf("\nPAGE FAULT : %d",fault);
return;
}
for(;i<size;i++)
{
flag=0;
for(j=0;j<frame;j++)
if(p[i]==arr[j])
{
flag=1;
break;
}
if(flag==1)
{
for(m=0;m<frame;m++)
a[m][i]=arr[m];
continue;
}
for(n=0;n<frame;n++)
{
for(j=i+1;j<size;j++)
if(p[j]==arr[n])
{
no[n]=j;
break;
}
if(j==size)
no[n]=99;
}
small=-999;
for(j=0;j<frame;j++)
if(small<no[j])
{
small=no[j];
k=j;
}
arr[k]=p[i];
fault++;
a[frame][i]=fault;
for(m=0;m<frame;m++)
a[m][i]=arr[m];
}
for(i=0;i<size;i++)
printf(" %d  ",p[i]);
printf("\n\n");
for(i=0;i<frame;i++)
{
for(j=0;j<size;j++)
if(a[i][j]==-1)
printf("|-| ");
else
printf("|%d| ",a[i][j]);
printf("\n");
}
printf("\n");
for(i=0;i<size;i++)
if(a[frame][i]!=a[frame][i-1] && a[frame][i]!=-1)
if(a[frame][i]>9)
printf(" %d ",a[frame][i]);
else
printf(" %d  ",a[frame][i]);
else
printf(" -  ");		
printf("\nPAGE FAULTS: %d\n",fault);
}
int main()
{
int i,op,p[50],size,frame;
printf("\nEnter total no. of pages : ");
scanf("%d",&size);
printf("\nEnter sequence of pages : \n");
for(i=0;i<size;i++)
scanf("%d",&p[i]);
printf("\nEnter size of buffer : ");
scanf("%d",&frame);
do
{
printf("\nMAIN MENU(Page replacement algo.)");
printf("\nEnter the choice of operation");		
printf("\n1.FIFO\n2.LRU\n3.Optimal");
printf("\n0.Exit\nEnter : ");
scanf("%d",&op);
switch(op)
{
case 1:	fifo(p,size,frame);break;
case 2:	lru(p,size,frame);break;
case 3:	optimal(p,size,frame);break;
case 0:	exit(0);
default:printf("\nINVALID INPUT");
}
}
while(op);
return 0;
}
