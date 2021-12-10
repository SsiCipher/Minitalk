#include <stdio.h>
#include <unistd.h>

int get_nth_bit(unsigned char c, int n)
{
	unsigned char	comp_c;

	comp_c = 0b10000000;
	if (n > 8)
		return (-1);
	else
		return ((c & (comp_c >> (n - 1))) >> (8 - n));
}

char assemble_char(int *chr_bits)
{
	char	chr;
	int		shift;

	shift = 0;
	chr = 0b00000000;
	while (shift < 8)
	{
		chr |= chr_bits[shift];
		if (shift != 7)
			chr <<= 1;
		shift++;
	}
	return (chr);
}

void handl(unsigned char *n, int bit, int *shift)
{
	*n |= bit;
	if (*shift != 7)
		*n = *n << 1;
	*shift += 1;
	if(*shift == 8)
	{
		write(1, n, 1);
		*n = 0b00000000;
		*shift = 0;
	}
}

void put_bit_string(unsigned char *chr, char *str, int *shift)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 1;
		while (j <= 8)
		{
			handl(chr, get_nth_bit(str[i], j), shift);
			j++;
		}
		i++;
	}
}

int main() {
	int shift = 0;
	unsigned char n = 0b00000000;

	put_bit_string(&n, "Hello dfgdfg ", &shift);

	return 0;
}
