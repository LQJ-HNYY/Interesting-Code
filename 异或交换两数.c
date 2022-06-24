#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int i = 3,
		j = 4;
	
	swap(&i, &j);
	
	printf("交换前：i=3, j=4\r\n交换后：i=%d, j=%d", i, j);
	
	return 0;
	
}


/*
利用异或具有交换律和结合律的性质 
*/
void swap(int* a, int* b)
{
	/*不能指向同一地址*/
	if(a == b)
	{
		/*指向同一地址，其内存空间的值必定相同，则不需要进行交换*/
		return ;
	}
		
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
} 
