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

#include <math.h>

bool isPalindrome(int x)
{
	//short-circuit here to save time
	if (x < 0) return false;
	if (x < 10) return true;
	if (x < 100 && (x % 10) != (x / 10)) return false;

	//get width in digits
	int width = (int)(floor(log10(x)) + 1);
	int tmp = x;
	int lodigit;
	int hidigit;
	int divisor1;
	int divisor2;
	int divisor3;
	int digit1;
	int digit2;
	int digits_to_check = (width >> 1) + ((width & 1) ? 1 : 0);

	for (int i = 0; i < digits_to_check; i++)
	{
		divisor1 = (int)(pow(10, width - i - 1));
		divisor2 = (int)(pow(10, i));

		digit1 = (x / divisor1) % 10;
		digit2 = (x / divisor2) % 10;

		if (digit1 != digit2)
		{
			return false;
		}
	}

	return true;
}