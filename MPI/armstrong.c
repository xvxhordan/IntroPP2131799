#include <stdio.h>

void main(){

	int num,temp,r,sum;
	int stno,enno;

	printf("Input start number of range: ");
    scanf("%d",&stno);
    printf("Input ending number of range : ");
    scanf("%d",&enno);

    printf("Armstrong numbers in given range are: ");

    for(num=stno;num<=enno;num++){
    	temp = num;
    	sum = 0;
    	for(temp = num; temp != 0; temp = temp/10){
    		r=temp % 10;
    		sum=sum+(r*r*r);
    	}
    	if(sum==num){
    		printf("%d ", num);
		}
	}
 	printf("\n");
 }
