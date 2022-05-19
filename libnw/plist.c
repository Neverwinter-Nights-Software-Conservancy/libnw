#include	<config.h>
#include	<stdio.h>
#include	<assert.h>
#if STDC_HEADERS || HAVE_STDLIB_H
#include	<stdlib.h>
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS || HAVE_MEMORY_H
#  include	<memory.h>
# endif
# include	<string.h>
#endif
#include	"global.h"
#include	"object.h"
#include	"itp.h"
#include	"bendian.h"
#include	"exmem.h"

static struct nwn_itp head;
static struct nwn_itp_list* listp;
static struct nwn_itp_data* datap;
static struct nwn_itp_tag* tagp;
static char* valuep;
static int* rootp;
static int* indexp;

static struct nwn_object* decode_data(int i);
static void add_entry( struct nwn_itp *header, struct nwn_itp_list *entry );
static struct nwn_itp_list *handle_entry( struct v *v );

struct v* cvt_to_plist(char* resc)
{
	int i;
	struct v* vp;

	/* extract header */
	memcpy((char*) &head, resc, sizeof head);
#if WORDS_BIGENDIAN
	be2lel(&head.oList);
	be2lel(&head.cList);
	be2lel(&head.oData);
	be2lel(&head.cData);
	be2lel(&head.oTag);
	be2lel(&head.cTag);
	be2lel(&head.oValue);
	be2lel(&head.cValue);
	be2lel(&head.oRoot);
	be2lel(&head.cRoot);
	be2lel(&head.oIndex);
	be2lel(&head.cIndex);
#endif

	/* extract "list" section */
	listp = malloc(head.cList * sizeof *listp);
	if (!listp)
	{
		fprintf(stderr, "%s: Can't allocate %ld lists!\n",
			MyName, head.cList);
		return 0;
	}
	memcpy((char*) listp, &resc[head.oList], head.cList * sizeof *listp);
#if WORDS_BIGENDIAN
	for (i = 0; i < head.cList; ++i)
	{
		be2lel(&listp[i].code);
		be2lel(&listp[i].index);
		be2lel(&listp[i].count);
	}
#endif

	/* extract "data" section */
	datap = malloc(head.cData * sizeof *datap);
	if (!datap)
	{
		fprintf(stderr, "%s: Can't allocate %ld data!\n",
			MyName, head.cData);
		return 0;
	}
	memcpy((char*) datap, &resc[head.oData], head.cData * sizeof *datap);
#if WORDS_BIGENDIAN
	for (i = 0; i < head.cData; ++i)
	{
		be2lel(&datap[i].type);
		be2lel(&datap[i].index);
		be2lel(&datap[i].data);
	}
#endif

	/* extract "tag" section */
	tagp = malloc(head.cTag * sizeof *tagp);
	if (!tagp)
	{
		fprintf(stderr, "%s: Can't allocate %ld tags!\n",
			MyName, head.cTag);
		return 0;
	}
	memcpy((char*) tagp, &resc[head.oTag], head.cTag * sizeof *tagp);

	/* extract "value" section */
	valuep = malloc(head.cValue * sizeof *valuep);
	if (!valuep)
	{
		fprintf(stderr, "%s: Can't allocate %ld values!\n",
			MyName, head.cValue);
		return 0;
	}
	memcpy((char*) valuep, &resc[head.oValue], head.cValue * sizeof *valuep);

	/* extract "root" section */
	rootp = malloc(head.cRoot);	/* cRoot is byte count! */
	if (!rootp)
	{
		fprintf(stderr, "%s: Can't allocate %ld roots!\n",
			MyName, head.cRoot / sizeof *rootp);
		return 0;
	}
	memcpy((char*) rootp, &resc[head.oRoot], head.cRoot);
#if WORDS_BIGENDIAN
	for (i = 0; i < (head.cRoot / sizeof *rootp); ++i)
		be2lei(&rootp[i]);
#endif

