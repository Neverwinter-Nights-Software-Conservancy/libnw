#include	<config.h>
#if HAVE_ENDIAN_H
#include	<endian.h>
#elif HAVE_MACHINE_ENDIAN_H
#include	<machine/endian.h>
#endif

#if WORDS_BIGENDIAN

void be2les(short* ip)
{
	union be2les
	{
		unsigned char c[2];
		short i;
	};
	union be2les cb;
	unsigned char t0;
	unsigned char t1;

	cb.i = *ip;
	t0 = cb.c[0]; t1 = cb.c[1];
	cb.c[1] = t0; cb.c[0] = t1;
	*ip = cb.i;
}

void be2leus(unsigned short* ip)
{
	union be2leus
	{
		unsigned char c[2];
		unsigned short i;
	};
	union be2leus cb;
	unsigned char t0;
	unsigned char t1;

	cb.i = *ip;
	t0 = cb.c[0]; t1 = cb.c[1];
	cb.c[1] = t0; cb.c[0] = t1;
	*ip = cb.i;
}

void be2lei(int* ip)
{
	union be2leus
	{
		unsigned char c[4];
		int i;
	};
	union be2leus cb;
	unsigned char t0;
	unsigned char t1;

	cb.i = *ip;
	t0 = cb.c[0]; t1 = cb.c[3];
	cb.c[3] = t0; cb.c[0] = t1;
	t0 = cb.c[1]; t1 = cb.c[2];
	cb.c[2] = t0; cb.c[1] = t1;
	*ip = cb.i;
}

void be2leui(unsigned int* ip)
{
	union be2leus
	{
		unsigned char c[4];
		unsigned int i;
	};
	union be2leus cb;
	unsigned char t0;
	unsigned char t1;

	cb.i = *ip;
	t0 = cb.c[0]; t1 = cb.c[3];
	cb.c[3] = t0; cb.c[0] = t1;
	t0 = cb.c[1]; t1 = cb.c[2];
	cb.c[2] = t0; cb.c[1] = t1;
	*ip = cb.i;
}

void be2lel(long* lp)
{
	union be2lel
	{
		unsigned char c[4];
		long i;
	};
	union be2lel cb;
	unsigned char t0;
	unsigned char t1;

	cb.i = *lp;
	t0 = cb.c[0]; t1 = cb.c[3];
	cb.c[3] = t0; cb.c[0] = t1;
	t0 = cb.c[1]; t1 = cb.c[2];
	cb.c[2] = t0; cb.c[1] = t1;
	*lp = cb.i;
}

void be2leul(unsigned long* lp)
{
	union be2leul
	{
		unsigned char c[4];
		unsigned long i;
	};
	union be2leul cb;
	unsigned char t0;
	unsigned char t1;

	cb.i = *lp;
	t0 = cb.c[0]; t1 = cb.c[3];
	cb.c[3] = t0; cb.c[0] = t1;
	t0 = cb.c[1]; t1 = cb.c[2];
	cb.c[2] = t0; cb.c[1] = t1;
	*lp = cb.i;
}

void be2leull(unsigned long long* ulp)
{
	union be2leull
	{
		unsigned char c[8];
		unsigned long long i;
	};
	union be2leull cb;
	unsigned char t0;
	unsigned char t1;

	cb.i = *ulp;
	t0 = cb.c[0]; t1 = cb.c[7];
	cb.c[7] = t0; cb.c[0] = t1;
	t0 = cb.c[1]; t1 = cb.c[6];
	cb.c[6] = t0; cb.c[1] = t1;
	t0 = cb.c[2]; t1 = cb.c[5];
	cb.c[5] = t0; cb.c[2] = t1;
	t0 = cb.c[3]; t1 = cb.c[4];
	cb.c[4] = t0; cb.c[3] = t1;
	*ulp = cb.i;
}

void be2lell(long long* llp)
{
	union be2lell
	{
		unsigned char c[8];
		long long i;
	};
	union be2lell cb;
	unsigned char t0;
	unsigned char t1;

	cb.i = *llp;
	t0 = cb.c[0]; t1 = cb.c[7];
	cb.c[7] = t0; cb.c[0] = t1;
	t0 = cb.c[1]; t1 = cb.c[6];
	cb.c[6] = t0; cb.c[1] = t1;
	t0 = cb.c[2]; t1 = cb.c[5];
	cb.c[5] = t0; cb.c[2] = t1;
	t0 = cb.c[3]; t1 = cb.c[4];
	cb.c[4] = t0; cb.c[3] = t1;
	*llp = cb.i;
}

#endif /* WORDS_BIGENDIAN */
