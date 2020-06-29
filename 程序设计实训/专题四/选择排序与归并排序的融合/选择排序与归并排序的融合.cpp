#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void Merge (int array[], int arr1[], int n1, int arr2[], int n2);

void SortIntegerArray (int array[], int n)
{
    int i, j, index, n1, n2, temp, *arr1, *arr2;
    //�鲢����ʱ�临�Ӷ�O(N*lgN)  ѡ�������ʱ�临�Ӷ�ΪO(N^2)  �ٽ�ֵ��100~1000֮��

    if (n > 100)
	{
    	if (n > 1)
		{
         n1= n/2;
         n2= n-n1;
         arr1 = new int[n1];
         arr2 = new int[n2];
         for (i = 0; i < n1; i++) arr1[i] = array[i];
         for (i = 0; i < n2; i++) arr2[i] = array[n1 + i];
         SortIntegerArray (arr1, n1);
         SortIntegerArray (arr2, n2);
         Merge (array, arr1, n1, arr2, n2);
         delete arr1;
         delete arr2;
    	}
	}

	if(n < 100)
	{
		int i, index, k, temp;
    	for(k=0; k<n-1; k++)
		{
            index=k;
            for(i=k+1; i<n; i++)
                if(array[i]< array[index])  index=i;
            temp=array[index];   array[index]=array[k];    array[k]=temp;
    	}
	}

}

void Merge (int array[], int arr1[], int n1, int arr2[], int n2)
{
     int p, p1, p2;
     p = p1 = p2 = 0;
     while (p1 < n1 && p2 < n2) {
           if (arr1[p1] < arr2[p2])
                 array[p++] = arr1[p1++];
           else
                 array[p++] = arr2[p2++];
    }
    while (p1 < n1) array[p++] = arr1[p1++];
    while (p2 < n2) array[p++] = arr2[p2++];
}

int main()
{
	ifstream inf("C:\\Users\����\Desktop\da.txt");		//�������ݱ�����c:\da.txt�ļ���
	int depth=0;
	int data[10000];           //���ڱ����ȡ���������ֵ�����
	int i=0;
	while (inf>>data[depth])        //��inf�ļ��е����ֶ�ȡ��data������
 	++depth;
	inf.close();               //��ȡ��Ϻ�,�ر��ļ�

	double start, finish;
	start = (double)clock();

	for(i=0; i<depth; i++)
	{
		cout<<data[i]<<" ";
	}
	SortIntegerArray(data,depth);
		cout<<endl;
	for(i=0; i<depth; i++)
	{
		cout<<data[i]<<" ";
	}
	finish = (double)clock();
	cout<<endl;
	double time=finish-start;
	cout<<"��������ʱ��Ϊ:"<<time<<endl;
}

