int x = 1, y = 2,z[10];
int *ip;

ip = &x;
y = *ip;
*ip = 0;
ip = &[0];



void swap(int *px,int *py)
{
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}