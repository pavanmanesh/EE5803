#include<stdio.h>
#include<stdbool.h>
bool NAND(bool a, bool b)
{
   return !(a&&b);
}
int main()
{
bool a=false,b,c,lhs,rhs,nand;
int i,j,k;
printf("A B C LHS RHS NAND\n");
for(i=0;i<=1;i++)
{
    b=false;
    for(j=0;j<=1;j++)
    {
        c=false;
        for(k=0;k<=1;k++)
        {
            lhs=(!a)||(!b&&c);
            rhs=(!a&&!b&&!c)+(!a&&b&&!c)+(!a&&b&&c)+(!a&&!b&&c)+(a&&!b&&c);
            nand=NAND(NAND(!b,c),a);
            printf("%d %d %d  %d   %d   %d\n",a,b,c,lhs,rhs,nand);
            c=true;
        }
        b=true;
    }
    a=true;
}
return 0;
}
