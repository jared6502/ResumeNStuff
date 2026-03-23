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

bool isNumber(char* s)
{
	bool inthassign = false;
	bool intdec = false;
	bool inthasdigits = false;
	bool expo = false;
	bool expohassign = false;
	bool expohasdigits = false;

	for (int i = 0; i < 20 && s[i] != '\0'; i++)
	{
		if (!expo)
		{
			switch (s[i])
			{
			case '+':
			case '-':
				if (!inthassign && !intdec && !inthasdigits)
				{
					inthassign = true;
					break;
				}
				else
				{
					return false;
				}

			case '.':
				if (!intdec)
				{
					intdec = true;
					break;
				}
				else
				{
					return false;
				}

			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				inthasdigits = true;
				break;

			case 'e':
			case 'E':
				if (!expo)
				{
					expo = true;
					break;
				}
				else
				{
					return false;
				}

			default:
				return false;
			}
		}
		else
		{
			switch (s[i])
			{
			case '+':
			case '-':
				if (!expohassign && !expohasdigits)
				{
					expohassign = true;
					break;
				}
				else
				{
					return false;
				}

			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				expohasdigits = true;
				break;

			default:
				return false;
			}
		}
	}

	return inthasdigits && (!expo || expohasdigits);
}