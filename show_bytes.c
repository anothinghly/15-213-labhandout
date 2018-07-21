#include<stdio.h>
#include<stdlib.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start,size_t len)
{
	size_t i;
	for(i=0;i<len;i++)
	{
		printf(" %.2x",start[i]);
	}
	printf("\n");
}


void show_int(int val)
{
	show_bytes((byte_pointer) &val,sizeof(int));
}
void show_short(short val)
{
	show_bytes((byte_pointer) &val,sizeof(short));
}
void show_float(float val)
{
	show_bytes((byte_pointer) &val,sizeof(float));
}
void show_pointer(void *val)
{
	show_bytes((byte_pointer) &val,sizeof(void *));
}

void test_show_bytes(int val)
{
	int ival=val;
	float fval=val;
	int *pval=&ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}

int main(int argc,char **argv)
{
	
	int val=0x12345678;
	if(argc==2)
		val=atoi(argv[1]);
	else
		val=0x12345678;
	show_short((short) val);
	test_show_bytes(val);
	printf("show_bytes():\n");
	char a[]="abcdef";
	show_bytes((unsigned char*)a,6);

	
	return 0;
}

