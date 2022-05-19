#include	"v.h"

#define	UTI_SIGNATURE	"UTI "
#define	UTI_VERSION		"V3.2"

struct nwn_uti_properties
{
	int Code;
	unsigned short PropertyName;
	unsigned short Subtype;
	unsigned short CostValue;
	unsigned char Param1;
	unsigned char Param1Value;
	unsigned char ChanceAppear;
	unsigned char CostTable;
};

struct nwn_uti
{
	long BaseItem;
	struct v* LocalizedName;	//locstrs
	struct v* Description;	//locstrs
	struct v* DescIdentified;	//locstrs
	struct v* PropertiesList;	//struct nwn_uti_properties*
	char* Tag;
	char* Comment;
	char TemplateResRef[16];
	unsigned long Cost;
	unsigned long AddCost;
	unsigned short StackSize;
	unsigned char ArmorPart_Belt;
	unsigned char ArmorPart_LBicep;
	unsigned char ArmorPart_LFArm;
	unsigned char ArmorPart_LFoot;
	unsigned char ArmorPart_LHand;
	unsigned char ArmorPart_LShin;
	unsigned char ArmorPart_LShoul;
	unsigned char ArmorPart_LThigh;
	unsigned char ArmorPart_Neck;
	unsigned char ArmorPart_Pelvis;
	unsigned char ArmorPart_RBicep;
	unsigned char ArmorPart_RFArm;
	unsigned char ArmorPart_RFoot;
	unsigned char ArmorPart_RHand;
	unsigned char ArmorPart_RShin;
	unsigned char ArmorPart_RShoul;
	unsigned char ArmorPart_RThigh;
	unsigned char ArmorPart_Torso;
	unsigned char Charges;
	unsigned char Cloth1Color;
	unsigned char Cloth2Color;
	unsigned char Identified;
	unsigned char Leather1Color;
	unsigned char Leather2Color;
	unsigned char Metal1Color;
	unsigned char Metal2Color;
	unsigned char ModelPart1;
	unsigned char ModelPart2;
	unsigned char ModelPart3;
	unsigned char PaletteID;
	unsigned char Plot;
	unsigned char Stolen;
};
