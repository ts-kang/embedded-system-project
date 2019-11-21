#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>

#ifdef DEBUG
#define debug(fmt, ...) fprintf(stdout, fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...)						\
	do {							\
		if (0)						\
			fprintf(stdout, fmt, ##__VA_ARGS__);	\
	} while (0)
#endif

#endif /* _DEBUG_H_ */
