#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "merge.h"

int merge(int *A, int p, int q, int r) {
	int n1 = q - p, n2 = r - q;
	int *l_arr, *r_arr;
	int i, j ,k;

	/* sanity check */
	assert((p <= q) && (q < r));
	assert((n1 >= 0) && (n2 >= 0)); 

	l_arr = malloc(sizeof(*l_arr) * (n1 + 1));
	r_arr = malloc(sizeof(*l_arr) * (n2 + 1));
	memcpy(l_arr, A, sizeof(*l_arr) * n1);
	memcpy(r_arr, A + n1, sizeof(*r_arr) * n2);
	l_arr[n1] = INT_MAX;
	r_arr[n2] = INT_MAX;

	i = j = 0;
	for (k = p; k < r; k++) {
		if (l_arr[i] <= r_arr[j])
			A[k] = l_arr[i++];
		else
			A[k] = r_arr[j++];
	}

	free(l_arr);
	free(r_arr);
}

int test_merge() {
	int merge_input_data[] = {2, 4, 5, 7, 1, 2, 3, 6};
	int merge_expected_data[] = {1, 2, 2, 3, 4, 5, 6, 7};

	merge(&merge_input_data, 0, 4, 8);

	assert(memcmp(merge_input_data, merge_expected_data,
	       ARRAY_SIZE(merge_input_data)) == 0);
}