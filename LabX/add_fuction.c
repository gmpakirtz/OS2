#include <stdio.h>

void add(int *a, int *b, int *c) {
	*a = *a + *b + *c;
}

int main() {
	int x = 5, y = 10, z = 15;
	add(&x, &y, &z);
	printf("the sum is: %d\n", x);
	return 0;
}
