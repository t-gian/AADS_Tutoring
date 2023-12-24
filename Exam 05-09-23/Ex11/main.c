
#include <stdio.h>
#include <string.h>
int max(int a, int b);
int common_substring(char* str1, char* str2);
int lcs(char * str1, char *str2, int n, int m,int count, int *start);

int main()
{
	char str1[] = "123ABCD34EFG";
	char str2[] = "XXXABCE124YABCD";
	printf("Lenght of LCS is %d\n", common_substring(str1,str2));
}
int common_substring(char* str1, char* str2)
{
	int start = 0;
    int count = lcs(str1, str2,strlen(str1), strlen(str2),0, &start);
    printf("LCS is: ");
    for (int i=start; i<start+count; i++){
        printf("%c",str1[i]);
    }
    printf("\n");
    return count;
}
int lcs(char* str1, char* str2, int n, int m,int count, int *start)
{
    if (n == 0 || m == 0)
        return count;
    if (str1[n-1] == str2[m-1]){
        count = lcs(str1, str2, n-1, m-1,count+1,start);
        *start = n-1;
    }
    count = max(count, max(lcs(str1, str2, n,m-1,0,start),lcs(str1, str2,n-1,m,0,start)));
    return count;
}
int max(int a, int b) { return (a > b) ? a : b; }

