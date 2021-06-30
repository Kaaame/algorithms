#pragma once
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(typeof(x[0])))

int merge(int *A, int p, int q, int r);
int test_merge();