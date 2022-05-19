#define	JRL_SIGNATURE	"JRL "
#define	JRL_VERSION		"V3.2"

struct nwn_jrl_categories_entrylist
{
	int Code;
	unsigned long ID;
	unsigned short End;
	struct v* Text;	//locstrs
};

struct nwn_jrl_categories
{
	int Code;
	struct v* Name;	//locstrs
	unsigned long XP;
	unsigned long Priority;
	unsigned short Picture;
	char* Comment;
	char* Tag;
	struct v* EntryList;	//struct nwn_jrl_categories_entrylist
};

struct nwn_jrl
{
	struct v* Categories;	//?
};
