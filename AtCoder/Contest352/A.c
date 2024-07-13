// https://atcoder.jp/contests/abc352/tasks/abc352_a
// AtCoder Line

#include <stdio.h>

int main(){
	
	short int  X,Y,Z;
	
	scanf("%hd%hd%hd%hd", &X,&X,&Y,&Z);
	
	printf("%s\n",((X<Z && Z<Y)||(X>Z && Z>Y))?"Yes":"No");
		
	return 0;
}
