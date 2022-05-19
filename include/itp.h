#ifndef _itp_h_
#define _itp_h_

/*
** the resource header for an ITP resource
*/
#pragma pack(1)
struct nwn_itp
{
	char			signature[4];
	char			version[4];
	long oList;		/* offset */
	long cList;		/* count */
	long oData;		/* offset */
	long cData;		/* count */
	long oTag;		/* tags offset */
	long cTag;		/* tags count */
	long oValue;	/* values offset */
	long cValue;	/* values count */
	long oRoot;		/* offset */
	long cRoot;		/* count */
	long oIndex;	/* offset */
	long cIndex;	/* count */
};
#pragma pack()

#pragma pack(1)
struct nwn_itp_list
{
	long code;
	long index;
	long count;
};
#pragma pack()

#pragma pack(1)
struct nwn_itp_data
{
	long type;
	long index;
	long data;
};
#pragma pack()

#pragma pack(1)
struct nwn_itp_tag
{
	char name[16];
};
#pragma pack()

#pragma pack(1)
struct nwn_itp_slist
{
	long size;
	long strref;
	long count;
};
#pragma pack()

#define	NWN_ITP_SIGNATURE	"ITP "
#define	NWN_ITP_VERSION		"V3.2"

enum nwn_itp_typecode
{
	t_uint8,
	t_int8,
	t_uint16,
	t_int16,
	t_uint32,
	t_int32,
	t_uint64,
	t_int64,
	t_float,
	t_double,
	t_string,
	t_resref,
	t_locstr,
	t_datref,
	t_capref,
	t_list
};

typedef enum nwn_itp_typecode TypeCode;

#endif
