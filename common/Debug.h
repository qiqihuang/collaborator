#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdarg.h>

#ifdef _DEBUG
	#define PRINT(fmt, args...)	\
	printf("\n[%s:%d]"fmt, __FUNCTION__, __LINE__, ##args)
#else
	#define PRINT(format, ...)
#endif

#ifdef _DEBUG
	#define EXCEPTION(fmt, args...)	\
	printf("\n[%s:%d] Exception: "fmt, __FUNCTION__, __LINE__, ##args)
#else
	#define EXCEPTION(format, ...)
#endif

#endif
