#include	"v.h"

#define	FAC_SIGNATURE	"FAC "
#define	FAC_VERSION		"V3.2"

struct nwn_fac_faction
{
	int Code;
	char* FactionName;
	unsigned long FactionParentID;
	unsigned short FactionGlobal;
};

struct nwn_fac_rep
{
	int Code;
	unsigned long FactionID1;
	unsigned long FactionID2;
	unsigned long FactionRep;
};

struct nwn_fac
{
	struct v* FactionList;	//struct nwn_fac_faction
	struct v* RepList;	//struct nwn_fac_rep
};
