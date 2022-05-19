#define	GUI_SIGNATURE	"GUI "
#define	GUI_VERSION		"V3.2"

struct nwn_gui_caption
{
	float AurString_AlignV;
	float AurString_ColorR;
	float AurString_ColorG;
	float AurString_ColorB;
	char AurString_Font[16];
	float AurString_AlignH;
	float AurString_ColorA;
	unsigned long Obj_StrRef;
	char* AurString_Text;
};

struct nwn_gui_child_2
{
	long Obj_Type;
	float Obj_X;
	float Obj_Y;
	float Obj_Z;
	char* Obj_Tag;
	unsigned char Obj_Locked;
	long Obj_Layer;
	char Obj_ResRef[16];
	char* Obj_Parent;
	char* Obj_Parent_Hook;
	unsigned char Obj_Checked;
	struct v* Obj_ChildList;	//struct nwn_gui*
};

struct nwn_gui_child_5
{
	long Obj_Type;
	long Obj_Layer;
	float Obj_Label_X;
	float Obj_Label_Y;
	float Obj_Label_Z;
	char* Obj_Tag;
	char* Obj_Parent_Hook;
	unsigned char Obj_Locked;
	struct nwn_gui_caption Obj_Caption;
	char* Obj_Parent;
	float Obj_Label_Height;
	float Obj_Label_Width;
};

struct nwn_gui_child_6
{
	long Obj_Type;
	long Obj_Layer;
	float Obj_X;
	float Obj_Y;
	float Obj_Z;
	char* Obj_Tag;
	char* Obj_Parent_Hook;
	unsigned char Obj_Locked;
	char Obj_ResRef[16];
	char* Obj_Parent;
	float Obj_Length;
	struct v* Obj_ChildList;	//struct nwn_gui*
};

struct nwn_gui_child_9
{
	long Obj_Type;
	long Obj_Layer;
	float Obj_X;
	float Obj_Y;
	float Obj_Z;
	char* Obj_Tag;
	char* Obj_Parent_Hook;
	unsigned char Obj_Locked;
	struct nwn_gui_caption Obj_Caption;
	char* Obj_Parent;
	char Obj_ResRef[16];
};

struct nwn_gui
{
	long Obj_Type;
	long Obj_Layer;
	float Obj_X;
	float Obj_Y;
	float Obj_Z;
	char* Obj_Tag;
	char* Obj_Parent_Hook;
	unsigned char Obj_Locked;
	struct v* Obj_ChildList;	//struct nwn_gui*
	long Obj_NumTags;
	char Obj_ResRef[16];
};
