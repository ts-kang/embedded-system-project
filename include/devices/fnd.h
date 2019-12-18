
#ifndef _FND_H_
#define _FND_H_

void fnd_init(void);
void fnd_destroy(void);

pthread_t *fnd_thread(int );
void *t_function(void *);

#endif /* _FND_H_ */