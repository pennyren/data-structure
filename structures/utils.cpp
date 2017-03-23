#define arr_length(a) (sizeof(a) / sizeof(a[0]))

int toNumber(char a[]) {
	int sign, offset, num = 0;

 	sign = (a[0] == '-') ? -1 : 1;
  	offset = (sign == -1) ? 1 : 0;

 	while (a[offset] != '\0') {
 		num = num * 10 + a[c] - '0';
 		offset++;
 	}

 	return sign == 1 ? num : -num;
}

char *strSplit(char *c, char delimiter) {

}