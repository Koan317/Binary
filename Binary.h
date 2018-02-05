#ifndef BINARY_H
#define BINARY_H
#include <bitset>
using namespace std;

class Binary
{
	bitset<32> num;
public:
	Binary(unsigned long num) { this->num = num; }
	Binary(string num);
	Binary operator<<(size_t bit)const;
	Binary operator>>(size_t bit)const;
	Binary operator=(const Binary num);
	Binary operator<<=(size_t bit);
	Binary operator>>=(size_t bit);
	int operator[](size_t i)const { return num[i]; }
	friend ostream &operator<<(ostream &output, const Binary &x);
};

Binary::Binary(string num)
{
	int leng = num.length();
	int length = leng < 32 ? leng : 32;
	if (leng > 32)
		num = num.substr(leng - 32, 32);
	for (auto i = 0; i < length; ++i)
		this->num[i] = (int)(num[length - i - 1] - 48);//将字符强转为整型
}

inline Binary Binary::operator<<(size_t bit) const
{
	bit %= 32;//移动32位会回到原位置
	if (bit == 0)//相当于没移动
		return Binary(num.to_ulong());
	else
		return Binary((num.to_ulong() << bit) + (num.to_ulong() >> (32 - bit)));
}

inline Binary Binary::operator>>(size_t bit) const
{
	bit %= 32;//移动32位会回到原位置
	if (bit == 0)//相当于没移动
		return Binary(num.to_ulong());
	else
		return Binary((num.to_ulong() >> bit) + (num.to_ulong() << (32 - bit)));
}

inline Binary Binary::operator=(const Binary num)
{
	if (this != &num)
		for (auto i = 0; i < 32; ++i)
			this->num[i] = num[i];
	return *this;
}

inline Binary Binary::operator<<=(size_t bit)
{
	*this = *this << bit;
	return *this;
}

inline Binary Binary::operator>>=(size_t bit)
{
	*this = *this >> bit;
	return *this;
}

ostream &operator<<(ostream &output, const Binary &num)
{
	bitset<32> s;
	for (auto i = 0; i < 32; ++i)
		s[i] = num[i];
	return output << s;
}
#endif // !BINARY_H
