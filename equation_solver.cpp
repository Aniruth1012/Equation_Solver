#include <iostream>
using namespace std;

int n;

void display(int copymatrix[10][10][10],int w)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",copymatrix[w][i][j]);
        }
        cout<<endl;
    }
}

int determinant(int cc,int count,int copymatrix[10][10][10],int sum,int a)
{
    if(count==1)
    {
        int a=copymatrix[cc--][0][0];
        return copymatrix[cc--][0][0];
    }
    else
    {
        sum=0;
        for(int i=0;i<count;i++)
        {
            int m=0;
            int nn=0;
            //printf("hi");
            for(int p=1;p<count;p++)
            {
                for(int q=0;q<count;q++)
                {
                    if(q!=i)
                    {
                        copymatrix[cc][m][nn]=copymatrix[cc-1][p][q];
                        nn++;
                    }
                }
                m++;
                nn=0;
            }
            //display(copymatrix,cc);
            a++;
            //printf("\n%d\n",count);
            int r=determinant(cc+1,count-1,copymatrix,sum,a);
            //printf("\nr %d\n",r);
            int pdt=r*copymatrix[cc-1][0][i];
            //printf(" product %d ",pdt);
            if(i%2==0)
            {
                sum+=pdt;
            }
            else
            {
                sum-=pdt;
            }
            //printf(" sum %d ",sum);
        }
        return sum;
    }
}

void adjoint(int copymatrix[10][10][10],int dd,int matrix[10][10],int copymatrix2[10][10][10])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int pp=0,qq=0;
            for(int ii=0;ii<n;ii++)
            {
                if(ii!=i)
                {
                    for(int jj=0;jj<n;jj++)
                    {
                        if(jj!=j)
                        {
                            copymatrix2[0][pp][qq]=copymatrix[0][ii][jj];
                            qq++;
                        }
                    }
                    pp++;
                    qq=0;
                }
            }
            int sun=0,aa=0;
            //display(copymatrix2,0);
            int cofactor=determinant(1,n-1,copymatrix2,sun,aa);
            if((i+j)%2==0)
            {
                matrix[j][i]=cofactor;
            }
            else
            {
                matrix[j][i]=-cofactor;
            }
        }
    }
}

void multiplication(int matrix[10][10],int B[10],int answer)
{
    char variables[]={'x','y','z','t','u','v','w'};
    int SOL[n];
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            int pdt=matrix[i][j]*B[j];
            sum+=pdt;
        }
        SOL[i]=sum;
    }
    for(int i=0;i<n;i++)
    {
        if(SOL[i]%answer!=0)
        {
            printf("%c = %d/%d",variables[i],SOL[i],answer);
        }
        else
        {
            printf("%c = %d",variables[i],SOL[i]/answer);
        }
        cout<<endl;
    }
}

int main()
{
    printf("Enter the size of matrix : ");
    scanf("%d",&n);
    int count=n;
    int sum=0;
    int c=1;
    int a=1;
    int copymatrix[n][10][10];
    int copymatrix2[10][10][10];
    int matrix[10][10];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    int B[n];
    printf("\nEnter the B matrix\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&B[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            copymatrix[0][i][j]=matrix[i][j];
        }
    }
    //display(copymatrix,0);
    int ans=determinant(c,count,copymatrix,sum,a);
    printf("%d\n",ans);
    adjoint(copymatrix,1,matrix,copymatrix2);
    multiplication(matrix,B,ans);
    return 0;
}
