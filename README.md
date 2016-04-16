# gelasia-sort
Sorting algorithm based on separating the range between the numbers.

Being **r** the range of numbers.

The complexity that I can notice so far is slightly (but I mean, really slightly) bigger than *O*(r)**,
and appears to be better than qsort when **n** is larger.

My last output:

```
running with n=4096
	gelasia_sort
		done in 6064.
	pure qsort
		done in 989.
running with n=8192
	gelasia_sort
		done in 6796.
	pure qsort
		done in 1662.
running with n=16384
	gelasia_sort
		done in 7267.
	pure qsort
		done in 3585.
running with n=32768
	gelasia_sort
		done in 8754.
	pure qsort
		done in 7605.
running with n=65536
	gelasia_sort
		done in 11636.
	pure qsort
		done in 16321.
running with n=131072
	gelasia_sort
		done in 17652.
	pure qsort
		done in 34789.
running with n=262144
	gelasia_sort
		done in 32615.
	pure qsort
		done in 73461.
running with n=524288
	gelasia_sort
		done in 66954.
	pure qsort
		done in 155290.
running with n=1048576
	gelasia_sort
		done in 180526.
	pure qsort
		done in 326805.
running with n=2097152
	gelasia_sort
		done in 1342631.
	pure qsort
		done in 686907.
running with n=4194304
	gelasia_sort
		done in 1631919.
	pure qsort
		done in 1440307.
running with n=8388608
	gelasia_sort
		done in 2169348.
	pure qsort
		done in 3008655.
running with n=16777216
	gelasia_sort
		done in 3284069.
	pure qsort
		done in 6280824.
running with n=33554432
	gelasia_sort
		done in 5845442.
	pure qsort
		done in 13142086.
running with n=67108864
	gelasia_sort
		done in 12147919.
	pure qsort
		done in 27309181.
```
