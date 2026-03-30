/*

Copyright 2026 Jared Robert Wright

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <stdlib.h>

int compare_int(const void* a, const void* b)
{
	return (int)(*((unsigned int*)a) - *((unsigned int*)b));
}

int firstMissingPositive(int* nums, int numsSize)
{
	int start = -1;

	if (numsSize == 1)
	{
		return (nums[0] != 1) ? 1 : 2;
	}
	else
	{
		qsort(nums, numsSize, sizeof(int), compare_int);

		for (int i = 0; i < numsSize; i++)
		{
			if (nums[i] > 0)
			{
				start = i;
				break;
			}
		}

		if (start == -1 || nums[start] > 1)
		{
			return 1;
		}

		for (int i = 0; i < numsSize - 1; i++)
		{
			if (nums[i] > 0)
			{
				if (nums[i + 1] - nums[i] > 1)
				{
					return nums[i] + 1;
				}
			}
		}

		return nums[numsSize - 1] + 1;
	}
}