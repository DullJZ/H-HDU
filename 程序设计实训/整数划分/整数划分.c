#include <stdio.h>
int d[];//ȫ�ֱ�����������ŷֽ��� 
void decompose(int m,int n,int k, int j);
//ȫ�ֺ�������ֽ����ã���m�ֽ�Ϊ������n���������k>=0 
int main()
{
	int j,n;
	printf("����������n\n");
	scanf("%d",&n);
	j=n;//��n��ֵ��j��ʹj���ڳ�ֵ 
    decompose(n,n,0,j);
	return 0;
}
void decompose(int m,int n,int k,int j)
{
	int i;
	if(m==0)
	{
		printf("%d=",j);
		printf("%d",d[0]);//���"n=" 
		for(i=1;i<k;i++)//���������ʽ 
		printf("+%d",d[i]);
		printf("\n");
	}
	for(i=m<n?m:n;i>0;i--)//һ�ηֽ�ļ��ֿ��ַܷ� 
	{
		if(i<n)
		d[k]=i;
		else
		d[k]=n;
		decompose(m-d[k],d[k],k+1,j);//�����ֽ⣬ֱ���õ�һ������ 
	}		
}   