	/* extract "index" section */
	indexp = malloc(head.cIndex);	/* cIndex is byte count! */
	if (!indexp)
	{
		fprintf(stderr, "%s: Can't allocate %ld indexes!\n",
			MyName, head.cIndex / sizeof *indexp);
		return 0;
	}
	memcpy((char*) indexp, &resc[head.oIndex], head.cIndex);
#if WORDS_BIGENDIAN
	for (i = 0; i < (head.cIndex / sizeof *indexp); ++i)
		be2lei(&indexp[i]);
#endif

	/*
	** ok, we have it all unpacked in useful chunks, so let's build the
	** property list
	*/

	vp = vnew(listp[0].count);
	if (!vp)
	{
		fprintf(stderr, "%s: Can't allocate %ld objects!\n",
			MyName, listp[0].count);
		return 0;
	}
	if (listp[0].count == 1)
		vapp(vp, decode_data(listp[0].index / sizeof (int)));
	else
	{
		int* rp = &rootp[listp[0].index / sizeof (int)];

		for (i = 0; i < listp[0].count; ++i)
			vapp(vp, decode_data(rp[i]));
	}
	return vp;
}

static struct nwn_object* decode_data(int i)
{
	struct nwn_itp_data* dp = &datap[i];
	struct nwn_object* op;

	op = malloc(sizeof *op);
	if (!op)
	{
		fprintf(stderr, "%s: Can't allocate an object!\n", MyName);
		return 0;
	}
	// FIXME!
	op->name = malloc(17);
	if (!op->name)
	{
		fprintf(stderr, "%s: Can't allocate an object name!\n", MyName);
		return 0;
	}
	strncpy(op->name, tagp[dp->index].name, 16);
	op->type = dp->type;
	switch (dp->type)
	{
	case t_uint8:
		op->val.ui8 = (unsigned char) dp->data;
		break;
	case t_int8:
		op->val.si8 = (signed char) dp->data;
		break;
	case t_uint16:
		op->val.ui16 = (unsigned short) dp->data;
		break;
	case t_int16:
		op->val.si16 = (signed short) dp->data;
		break;
	case t_uint32:
		op->val.ui32 = (unsigned int) dp->data;
		break;
	case t_int32:
		op->val.si32 = (signed int) dp->data;
		break;
	case t_uint64:
		op->val.ui64 = *((unsigned long long*) &valuep[dp->data]);
#if WORDS_BIGENDIAN
		be2leull(&op->val.ui64);
#endif
		break;
	case t_int64:
		op->val.si64 = *((signed long long*) &valuep[dp->data]);
#if WORDS_BIGENDIAN
		be2lell(&op->val.ui64);
#endif
		break;
	case t_float:
		op->val.f = *((float*) &dp->data);
		break;
	case t_double:
		op->val.d = *((double*) &valuep[dp->data]);
		break;
	case t_string:
	{
		unsigned int leng = *((unsigned int*) &valuep[dp->data]);
#if WORDS_BIGENDIAN
		be2leui(&leng);
#endif
		op->val.s = malloc(1 + leng);
		if (!op->val.s)
		{
			fprintf(stderr, "%s: Can't allocate string!\n", MyName);
			return 0;
		}
		memcpy(op->val.s, (char*) &valuep[dp->data + sizeof (int)], leng);
		op->val.s[leng] = '\0';
		break;
	}
	case t_resref:
	{
		unsigned int leng = *((unsigned char*) &valuep[dp->data]);
		if (leng > 16)
		{
			fprintf(stderr, "%s: RR > 16 chars: [%-*.*s]!\n",
				MyName, leng, leng, &valuep[dp->data + sizeof (char)]);
			abort();
		}
		memset(op->val.rr, '\0', sizeof op->val.rr);
		memcpy(op->val.rr, &valuep[dp->data + sizeof (char)], leng);
		break;
	}
	case t_locstr:
	{
		struct nwn_itp_slist* slp = (struct nwn_itp_slist*) &valuep[dp->data];
		unsigned long count = slp->count;

#if WORDS_BIGENDIAN
		be2leul(&count);
#endif
		op->val.locstr.strref = slp->strref;
		op->val.locstr.strs = vnew(count);
		if (count > 0)
		{
			int i;
			struct nwn_object_locstr_strs* lsp;
			char* cp = (char*) (slp + 1);

			for (i = 0; i < count; ++i)
			{
				int leng;

				lsp = malloc(sizeof *lsp);
				if (!lsp)
				{
					fprintf(stderr, "%s: Can't allocate a locstr!\n", MyName);
					return 0;
				}
				lsp->lang = *((int*) cp);
#if WORDS_BIGENDIAN
				be2lei(&lsp->lang);
#endif
				cp += sizeof (int);
				leng = *((int*) cp);
#if WORDS_BIGENDIAN
				be2lei(&leng);
#endif
				cp += sizeof (int);
				lsp->str = malloc(1 + leng);
				if (!lsp->str)
				{
					fprintf(stderr, "%s: Can't allocate locstr string!\n", MyName);
					return 0;
				}
				strncpy(lsp->str, cp, leng);
				lsp->str[leng] = '\0';
				cp += leng;
				vapp(op->val.locstr.strs, lsp);
			}
		}
		break;
	}
	case t_datref:
	{
		int leng = *((int*) &valuep[dp->data]);
#if WORDS_BIGENDIAN
		be2lei(&leng);
#endif
		op->val.blob.len = leng;
		op->val.blob.data = malloc(leng);
		if (!op->val.blob.data)
		{
			fprintf(stderr, "%s: Can't allocate blob!\n", MyName);
			return 0;
		}
		memcpy(op->val.blob.data, &valuep[dp->data + sizeof (int)], leng);
		break;
	}
	case t_capref:
	{
		struct nwn_itp_list* lp = &listp[dp->data];

		op->val.rec.code = lp->code;
		op->val.rec.v = vnew(lp->count);
		if (lp->count)
		{
			if (lp->count == 1)
				vapp(op->val.rec.v, decode_data(lp->index));
			else
			{
				int* rp = &rootp[lp->index / sizeof (int)];

				for (i = 0; i < lp->count; ++i)
					vapp(op->val.rec.v, decode_data(rp[i]));
			}
		}
		break;
	}
	case t_list:
	{
		int* ip = &indexp[dp->data / sizeof (int)];
		int leng = *ip++;

		op->val.rec.v = vnew(leng);
		if (leng)
		{
			for (i = 0; i < leng; ++i)
			{
				struct nwn_itp_list* lp = &listp[ip[i]];
				int* rp = &rootp[lp->index / sizeof (int)];
				struct nwn_object_record* recp = malloc(sizeof *recp);

				if (!recp)
				{
					fprintf(stderr, "%s: Can't allocate recp!\n", MyName);
					return 0;
				}
				recp->code = lp->code;
				recp->v = vnew(lp->count);
				if (lp->count == 1)
					vapp(recp->v, decode_data(lp->index));
				else
				{
					int j;

					for (j = 0; j < lp->count; ++j)
						vapp(recp->v, decode_data(rp[j]));
				}
				vapp(op->val.rec.v, recp);
			}
		}
	}
	}
	return op;
}

