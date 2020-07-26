#ifndef _tests_assert_h_
#define _tests_assert_h_

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define EQUALS(x, y) do { \
	if (x != y) { printf("\t%s:%d: %s\n", __FILE__, __LINE__, #x " != " #y); return 1; } \
} while (0)

#define PROTEUS_DBL_EPSILON (0.000000001)
#define EQUALS_DBL(x, y) do { \
	if (fabs(x - y) > PROTEUS_DBL_EPSILON) { printf("\t%s:%d: %s\n", __FILE__, __LINE__, #x " !~= " #y); return 1; } \
} while (0)

#define PROTEUS_FLT_EPSILON (0.00001)
#define EQUALS_FLT(x, y) do { \
	if (fabsf(x - y) > PROTEUS_FLT_EPSILON) { printf("\t%s:%d: %s\n", __FILE__, __LINE__, #x " !~= " #y); return 1; } \
} while (0)

#define IS_TRUE(x) do { \
	if ((x) != true) { printf("\t%s:%d: %s\n", __FILE__, __LINE__, #x " is FALSE"); return 1; } \
} while (0)

#define IS_FALSE(x) do { \
	if ((x) != false) { printf("\t%s:%d: %s\n", __FILE__, __LINE__, #x " is TRUE"); return 1; } \
} while (0)

#endif // _tests_assert_h_