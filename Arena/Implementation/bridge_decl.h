PRIVATE HTTabStop tabs_8[] = {
	{ 0, 8 }, {0, 16}, {0, 24}, {0, 32}, {0, 40},
	{ 0, 48 }, {0, 56}, {0, 64}, {0, 72}, {0, 80},
	{ 0, 88 }, {0, 96}, {0, 104}, {0, 112}, {0, 120},
	{ 0, 128 }, {0, 136}, {0, 144}, {0, 152}, {0, 160},
	{0, 168}, {0, 176},
	{0, 0 }		/* Terminate */
};

PRIVATE HTTabStop tabs_24[] = {
	{0, 24}, {0, 48},		/* 3 columns */
	{0, 0 }		/* Terminate */
};

PRIVATE HTStyle HTStyleNormal = { 0,  "Normal", "P",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	4, 4, 0, HT_LEFT,		1, 0,	tabs_8,
	YES, YES, 1, 1,			0 };	

PRIVATE HTStyle HTStyleList = { &HTStyleNormal,  "List", "UL",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	8, 12, 0, HT_LEFT,		1, 0,	0,
	YES, YES, 1, 1,			0 };	

PRIVATE HTStyle HTStyleMenu = {
	&HTStyleList,  "Menu", "MENU",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	4, 4, 0, HT_LEFT,		1, 0,	0,
	YES, YES, 0, 0,			0
};

PRIVATE HTStyle HTStyleDirect = {
	&HTStyleMenu,  "Dir", "DIR",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	0, 0, 0, HT_LEFT,		1, 0,	tabs_24,
	YES, YES, 0, 0,			0
};	

PRIVATE HTStyle HTStyleGlossary = {
	&HTStyleDirect,  "Glossary", "DL",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	4, 10, 0, HT_LEFT,		1, 0,	0, 
	YES, YES, 1, 1,			0
};	
PRIVATE HTStyle HTStyleGlossaryCompact = {
	&HTStyleGlossary,  "GlossaryCompact", "DLC",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	4, 10, 0, HT_LEFT,		1, 0,	0, 
	YES, YES, 0, 0,			0
};
PRIVATE HTStyle HTStyleExample =
	{ &HTStyleGlossaryCompact,  "Example", "XMP",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	0, 0, 0, HT_LEFT,		1, 0,	tabs_8,
	NO, NO, 1, 1,			0
};	

PRIVATE HTStyle HTStylePreformatted =
	{ &HTStyleExample,  	"Preformatted", "PRE",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	4, 4, 0, HT_LEFT,		1, 0,	tabs_8,
	NO, YES, 1, 1,			0
};	

PRIVATE HTStyle HTStyleListing =
	{ &HTStylePreformatted,  "Listing", "LISTING",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	0, 0, 0, HT_LEFT,		1, 0,	tabs_8,
	NO, NO, 1, 1,			0 };	

PRIVATE HTStyle HTStyleAddress =
	{ &HTStyleListing,  "Address", "ADDRESS",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	4, 6, 0, HT_LEFT,		1, 0,	0,
	NO, NO, 0, 0,			0 };	

PRIVATE HTStyle HTStyleBlockQuote =
	{ &HTStyleAddress,  "BlockQuote", "BLOCKQUOTE",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	12, 8, 8, HT_LEFT,		1, 0,	0,
	NO, NO, 1, 1,			0 };	

PRIVATE HTStyle HTStyleHeading1 =
	{ &HTStyleBlockQuote,  "Heading1", "H1",
	HT_FONT+HT_CAPITALS+HT_BOLD, 1.0, HT_BLACK,		0, 0,
	0, 0, 0, HT_LEFT,		1, 0,	0,
	YES, YES, 1, 1,			0 };	

PRIVATE HTStyle HTStyleHeading2 =
	{ &HTStyleHeading1,  "Heading2", "H2",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	0, 0, 0, HT_LEFT,		1, 0,	0,
	YES, YES, 1, 1,			0 };	

PRIVATE HTStyle HTStyleHeading3 = { &HTStyleHeading2,  "Heading3", "H3",
	HT_FONT+HT_CAPITALS, 1.0, HT_BLACK,		0, 0,
	2, 2, 0, HT_LEFT,		1, 0,	0, 
	YES, YES, 1, 0,			0 };	

PRIVATE HTStyle HTStyleHeading4 = { &HTStyleHeading3,  "Heading4", "H4",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	2, 2, 0, HT_LEFT,		1, 0,	0,
	YES, YES, 1, 0,			0 };	

PRIVATE HTStyle HTStyleHeading5 = { &HTStyleHeading4,  "Heading5", "H5",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	2, 2, 0, HT_LEFT,		1, 0,	0,
	YES, YES, 1, 0,			0 };	

PRIVATE HTStyle HTStyleHeading6 = { &HTStyleHeading5,  "Heading6", "H6",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	2, 2, 0, HT_LEFT,		1, 0,	0,
	YES, YES, 1, 0,			0 };	

PRIVATE HTStyle HTStyleHeading7 = { &HTStyleHeading6,  "Heading7", "H7",
	HT_FONT, 1.0, HT_BLACK,		0, 0,
	2, 2, 0, HT_LEFT,		1, 0,	0,
	YES, YES, 1, 0,			0 };	

/* Style sheet points to the last in the list:
*/
PRIVATE HTStyleSheet sheet = { "default.style", &HTStyleHeading7 }; /* sheet */

PUBLIC HTStyleSheet * styleSheet = &sheet;

/*PUBLIC HTStyleSheet * styleSheet = NULL; */