struct nwn_object_locstr copy_locstrs(struct nwn_object_locstr src)
{
	struct nwn_object_locstr r;
	struct nwn_object_locstr_strs* olp;
	struct nwn_object_locstr_strs* nlp;
	int j;

	r.strref = src.strref;
	r.strs = vnew(vlen(src.strs));
	for (j = 0; j < vlen(src.strs); ++j)
	{
		olp = vsubig(src.strs, j);
		nlp = malloc(sizeof *nlp);
		if (!nlp)
		{
			fprintf(stderr, "%s: Can't reallocate locstr!\n", MyName);
			nwvfree(r.strs);
			r.strs = 0;
			r.strref = -1;
			return r;
		}
		nlp->lang = olp->lang;
		nlp->str = strdup(olp->str);
		vapp(r.strs, nlp);
	}
	return r;
}

/* Convert plist to binary itp data and return the binary itp data.  Returned
 *  storage comes from malloc() so free it when you are done.  The number of
 *  bytes returned is stored in <size>.  <sig> and <ver> are the signature and
 *  version to write into the itp header, see the GFF specification
 *  (forthcoming from Bioware, supposedly) for more information on that */
struct nwn_itp		header;
struct nwn_itp_list	*entry_table=NULL;

char		*cvt_from_plist( int *size, struct v* v, char *sig, char *ver )
{
	/* Ensure sanity */
	assert( v && "NULL v!" );
	assert( size && "NULL size!" );
	*size = 0;
	if( strlen(sig) != 4 )
	{
		fprintf( stderr, "cvt_from_plist(): sig must be 4 characters\n" );
		return NULL;
	}
	if( strlen(ver) != 4 )
	{
		fprintf( stderr, "cvt_from_plist(): ver must be 4 characters\n" );
		return NULL;
	}

	/* Fill in part of header for later use */
	memset( &header, 0, sizeof(struct nwn_itp) );
	strncpy( header.signature, sig, 4 );
	strncpy( header.version, ver, 4 );
	
	/* Well, I got started anyway.  More later. */
	add_entry( &header, handle_entry(v) );

	return NULL;
}

