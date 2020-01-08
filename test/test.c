#include <evatest/test.h>
#include <stdlib.h>
#include <time.h>

int main() {
	INIT_TEST;
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
#ifdef SHOULD_WORK
		TEST(1 == 1);
#else
		TEST(rand() % 100 == rand() % 100);
#endif
	}
	END_TEST;
}
