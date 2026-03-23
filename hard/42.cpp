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

/*

//original slow but working solution

int trap(int* height, int heightSize)
{
	int maxheight = 0;
	int rain = 0;

	//get max height
	for (int i = 0; i < heightSize; i++)
	{
		if (maxheight < height[i]) maxheight = height[i];
	}

	for (int i = 1; i <= maxheight; i++)
	{
		int firstblock = 0;
		int lastblock = heightSize;
		for (int j = firstblock; j < heightSize; j++)
		{
			if (height[j] >= i)
			{
				firstblock = j;
				break;
			}
		}
		for (int j = lastblock - 1; j > -1; j--)
		{
			if (height[j] >= i)
			{
				lastblock = j;
				break;
			}
		}
		if (lastblock != firstblock && lastblock < heightSize && firstblock > -1)
		{
			for (int j = firstblock; j < lastblock; j++)
			{
				if (height[j] < i)
				{
					rain++;
				}
			}
		}
	}

	return rain;
}
*/

//much faster and simpler solution

int trap(int* height, int heightSize)
{
	int maxheight = 0;
	int heightleft = 0;
	int heightright = 0;
	int split = 0;
	int rain = 0;

	//get max height
	for (int i = 0; i < heightSize; i++)
	{
		if (maxheight < height[i])
		{
			maxheight = height[i];
			split = i;
		}
	}

	int firstblock = 0;
	int lastblock = heightSize;
	for (int i = 0; i < split; i++)
	{
		if (height[i] >= heightleft)
		{
			heightleft = height[i];
		}
		else
		{
			rain += heightleft - height[i];
		}
	}
	for (int i = lastblock - 1; i > split; i--)
	{
		if (height[i] >= heightright)
		{
			heightright = height[i];
		}
		else
		{
			rain += heightright - height[i];
		}
	}

	return rain;
}