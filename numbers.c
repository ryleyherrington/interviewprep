#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int factorial(int n) {
    if(n!=1){
		return n*factorial(n-1);
	}
	return 1;
}

//given that it's -2^31 --> 2^31 - 1
int solution(int a, int b) {	
	//ex: [4..17] returns 3. 4,9, and 16.
	if (a <= b) {
		a = (a < 0) ? 0 : a; //if a is negative, make it zero

		//so all of the integers between the squareroots of our values will have 
		//a square within the given range. So floor of the upper, ceil of the lower
		return floor(sqrt(abs(b))) - ceil(sqrt(abs(a))) + 1;
	} else {
		return 0;
	}
}

/* itoa:  convert n to characters in s */
 void itoa(int n, char s[])
 {
     int i, sign;
 
     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
 }
 
void swap(char *x, char *y) {
	//classic swap algorithm
    char tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
 
void permute(char *a, int l, int r) {
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtracking
       }
   }
}
 
//Find similar numbers -- if their decimal representations can be obtained from eachother by rearranging the digits
//N is an integer within range[0..99,999] 
int solution2(int n){
	//ex: n=1213 --> returns 12. 1123, 1132, 1213, 1231, 1312, 1321, 2113, 2131, 2311, 3112, 3121 and 3211.	
	if (n<0) 
		return 0;
	int nDigits = floor(log10(abs(n))) + 1;
	printf("ndigits:%d\n",nDigits);

	if (nDigits == 1)
		return 1;

	char snum[nDigits];
	snprintf(snum, sizeof(snum), "%d", n);
	
	itoa (n ,snum);
	printf ("decimal: %s\n", snum);

    int x = strlen(snum);
    permute(snum, 0, x-1);

	return n;
}
 
int main(int argc, char* argv[])
{
	int p, n, c;

	printf("Enter a problem number\n");
	scanf("%d", &p);
	if (p == 1) { 
		printf("Enter a number\n");
		scanf("%d", &n);
	
		printf("Enter a larger number\n");
		scanf("%d", &c);
		printf("\n=========================\nSolution:%d\n==========================\n",solution(n,c));
	}else if (p==2) {
		printf("Enter a number\n");
		scanf("%d", &n);
		
		printf("\n=========================\nSolution:%d\n==========================\n",solution2(n));
	} else if (p==3){
		printf("Enter a radius\n");
		int r;
		scanf("%d", &r);
		int sum = 0;
		for(int i = 0; i <= (r*r)/4; i++){
			  sum += ((r*r)/((4*i)+1)) - ((r*r)/((4*i)+3));
		}
		sum = sum * 4 + 1;

		printf("\n=========================\nNumber of ints::%d\n==========================\n",sum);


	}


	return 0;
}
