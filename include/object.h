#ifndef	__LIBNW_OBJECT_H__
#define	__LIBNW_OBJECT_H__

#include	"v.h"
#include	"itp.h"

struct nwn_object_locstr_strs
{
	int lang;
	char* str;
};

struct nwn_object_locstr
{
	unsigned long strref;
	struct v* strs;	// (struct nwn_object_locstr_strs*)
};

struct nwn_object_blob
{
	int len;
	char* data;
};

struct nwn_object_record
{
	int code;
	struct v* v;	/* (struct nwn_object*) */
};

struct nwn_object_listitem
{
	int code;
	struct nwn_object* itemp;
};

struct nwn_object_field
{
	enum nwn_itp_typecode type;
	unsigned long index;
	union nwn_simpleval
	{
		unsigned char ui8;
		signed char si8;
		unsigned short ui16;
		signed short si16;
		unsigned int ui32;
		signed int si32;
		float f;
	}
	data_or_offset;
};

struct nwn_object
{
	char* name;
	enum nwn_itp_typecode type;
	union
	{
		unsigned char ui8;
		signed char si8;
		unsigned short ui16;
		signed short si16;
		unsigned int ui32;
		signed int si32;
		unsigned long long ui64;
		signed long long si64;
		float f;
		double d;
		char* s;
		char rr[16];
		struct nwn_object_locstr  locstr;
		struct nwn_object_blob blob;
		struct nwn_object_record rec;
		struct v* list;	/* (struct v* (struct nwn_object_record*)) */
	}
	val;
};

/**
 * converts a binary image of a property list resource (ITP-like) \a resc
 * to a vector of nwn_object structures.  On any failure, returns 0.
 */
extern struct v* cvt_to_plist(char* resc);

/**
 * makes a copy of \a src, a vector of struct nwn_object_locstr.
 */
extern struct nwn_object_locstr copy_locstrs(struct nwn_object_locstr src);

/*
 * these macros are syntactic sugar to make most of the contents of the
 * libnw/plist2XXX.c files easier to code with fewer typos.
 */
#define asgn(p,q,m,t) if(strcmp(p->name,#m)==0){q->m=p->val.t;}
#define asgnrr(p,q,m) if(strcmp(p->name,#m)==0){strncpy(q->m,p->val.rr,sizeof q->m);}
#define asgns(p,q,m) if(strcmp(p->name,#m)==0){q->m=strdup(p->val.s);}
#define asgnls(p,q,m) if(strcmp(p->name,#m)==0){q->m=copy_locstrs(p->val.locstr);}

#endif
