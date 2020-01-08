#ifndef _H_TEST
#define _H_TEST
#include <stdio.h>

#define GREEN "\x1b[1;32m"
#define RED "\x1b[1;31m"
#define NOCOLOR "\x1b[0m"

#ifndef TEST_MAX
#define TEST_MAX 1000
#endif

#define INIT_TEST                                                              \
	size_t err = 0, test = 0;                                                  \
	size_t errs[TEST_MAX]

#if EVATEST_TAP

#define END_TEST                                                               \
	do {                                                                       \
		printf("1..%u\n", test);                                               \
	} while (0)

#define TEST(c)                                                                \
	do {                                                                       \
		test++;                                                                \
		if (!(c)) {                                                            \
			printf("not ");                                                    \
			errs[err] = test;                                                  \
			err++;                                                             \
		}                                                                      \
		printf("ok %u - %s:%d: %s\n", test, __FILE__, __LINE__, #c);           \
	} while (0)

#else

#define END_TEST                                                               \
	do {                                                                       \
		if (err == 0)                                                          \
			printf(GREEN "OK" NOCOLOR "\n");                                   \
		else {                                                                 \
			printf(RED "FAILED:" NOCOLOR " %d failed tests of %d.\n\t", err,   \
			       test);                                                      \
			for (int i = 0; i < err; i++)                                      \
				printf("[%d] ", errs[i]);                                      \
			printf("\n");                                                      \
		}                                                                      \
	} while (0)

#define TEST(c)                                                                \
	do {                                                                       \
		test++;                                                                \
		printf("[%d] test %s:%d: %s\n", test, __FILE__, __LINE__, #c);         \
		if (!(c)) {                                                            \
			printf(RED "\tFAILED" NOCOLOR "\n");                               \
			errs[err] = test;                                                  \
			err++;                                                             \
		} else                                                                 \
			printf(GREEN "\tOK" NOCOLOR "\n");                                 \
	} while (0)
#endif

#endif
