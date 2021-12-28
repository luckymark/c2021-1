#include <stdio.h>

int main()
 {	int n;
 	scanf("%d",&n);
	char a[n];
	int i=0;
	for(;i<n;i++){
		scanf("%s",&a[i]);
	}
	printf("\n");
	i=0;
	for (;i<n;i++){ 
		a[i]-=1;
	}
	printf("%s",a);
	 
}