/* The handle_* functions handle the byteswapping, not the add_* functions */
static void		add_entry( struct nwn_itp *header, struct nwn_itp_list *entry )
{
	if( !entry_table )
	{
		entry_table = malloc( sizeof(struct nwn_itp_list) );
		assert( entry_table );
#warning not finished
	}
}

static struct nwn_itp_list	*handle_entry( struct v *v )
{
	return NULL;
}

struct gffresc
{
	struct v* sv;	// (struct nwn_itp_list*); BioWare: "Struct"
	struct v* lv;	// (struct nwn_itp_tag*); BioWare: "Label"
	struct v* dv;	// (struct nwn_itp_data*); BioWare: "Field"
	struct v* fia;	// (long); BioWare: "Field Index Array"
	struct exmem* fdbv;	// (Field Data Block: byte array)
};

static int plist2resc1obj(struct gffresc* gffresc, struct nwn_object* o);

void* plist2resc(struct v* vp, int* size)
{
	int i;
	struct gffresc gffresc;
	struct nwn_itp_list* s;

	gffresc.sv = vnew(1);
	gffresc.lv = vnew(0);
	gffresc.dv = vnew(0);
	gffresc.fdbv = exmem_new(0);

	// clear this so we can return NULL for any errors
	*size = 0;

	// allocate Struct 0
	s = malloc(sizeof *s);
	if (!s)
	{
		fprintf(stderr, "%s: Can't allocate plist struct[0]!\n", MyName);
		return 0;
	}

	// initialize 1st element
	s->code = -1;		// special for Struct[0]
	s->index = 0;		// 1st available location
	s->count = vlen(vp);	// # of fields

	// append it to vector
	vapp(gffresc.sv, s);

	// loop through elements
	for (i = 0; i < vlen(vp); ++i)
	{
		struct nwn_object* o = vsubig(vp, i);

		if (plist2resc1obj(&gffresc, o))
			return 0;
	}
}

