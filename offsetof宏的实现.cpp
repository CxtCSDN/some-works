#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>


#define SWAP(num) num = (((num & 0x55555555) << 1) + ((num & 0xaaaaaaaa) >> 1))

#define OFFSETOF(structName, member) (size_t)&((((structName*)0)->member))

struct student {
	int num;
	char name;
	double mark;
};
int main()
{
	int num = 0;
	std::cin >> num;
	SWAP(num);
	std::cout << num;
#if 0
	std::cout << OFFSETOF(struct student, num) << std::endl;
	std::cout << OFFSETOF(struct student, name) << std::endl;
	std::cout << OFFSETOF(struct student, mark) << std::endl;
#endif
	
	return 0;
}