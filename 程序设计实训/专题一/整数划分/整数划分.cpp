#include <iostream>

using namespace std;

int mark[100];//��¼�ֽ����
int n;
void divide(int nowNumber, int k, int preNumber);//���ֺ������� 

int main()
{
	cin>>n;
	divide(0, 0, n-1);

	return 0;
}

//now������¼��ǰֵ�жϵ�ǰ��С��n�Ĺ�ϵ��k��¼�ݹ������ pre��¼ǰһ��ֵ
void divide(int nowNumber, int k, int preNumber)
{
    int i;
//��ǰֵ����n�ͷ��أ��ݹ���� 
    if(nowNumber > n)
    {
         return;
    }
//��ǰֵ��n��ȣ��ݹ���������յݹ����i��������ֽ�� 
    if (nowNumber == n)
    {
        cout<<n<<"=";
        for(i = 0; i < k - 1; i++)
		{
        	cout<<mark[i]<<"+";
        }
        	cout<<mark[i]<<endl;
    }
    
     else//(nowNumber < n)
    {
        for(i = preNumber; i > 0;)//��nΪ6Ϊ����i=5
        { 
                mark[k] = i; 
				// mark[0]=5 //mark[1]=4 break; //mark[1]=3 break.....
				
                nowNumber += i;
				// now=5 //now=4 //now=3
				
                divide(nowNumber, k + 1, i); 
				// (5,1,5)>>> k=1 >>>now=10>n break // (4,2,4)>>> k=2 >>> now=8>n break //
				
                nowNumber -= i;// now=0 // now=0
                
            	i--;//i=4 //i=3 //
        }
    }
}
