#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_dir
{
	int width;
	int precision;
}				t_dir;

long ft_max(long a, long b)
{
	return (a > b) ? a : b;
}

unsigned int ft_strlen(char *str)
{
	unsigned int i = 0;
	while (str[i])
		i++;
	return i;
}

int ft_atoi(const char *str)
{
	int total = 0;
	while (*str >= '0' && *str <= '9')
	{
		total = (total * 10) + (*str - '0');
		str++;
	}
	return total;
}

int ft_numlen(unsigned int val, char *base)
{
	int len = 1;
	unsigned int baselen = ft_strlen(base);

	while (val /= baselen)
		len++;
	return len;
}

int ft_putnbr(unsigned int val, char *base)
{
	unsigned int baselen = ft_strlen(base);

	if (val >= baselen)
		ft_putnbr(val / baselen, base);
	write(1, &base[val % baselen], 1);
	return ft_numlen(val, base);
}

int print_int(t_dir *dir, int val)
{
	int neg = (val < 0) ? 1 : 0;
	unsigned int uval = (neg) ? -val : val;
	int len = ft_numlen(uval, "0123456789");
	int precision = ft_max(dir->precision, len);
	int printable_precision = precision - len;
	if (val == 0 && dir->precision == 0 && dir->width >= 1)
		dir->width++;
	int width = ft_max(dir->width, precision);
	int printable_width = ft_max(width - (precision + neg), 0);
	int printed = 0;

	while (printed < printable_width)
		printed += write(1, " ", 1);
	if (neg)
		printed += write(1, "-", 1);
	while (printed < printable_width + printable_precision + neg)
		printed += write(1, "0", 1);
	if (!(val == 0 && dir->precision == 0))
		printed += ft_putnbr(uval, "0123456789");
	return printed;
}

int print_hex(t_dir *dir, unsigned int uval)
{
	int len = ft_numlen(uval, "0123456789abcdef");
	int precision = ft_max(dir->precision, len);
	int printable_precision = precision - len;
	if (uval == 0 && dir->precision == 0 && dir->width >= 1)
		dir->width++;
	int width = ft_max(dir->width, precision);
	int printable_width = ft_max(width - precision, 0);
	int printed = 0;

	while (printed < printable_width)
		printed += write(1, " ", 1);
	while (printed < printable_width + printable_precision)
		printed += write(1, "0", 1);
	if (!(uval == 0 && dir->precision == 0))
		printed += ft_putnbr(uval, "0123456789abcdef");
	return printed;
}

int print_str(t_dir *dir, char *val)
{
	if (!val)
		val = "(null)";
	int len = ft_strlen(val);
	if (dir->precision == -1)
		dir->precision = len;
	int printable_precision = (dir->precision > len) ? len : dir->precision;
	int width = ft_max(dir->width, printable_precision);
	int printable_width = ft_max(width - printable_precision, 0);
	int printed = 0;

	while (printed < printable_width)
		printed += write(1, " ", 1);
	printed += write(1, val, printable_precision);
	return printed;
}

int do_convert(const char **str, va_list args)
{
	t_dir dir;
	int printed = 0;

	dir.width = ft_atoi(*str);
	dir.precision = -1;
	while (**str >= '0' && **str <= '9')
		(*str)++;
	if (**str == '.')
	{
		(*str)++;
		dir.precision = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			(*str)++;
	}
	if (**str == 'd')
		printed = print_int(&dir, va_arg(args, int));
	else if (**str == 'x')
		printed = print_hex(&dir, va_arg(args, unsigned int));
	else if (**str == 's')
		printed = print_str(&dir, va_arg(args, char *));
	if (**str)
		(*str)++;
	return printed;
}

int ft_printf(const char *str, ...)
{
	int printed = 0;
	va_list args;

	if (!str)
		return 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			printed += do_convert(&str, args);
		}
		else
		{
			printed += write(1, str, 1);
			str++;
		}
	}
	va_end(args);
	return printed;
}