static int plist2resc1obj(struct gffresc* gffresc, struct nwn_object* o)
{
	struct nwn_itp_tag* t = malloc(sizeof *t);
	struct nwn_itp_data* d = malloc(sizeof *d);

	if (!t)
	{
		fprintf(stderr, "%s: Can't allocate Label!\n", MyName);
		return 0;
	}
	// clear memory
	memset(t, 0, sizeof *t);
	// fill in value
	strncpy(t->name, o->name, sizeof t->name);
	vapp(gffresc->lv, t);

	if (!d)
	{
		fprintf(stderr, "%s: Can't allocate Field!\n", MyName);
		return 0;
	}
	// clear memory
	memset(d, 0, sizeof *d);
	// fill in values
	d->type = o->type;
	d->index = vlen(gffresc->lv);
	// append the field now; we may recurse below
	vapp(gffresc->dv, d);
	// where to store it depends on type
	switch (d->type)
	{
	// these are all simple objects, stored in d->data
	case t_uint8:
		d->data = o->val.ui8;
		break;

	case t_int8:
		d->data = o->val.si8;
		break;

	case t_uint16:
		d->data = o->val.ui16;
		break;

	case t_int16:
		d->data = o->val.si16;
		break;

	case t_uint32:
		d->data = o->val.ui32;
		break;

	case t_int32:
		d->data = o->val.si32;
		break;

	case t_float:
		// cheat
		d->data = o->val.ui32;
		break;

	// these are complex, stored in the field data block
	case t_uint64:
		d->data = exmem_len(gffresc->fdbv);
		exmem_push(gffresc->fdbv, (char*) &o->val.ui64, sizeof o->val.ui64);
		break;

	case t_int64:
		d->data = exmem_len(gffresc->fdbv);
		exmem_push(gffresc->fdbv, (char*) &o->val.si64, sizeof o->val.si64);
		break;

	case t_double:
		d->data = exmem_len(gffresc->fdbv);
		exmem_push(gffresc->fdbv, (char*) &o->val.d, sizeof o->val.d);
		break;

	case t_string:	// CExoString
	{
		int sl = strlen(o->val.s);

		d->data = exmem_len(gffresc->fdbv);
		exmem_push(gffresc->fdbv, (char*) &sl, sizeof sl);
		exmem_push(gffresc->fdbv, o->val.s, sl);
		break;
	}

	case t_resref:
	{
		char buf[17];

		buf[0] = strlen(o->val.s);
		strncpy(&buf[1], o->val.s, buf[0]);
		d->data = exmem_len(gffresc->fdbv);
		exmem_push(gffresc->fdbv, &buf[0], buf[0] + 1);
		break;
	}

	case t_locstr:	// CExoLocString
	{
		int k = 0;

		d->data = exmem_len(gffresc->fdbv);
		exmem_push(gffresc->fdbv, (char*) &k, sizeof k);	//placeholder for total size
		exmem_push(gffresc->fdbv, (char*) &o->val.locstr.strref, sizeof o->val.locstr.strref);
		k = vlen(o->val.locstr.strs);
		exmem_push(gffresc->fdbv, (char*) &k, sizeof k);
		for (k = 0; k < vlen(o->val.locstr.strs); ++k)
		{
			struct nwn_object_locstr_strs* str = vsubig(o->val.locstr.strs, k);
			int len = strlen(str->str);

			exmem_push(gffresc->fdbv, (char*) &str->lang, sizeof str->lang);
			exmem_push(gffresc->fdbv, (char*) &len, sizeof len);
			exmem_push(gffresc->fdbv, str->str, len);
		}
		// fill in total size
		*(int*)(&gffresc->fdbv->mem[d->data]) = exmem_len(gffresc->fdbv) - d->data;
		break;
	}

	case t_datref:	// blob, Void
		d->data = exmem_len(gffresc->fdbv);
		exmem_push(gffresc->fdbv, (char*) &o->val.blob.len, sizeof o->val.blob.len);
		exmem_push(gffresc->fdbv, o->val.blob.data, o->val.blob.len);
		break;

	// these are even more complex, and get stored in other sections, to boot
	case t_capref:	// Struct
	{
		int k;
		struct nwn_itp_list* s;

		d->data = vlen(gffresc->sv);

		// allocate Struct
		s = malloc(sizeof *s);
		if (!s)
		{
			fprintf(stderr, "%s: Can't allocate plist struct!\n", MyName);
			return 0;
		}

		// append it to Struct array
		vapp(gffresc->sv, s);

		// initialize it
		s->code = o->val.rec.code;
		s->count = vlen(o->val.rec.v);	// # of fields
		if (s->count > 1)
			s->index = vlen(gffresc->fia);
		else
			s->index = vlen(gffresc->dv);

		// we need to recurse for each member
		// FIXME: how do we say "use Field Index Array" vs. "use Field Array"?
		if (s->count == 1)
			plist2resc1obj(gffresc, vsubig(o->val.rec.v, 0));
		else
		{
			for (k = 0; k < s->count; ++k)
			{
				struct nwn_object* co = vsubig(o->val.rec.v, k);

				plist2resc1obj(gffresc, co);
			}
		}
		break;
	}

	case t_list:
		// we need to recurse for each list element
		break;
	}
}
