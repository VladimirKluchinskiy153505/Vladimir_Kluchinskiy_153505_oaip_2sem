#include <cerrno>
#include <iostream>
using namespace std;
 size_t Strlen(const char* str)
{
	const char* s;

	for (s = str; *s; ++s);
	return (s - str);
}
void* Memcpy2(void* s1,  void* s2, size_t n) {
	char* csrc = static_cast<char*>(s1);
	char* cdest = static_cast<char*>(s2);
		cdest = new char[n + 1];
		for (int i = 0; i < n; i++) {
			cdest[i] = csrc[i];
		}
		cdest[n] = '\0';
		return cdest;
}
void Memcpy(void* dest, void* src, size_t n)
{
	// Typecast src and dest addresses to (char *)
	char* csrc = (char*)src;
	char* cdest = (char*)dest;

	// Copy contents of src[] to dest[]
	for (int i = 0; i < n; i++)
		cdest[i] = csrc[i];
}
void Memmove(void* dest, void* src, size_t n)
{
	char* csrc = (char*)src;
	char* cdest = (char*)dest;

	char* temp = new char[n];
	for (int i = 0; i < n; i++)
		temp[i] = csrc[i];
	for (int i = 0; i < n; i++)
		cdest[i] = temp[i];

	delete[] temp;
}
void Strcpy1(char* dest, const char* source)
{
	int i = 0;
	while (1)
	{
		dest[i] = source[i];
		if (dest[i] == '\0')
		{
			break;
		}
		i++;
	}
}
char* Strncpy(char* dst, const char* src, size_t n)
{
	int i;
	char* temp;
	temp = dst;
	for (i = 0; i < n; i++)
		*dst++ = *src++;
	return temp;
}
char* Strcat(char* destination, const char* source)
{
	char* ptr = destination + strlen(destination);

	while (*source != '\0') {
		*ptr++ = *source++;
	}
	*ptr = '\0';
	return destination;
}
char* Strncat(char* destination, const char* source, size_t num)
{
	// make `ptr` point to the end of the destination string
	char* ptr = destination + strlen(destination);

	// Appends characters of the source to the destination string
	while (*source != '\0' && num--) {
		*ptr++ = *source++;
	}

	// null terminate destination string
	*ptr = '\0';

	// destination string is returned by standard `strncat()`
	return destination;
}
int Memcmp(const void* buf1,const void* buf2,size_t count)
{
	if (!count)
		return(0);

	while (--count && *(char*)buf1 == *(char*)buf2) {
		buf1 = (char*)buf1 + 1;
		buf2 = (char*)buf2 + 1;
	}
	return(*((unsigned char*)buf1) - *((unsigned char*)buf2));
}
int Strcmp(const char* X, const char* Y)
{
	while (*X)
	{
		// if characters differ, or end of the second string is reached
		if (*X != *Y) {
			break;
		}

		// move to the next pair of characters
		X++;
		Y++;
	}
	// return the ASCII difference after converting `char*` to `unsigned char*`
	return *(const unsigned char*)X - *(const unsigned char*)Y;
}

int Strcoll(const char* s1, const char* s2) {


	while (*s1 == *s2++)
		if (*s1++ == '\0')
			return (0);

	return (*(const unsigned char*)s1 - *(const unsigned char*)(s2 - 1));
}
int Strncmp(const char* s, const char* t, size_t num)
{
	for (; num > 0; s++, t++, num--)
		if (*s == 0)
			return 0;

	if (*s == *t) {
		++s;
		++t;
	}
	else if (*s != *t)
		return *s - *t;
}
 size_t Strxfrm(char* dest, const char* src, size_t n) {

	//src = setlocale(LC_COLLATE, "en_us.utf8");

	if (!dest)
		return 0;

	size_t i;

	for (i = 0; i < n; ++i)
		*(dest + i) = *(src + i);

	*(dest + i) = '\0';

	return strlen(dest);
}
 char* Strtok(char* s, char d)
 {
	 // Stores the state of string
	 static char* input = NULL;

	 // Initialize the input string
	 if (s != NULL)
		 input = s;

	 // Case for final token
	 if (input == NULL)
		 return NULL;

	 // Stores the extracted string
	 char* result = new char[strlen(input) + 1];
	 int i = 0;

	 // Start extracting string and
	 // store it in array
	 for (; input[i] != '\0'; i++) {

		 // If delimiter is not reached
		 // then add the current character
		 // to result[i]
		 if (input[i] != d)
			 result[i] = input[i];

		 // Else store the string formed
		 else {
			 result[i] = '\0';
			 input = input + i + 1;
			 return result;
		 }
	 }

	 // Case when loop ends
	 result[i] = '\0';
	 input = NULL;

	 // Return the resultant pointer
	 // to the string
	 return result;
 }
 void* Memset(void* s, int c, size_t len) {

	 unsigned char* dst = (unsigned char*)s;

	 while (len--) {

		 *dst = (unsigned char)c;

		 dst++;
	 }

	 return s;
 }
 char* _strerror(int errnum) {


	 if (errnum == E2BIG) //7
		 return (char*)"Список аргументов слишком длинный";

	 if (errnum == EACCES) //13
		 return (char*)"Отказ в доступе";

	 if (errnum == EADDRINUSE) //100
		 return (char*)"Адрес используется";

	 if (errnum == EADDRNOTAVAIL) //101
		 return (char*)"Адрес недоступен";

	 if (errnum == EAFNOSUPPORT) //102
		 return (char*)"Семейство адресов не поддерживается";

	 if (errnum == EAGAIN) //11
		 return (char*)"Ресурс временно недоступен";

	 if (errnum == EDOM) //33
		 return (char*)"Ошибка области определения";

	 if (errnum == EEXIST) //17
		 return (char*)"Файл существует";

	 if (errnum == EFAULT) //14
		 return (char*)"Неправильный адрес";

	 if (errnum == ENOENT) //2
		 return (char*)"Нет такого файла или каталога";

	 if (errnum == ENOMEM) //12
		 return (char*)"Недостаточно памяти";

	 if (errnum == ERANGE) //34
		 return (char*)"Результат слишком велик";

	 if (errnum == EADDRINUSE) //100
		 return (char*)"Адрес используется";

	 if (errnum == ETXTBSY) //139
		 return (char*)"Текстовый файл занят";

	 return (char*)"EINVAL"; //Значение errnum не является правильным кодом ошибки

 }
int main()
{
	const char* ptr= "abd";
	cout << Strlen(ptr);
	return 0;
}

