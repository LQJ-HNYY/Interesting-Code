#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int i = 3,
		j = 4;
	
	swap(&i, &j);
	
	printf("����ǰ��i=3, j=4\r\n������i=%d, j=%d", i, j);
	
	return 0;
	
}


/*
���������н����ɺͽ���ɵ����� 
*/
void swap(int* a, int* b)
{
	/*����ָ��ͬһ��ַ*/
	if(a == b)
	{
		/*ָ��ͬһ��ַ�����ڴ�ռ��ֵ�ض���ͬ������Ҫ���н���*/
		return ;
	}
		
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
} 
