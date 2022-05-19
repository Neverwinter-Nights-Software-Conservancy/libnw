#include	"v.h"
#include	"object.h"

#define	DLG_SIGNATURE	"DLG "
#define	DLG_VERSION		"V3.2"

struct nwn_dlg_reply_entry
{
	int Code;
	unsigned long Index;
	char Active[16];
	unsigned char IsChild;
	char* LinkComment;
};

struct nwn_dlg_reply
{
	int Code;
	unsigned long Delay;
	unsigned long Animation;
	unsigned long QuestEntry;
	unsigned char AnimLoop;
	char* Comment;
	char* Quest;
	char Sound[16];
	char Script[16];
	struct v* EntriesList;	//struct nwn_dlg_reply_entry
	struct nwn_object_locstr Text;
};

struct nwn_dlg_start
{
	int Code;
	unsigned long Index;
	char Active[16];
};

struct nwn_dlg_entry_reply
{
	int Code;
	unsigned long Index;
	char Active[16];
	unsigned char IsChild;
	char* LinkComment;
};

struct nwn_dlg_entry
{
	int Code;
	unsigned long Delay;
	unsigned long Animation;
	unsigned long QuestEntry;
	unsigned char AnimLoop;
	char* Comment;
	char* Quest;
	char* Speaker;
	char Script[16];
	char Sound[16];
	struct nwn_object_locstr Text;
	struct v* RepliesList;	//struct nwn_dlg_entry_reply
};

struct nwn_dlg
{
	unsigned long DelayEntry;
	unsigned long DelayReply;
	unsigned long NumWords;
	unsigned char PreventZoomIn;
	char EndConversation[16];
	char EndConverAbort[16];
	struct v* EntryList;	//struct nwn_dlg_entry
	struct v* ReplyList;	//struct nwn_dlg_reply
	struct v* StartingList;	//struct nwn_dlg_start
};

extern struct nwn_dlg* plist2dlg(struct v* pp);
