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

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int index1 = 0, index2 = 0;
	bool even = false;

	if (nums1Size == 0)
	{
		index2 = nums2Size >> 1;
		if (nums2Size & 1)
		{
			return nums2[index2];
		}
		else
		{
			return (nums2[index2] + nums2[index2 - 1]) / 2.0;
		}
	}
	else if (nums2Size == 0)
	{
		index1 = nums1Size >> 1;
		if (nums1Size & 1)
		{
			return nums1[index1];
		}
		else
		{
			return (nums1[index1] + nums1[index1 - 1]) / 2.0;
		}
	}
	else
	{
		int mergedlist[2000];
		int mergedsize = nums1Size + nums2Size;
		index1 = index2 = 0;

		for (int i = 0; i < mergedsize; i++)
		{
			if (index1 < nums1Size && index2 < nums2Size)
			{
				if (nums1[index1] < nums2[index2])
				{
					mergedlist[i] = nums1[index1];
					index1++;
				}
				else
				{
					mergedlist[i] = nums2[index2];
					index2++;
				}
			}
			else if (index1 < nums1Size)
			{
				mergedlist[i] = nums1[index1];
				index1++;
			}
			else if (index2 < nums2Size)
			{
				mergedlist[i] = nums2[index2];
				index2++;
			}
		}

		return (mergedsize & 1) ? mergedlist[mergedsize >> 1] : ((mergedlist[(mergedsize >> 1)] + mergedlist[(mergedsize >> 1) - 1]) / 2.0);
	}
}