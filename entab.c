#include<stdio.h>
#define TABSIZE 8
main()
{
	int pos=0;
	int nt=0;
	int nb=0;
	int c;
	for(pos=1;(c=getchar())!=0;++pos)//逐个检查字符
		if(c==' ')						//如果是空格
		{
			if(pos%TABSIZE!=0) //如果该位置除TABSIZE有余，说明需要一个空格
				++nb;
			else  //如果该位置除TABSIZE可以整除，则此时正在制表符终止位上。
			{
				nb=0;//不用空格
				++nt;//用制表符替代
			}
		}
		else  //遇到非空格字符
		{
			while(nt>0) //先将之前的制表符打印
			{	
				--nt;
				putchar('\t');
			}
			if(c=='\t') //如果遇到制表符
				nb=0;   //则忘记所有之前的所需空格数
			else
				while(nb>0)  //如果遇到的不是制表符（即不是空格也不是制表）
				{
					--nb;
					putchar(' ');//打印所需空格
				}
			putchar(c);//将该非空格字符打印
			if(c=='\n')		//如果遇到换行符，把pos至0
				pos=0;
			else if(c=='\t')
				pos=pos+(TABSIZE-(pos-1)%TABSIZE)-1;//？
		}
}