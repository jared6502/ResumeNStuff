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
#include <math.h>

char* addBinary(char* a, char* b)
{
	int lenA = 0;
	int lenB = 0;
	char* result;
	char output[10001];

	while (a[lenA] != '\0')
	{
		lenA++;
	}
	while (b[lenB] != '\0')
	{
		lenB++;
	}

	int an = 0;
	int bn = 0;
	int cn;
	int bitlen;

	for (int i = 0; i < lenA; i++)
	{
		if (a[lenA - i - 1] == '1')
		{
			an |= (1 << i);
		}
	}
	for (int i = 0; i < lenB; i++)
	{
		if (b[lenB - i - 1] == '1')
		{
			bn |= (1 << i);
		}
	}

	cn = an + bn;
	if (cn == 0)
	{
		bitlen = 1;
	}
	else
	{
		bitlen = (int)(floor(log2(cn)) + 1);
	}

	result = (char*)(malloc((bitlen + 1) * sizeof(char)));
	result[bitlen] = '\0';
	for (int i = bitlen - 1; i >= 0; i--)
	{
		result[bitlen - 1 - i] = (cn & (1 << i)) ? '1' : '0';
	}

	return result;
}