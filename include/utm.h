#define	UTM_SIGNATURE	"UTM "
#define	UTM_VERSION		"V3.2"

struct nwn_utm_storelist_itemlist
{
	int Code;
	char InventoryRes[16];
	unsigned short Repos_PosX;
	unsigned short Repos_Posy;
};

struct nwn_utm_storelist
{
	int Code;
	struct v* ItemList;	//struct nwn_utm_storelist_itemlist
};

struct nwn_utm
{
	char ResRef[16];
	long MarkDown;
	long MarkUp;
	char OnOpenStore[16];
	unsigned char BlackMarket;
	char* Tag;
	unsigned char ID;
	char* Comment;
	long BM_MarkDown;
	struct v* StoreList;	//struct nwn_utm_storelist
	struct v* LocName;	//locstrs
};
