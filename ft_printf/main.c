int ft_printf(const char *, ...);

#include <stdio.h>

int main(void)
{
	int ret;
	int ret2;

	ret = ft_printf("FT | [%d] [%.d] [%5d] [%.5d] [%5.5d] [%5.4d] [%4.5d] [%3.d] [%.3d]\n", 42, 42, 42, 42, 42, 42, 42, 42, 42);
	ret2 = printf("SY | [%d] [%.d] [%5d] [%.5d] [%5.5d] [%5.4d] [%4.5d] [%3.d] [%.3d]\n", 42, 42, 42, 42, 42, 42, 42, 42, 42);
	printf("FT: [%d], SY: [%d]\n", ret, ret2);
	ret = ft_printf("FT | [%d] [%.d] [%5d] [%.5d] [%5.5d] [%5.4d] [%4.5d] [%3.d] [%.3d]\n", 0, 0, 0, 0, 0, 0, 0, 0, 0);
	ret2 = printf("SY | [%d] [%.d] [%5d] [%.5d] [%5.5d] [%5.4d] [%4.5d] [%3.d] [%.3d]\n", 0, 0, 0, 0, 0, 0, 0, 0, 0);
	printf("FT: [%d], SY: [%d]\n", ret, ret2);
	ret = ft_printf("FT | [%d] [%.d] [%5d] [%.5d] [%5.5d] [%5.4d] [%4.5d] [%3.d] [%.3d]\n", -42, -42, -42, -42, -42, -42, -42, -42, -42);
	ret2 = printf("SY | [%d] [%.d] [%5d] [%.5d] [%5.5d] [%5.4d] [%4.5d] [%3.d] [%.3d]\n", -42, -42, -42, -42, -42, -42, -42, -42, -42);
	printf("FT: [%d], SY: [%d]\n", ret, ret2);

	
	ret = ft_printf("FT | [%x] [%.x] [%5x] [%.5x] [%5.5x] [%5.4x] [%4.5x] [%3.x] [%.3x]\n", 42, 42, 42, 42, 42, 42, 42, 42, 42);
	ret2 = printf("SY | [%x] [%.x] [%5x] [%.5x] [%5.5x] [%5.4x] [%4.5x] [%3.x] [%.3x]\n", 42, 42, 42, 42, 42, 42, 42, 42, 42);
	printf("FT: [%d], SY: [%d]\n", ret, ret2);

	ret = ft_printf("FT | [%x] [%.x] [%5x] [%.5x] [%5.5x] [%5.4x] [%4.5x] [%3.x] [%.3x]\n", 0, 0, 0, 0, 0, 0, 0, 0, 0);
	ret2 = printf("SY | [%x] [%.x] [%5x] [%.5x] [%5.5x] [%5.4x] [%4.5x] [%3.x] [%.3x]\n", 0, 0, 0, 0, 0, 0, 0, 0, 0);
	printf("FT: [%d], SY: [%d]\n", ret, ret2);
	
	ret = ft_printf("FT | [%x] [%.x] [%5x] [%.5x] [%5.5x] [%5.4x] [%4.5x] [%3.x] [%.3x]\n", -42, -42, -42, -42, -42, -42, -42, -42, -42);
	ret2 = printf("SY | [%x] [%.x] [%5x] [%.5x] [%5.5x] [%5.4x] [%4.5x] [%3.x] [%.3x]\n", -42, -42, -42, -42, -42, -42, -42, -42, -42);
	printf("FT: [%d], SY: [%d]\n", ret, ret2);

	ret = ft_printf("ft | [%s] [%.s] [%5s] [%.5s] [%5.5s] [%5.4s] [%4.5s] [%3.s] [%.3s]\n", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello");
	ret2 = printf("sy | [%s] [%.s] [%5s] [%.5s] [%5.5s] [%5.4s] [%4.5s] [%3.s] [%.3s]\n", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello");
	printf("ft: [%d], sy: [%d]\n", ret, ret2);

	ret = ft_printf("ft | [%s] [%.s] [%5s] [%.5s] [%5.5s] [%5.4s] [%4.5s] [%3.s] [%.3s]\n", NULL,  NULL,  NULL,  NULL,  NULL,  NULL,  NULL,  NULL, NULL);
	ret2 = printf("sy | [%s] [%.s] [%5s] [%.5s] [%5.5s] [%5.4s] [%4.5s] [%3.s] [%.3s]\n",  NULL,  NULL,  NULL,  NULL,  NULL,  NULL,  NULL,  NULL, NULL);
	printf("ft: [%d], sy: [%d]\n", ret, ret2);
}
