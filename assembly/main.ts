
declare function block(pos:i32, len:i32):void;

const AES_SUB_BOX:i32 =		0;

const AES_T1:i32 =			256; // AES_SUB_BOX + 256
const AES_T2:i32 =			1280; // AES_T1 + 256 * 4
const AES_T3:i32 =			2304; // AES_T2 + 256 * 4
const AES_T4:i32 =			3328; // AES_T3 + 256 * 4

const KECCAK_RNDC:i32 =		4352; // AES_T4 + 256 * 4

const BLAKE_SIGMA:i32 =		4544; // KECCAK_RNDC + 192
const BLAKE_CST:i32 =		4768; // BLAKE_SIGMA + 224
const JH_E8:i32 =			4832; // BLAKE_CST + 64
const JH_SWAP:i32 =			6176; // JH_E8 + 1344
const GROSTL_T0:i32 =		6288; // JH_SWAP + 112
const GROSTL_T1:i32 =		8336; // GROSTL_T0 + 2048
const GROSTL_T2:i32 =		10384; // GROSTL_T1 + 2048
const GROSTL_T3:i32 =		12432; // GROSTL_T2 + 2048
const GROSTL_T4:i32 =		14480; // GROSTL_T3 + 2048
const GROSTL_T5:i32 =		16528; // GROSTL_T4 + 2048
const GROSTL_T6:i32 =		18576; // GROSTL_T5 + 2048
const GROSTL_T7:i32 =		20624; // GROSTL_T6 + 2048

const DATA:i32 =			22672; // GROSTL_T7 + 2048

const AES_KEY:i32 =			22672; // DATA

const TEXT_POS:i32 =		22672; // DATA
const TEXT_KEC:i32 =		22872; // TEXT_POS + 200

const LONG_TEXT_POS:i32 =	22912; // TEXT_POS + 240
const LONG_TEXT_END:i32 =	2120064; // LONG_TEXT_POS + ( 1 << 21 )

const BLAKE_M:i32 =			22928; // TEXT_KEC + 56

{ // INIT

	// alloc memory
	grow_memory( LONG_TEXT_END >>> 16 );

	var x:i32;
	var y:i32;
	var z:i32;
	var i:i32;
	var t:i32;

	var v:i64;

	// compute double table
	i = 0;
	do { store<u8>( i, (   i << 1            ) as u8, AES_T1 ) } while ( ++i < 128 );
	do { store<u8>( i, ( ( i << 1 ) ^ 0x011B ) as u8, AES_T1 ) } while ( ++i < 256 );

	// compute aes box
	x = 1;
	i = 1;
	store<u8>( AES_SUB_BOX, 0x63 );
	do {

		t = x ^ ( x << 1 ) ^ ( x << 2 ) ^ ( x << 3 ) ^ ( x << 4 );
		store<u8>( i, ( ( t >>> 8 ) ^ ( t & 0xFF ) ^ 0x63 ) as u8, AES_SUB_BOX );

		i  = load<u8>( i, AES_T1 );
		i ^= load<u8>( load<u8>( load<u8>( load<u8>( load<u8>( i, AES_T1 ), AES_T1 ) ^ i, AES_T1 ), AES_T1 ), AES_T1 );
		x ^= load<u8>( load<u8>( x, AES_T1 ), AES_T1 );

	} while ( i != 1 );

	// compute aes tables
	i = 0;
	do {

		x = load<u8>( i, AES_SUB_BOX );
		y = ( x << 1 ) ^ ( ( ( x >>> 7 ) & 1 ) * 0x011B );
		z = y ^ x;
		t = i << 2;

		store<i32>( t, ( z << 24 ) | ( x << 16 ) | ( x << 8 ) | ( y ), AES_T1 );
		store<i32>( t, ( x << 24 ) | ( x << 16 ) | ( y << 8 ) | ( z ), AES_T2 );
		store<i32>( t, ( x << 24 ) | ( y << 16 ) | ( z << 8 ) | ( x ), AES_T3 );
		store<i32>( t, ( y << 24 ) | ( z << 16 ) | ( x << 8 ) | ( x ), AES_T4 );

	} while ( ++i < 256 );

	// compute keccak rndc
	store<i64>( KECCAK_RNDC +   0, 0x0000000000000001 );
	store<i64>( KECCAK_RNDC +   8, 0x0000000000008082 );
	store<i64>( KECCAK_RNDC +  16, 0x800000000000808A );
	store<i64>( KECCAK_RNDC +  24, 0x8000000080008000 );
	store<i64>( KECCAK_RNDC +  32, 0x000000000000808B );
	store<i64>( KECCAK_RNDC +  40, 0x0000000080000001 );
	store<i64>( KECCAK_RNDC +  48, 0x8000000080008081 );
	store<i64>( KECCAK_RNDC +  56, 0x8000000000008009 );
	store<i64>( KECCAK_RNDC +  64, 0x000000000000008A );
	store<i64>( KECCAK_RNDC +  72, 0x0000000000000088 );
	store<i64>( KECCAK_RNDC +  80, 0x0000000080008009 );
	store<i64>( KECCAK_RNDC +  88, 0x000000008000000A );
	store<i64>( KECCAK_RNDC +  96, 0x000000008000808B );
	store<i64>( KECCAK_RNDC + 104, 0x800000000000008B );
	store<i64>( KECCAK_RNDC + 112, 0x8000000000008089 );
	store<i64>( KECCAK_RNDC + 120, 0x8000000000008003 );
	store<i64>( KECCAK_RNDC + 128, 0x8000000000008002 );
	store<i64>( KECCAK_RNDC + 136, 0x8000000000000080 );
	store<i64>( KECCAK_RNDC + 144, 0x000000000000800A );
	store<i64>( KECCAK_RNDC + 152, 0x800000008000000A );
	store<i64>( KECCAK_RNDC + 160, 0x8000000080008081 );
	store<i64>( KECCAK_RNDC + 168, 0x8000000000008080 );
	store<i64>( KECCAK_RNDC + 176, 0x0000000080000001 );
	store<i64>( KECCAK_RNDC + 184, 0x8000000080008008 );

	// compute blake sigma
	store<i64>( BLAKE_SIGMA +   0, 0x0706050403020100 << 2 ); store<i64>( BLAKE_SIGMA +   8, 0x0F0E0D0C0B0A0908 << 2 );
	store<i64>( BLAKE_SIGMA +  16, 0x060D0F0908040A0E << 2 ); store<i64>( BLAKE_SIGMA +  24, 0x0305070B02000C01 << 2 );
	store<i64>( BLAKE_SIGMA +  32, 0x0D0F0205000C080B << 2 ); store<i64>( BLAKE_SIGMA +  40, 0x0409010706030E0A << 2 );
	store<i64>( BLAKE_SIGMA +  48, 0x0E0B0C0D01030907 << 2 ); store<i64>( BLAKE_SIGMA +  56, 0x080F00040A050602 << 2 );
	store<i64>( BLAKE_SIGMA +  64, 0x0F0A040207050009 << 2 ); store<i64>( BLAKE_SIGMA +  72, 0x0D0308060C0B010E << 2 );
	store<i64>( BLAKE_SIGMA +  80, 0x03080B000A060C02 << 2 ); store<i64>( BLAKE_SIGMA +  88, 0x09010E0F05070D04 << 2 );
	store<i64>( BLAKE_SIGMA +  96, 0x0A040D0E0F01050C << 2 ); store<i64>( BLAKE_SIGMA + 104, 0x0B08020903060700 << 2 );
	store<i64>( BLAKE_SIGMA + 112, 0x0903010C0E070B0D << 2 ); store<i64>( BLAKE_SIGMA + 120, 0x0A020608040F0005 << 2 );
	store<i64>( BLAKE_SIGMA + 128, 0x0800030B090E0F06 << 2 ); store<i64>( BLAKE_SIGMA + 136, 0x050A0401070D020C << 2 );
	store<i64>( BLAKE_SIGMA + 144, 0x050106070408020A << 2 ); store<i64>( BLAKE_SIGMA + 152, 0x000D0C030E090B0F << 2 );
	store<i64>( BLAKE_SIGMA + 160, 0x0706050403020100 << 2 ); store<i64>( BLAKE_SIGMA + 168, 0x0F0E0D0C0B0A0908 << 2 );
	store<i64>( BLAKE_SIGMA + 176, 0x060D0F0908040A0E << 2 ); store<i64>( BLAKE_SIGMA + 184, 0x0305070B02000C01 << 2 );
	store<i64>( BLAKE_SIGMA + 192, 0x0D0F0205000C080B << 2 ); store<i64>( BLAKE_SIGMA + 200, 0x0409010706030E0A << 2 );
	store<i64>( BLAKE_SIGMA + 208, 0x0E0B0C0D01030907 << 2 ); store<i64>( BLAKE_SIGMA + 216, 0x080F00040A050602 << 2 );

	// compute blake cst
	store<i64>( BLAKE_CST +  0, 0x85A308D3243F6A88 ); store<i64>( BLAKE_CST +  8, 0x0370734413198A2E );
	store<i64>( BLAKE_CST + 16, 0x299F31D0A4093822 ); store<i64>( BLAKE_CST + 24, 0xEC4E6C89082EFA98 );
	store<i64>( BLAKE_CST + 32, 0x38D01377452821E6 ); store<i64>( BLAKE_CST + 40, 0x34E90C6CBE5466CF );
	store<i64>( BLAKE_CST + 48, 0xC97C50DDC0AC29B7 ); store<i64>( BLAKE_CST + 56, 0xB54709173F84D5B5 );

	// compute jh e8
	store<i64>( JH_E8 +    0, 0x67F815DFA2DED572 ); store<i64>( JH_E8 +    8, 0x571523B70A15847B );
	store<i64>( JH_E8 +   16, 0xF6875A4D90D6AB81 ); store<i64>( JH_E8 +   24, 0x402BD1C3C54F9F4E );
	store<i64>( JH_E8 +   32, 0x9CFA455CE03A98EA ); store<i64>( JH_E8 +   40, 0x9A99B26699D2C503 );
	store<i64>( JH_E8 +   48, 0x8A53BBF2B4960266 ); store<i64>( JH_E8 +   56, 0x31A2DB881A1456B5 );
	store<i64>( JH_E8 +   64, 0xDB0E199A5C5AA303 ); store<i64>( JH_E8 +   72, 0x1044C1870AB23F40 );
	store<i64>( JH_E8 +   80, 0x1D959E848019051C ); store<i64>( JH_E8 +   88, 0xDCCDE75EADEB336F );
	store<i64>( JH_E8 +   96, 0x416BBF029213BA10 ); store<i64>( JH_E8 +  104, 0xD027BBF7156578DC );
	store<i64>( JH_E8 +  112, 0x5078AA3739812C0A ); store<i64>( JH_E8 +  120, 0xD3910041D2BF1A3F );
	store<i64>( JH_E8 +  128, 0x907ECCF60D5A2D42 ); store<i64>( JH_E8 +  136, 0xCE97C0929C9F62DD );
	store<i64>( JH_E8 +  144, 0xAC442BC70BA75C18 ); store<i64>( JH_E8 +  152, 0x23FCC663D665DFD1 );
	store<i64>( JH_E8 +  160, 0x1AB8E09E036C6E97 ); store<i64>( JH_E8 +  168, 0xA8EC6C447E450521 );
	store<i64>( JH_E8 +  176, 0xFA618E5DBB03F1EE ); store<i64>( JH_E8 +  184, 0x97818394B29796FD );
	store<i64>( JH_E8 +  192, 0x2F3003DB37858E4A ); store<i64>( JH_E8 +  200, 0x956A9FFB2D8D672A );
	store<i64>( JH_E8 +  208, 0x6C69B8F88173FE8A ); store<i64>( JH_E8 +  216, 0x14427FC04672C78A );
	store<i64>( JH_E8 +  224, 0xC45EC7BD8F15F4C5 ); store<i64>( JH_E8 +  232, 0x80BB118FA76F4475 );
	store<i64>( JH_E8 +  240, 0xBC88E4AEB775DE52 ); store<i64>( JH_E8 +  248, 0xF4A3A6981E00B882 );
	store<i64>( JH_E8 +  256, 0x1563A3A9338FF48E ); store<i64>( JH_E8 +  264, 0x89F9B7D524565FAA );
	store<i64>( JH_E8 +  272, 0xFDE05A7C20EDF1B6 ); store<i64>( JH_E8 +  280, 0x362C42065AE9CA36 );
	store<i64>( JH_E8 +  288, 0x3D98FE4E433529CE ); store<i64>( JH_E8 +  296, 0xA74B9A7374F93A53 );
	store<i64>( JH_E8 +  304, 0x86814E6F591FF5D0 ); store<i64>( JH_E8 +  312, 0x9F5AD8AF81AD9D0E );
	store<i64>( JH_E8 +  320, 0x6A6234EE670605A7 ); store<i64>( JH_E8 +  328, 0x2717B96EBE280B8B );
	store<i64>( JH_E8 +  336, 0x3F1080C626077447 ); store<i64>( JH_E8 +  344, 0x7B487EC66F7EA0E0 );
	store<i64>( JH_E8 +  352, 0xC0A4F84AA50A550D ); store<i64>( JH_E8 +  360, 0x9EF18E979FE7E391 );
	store<i64>( JH_E8 +  368, 0xD48D605081727686 ); store<i64>( JH_E8 +  376, 0x62B0E5F3415A9E7E );
	store<i64>( JH_E8 +  384, 0x7A205440EC1F9FFC ); store<i64>( JH_E8 +  392, 0x84C9F4CE001AE4E3 );
	store<i64>( JH_E8 +  400, 0xD895FA9DF594D74F ); store<i64>( JH_E8 +  408, 0xA554C324117E2E55 );
	store<i64>( JH_E8 +  416, 0x286EFEBD2872DF5B ); store<i64>( JH_E8 +  424, 0xB2C4A50FE27FF578 );
	store<i64>( JH_E8 +  432, 0x2ED349EEEF7C8905 ); store<i64>( JH_E8 +  440, 0x7F5928EB85937E44 );
	store<i64>( JH_E8 +  448, 0x4A3124B337695F70 ); store<i64>( JH_E8 +  456, 0x65E4D61DF128865E );
	store<i64>( JH_E8 +  464, 0xE720B95104771BC7 ); store<i64>( JH_E8 +  472, 0x8A87D423E843FE74 );
	store<i64>( JH_E8 +  480, 0xF2947692A3E8297D ); store<i64>( JH_E8 +  488, 0xC1D9309B097ACBDD );
	store<i64>( JH_E8 +  496, 0xE01BDC5BFB301B1D ); store<i64>( JH_E8 +  504, 0xBF829CF24F4924DA );
	store<i64>( JH_E8 +  512, 0xFFBF70B431BAE7A4 ); store<i64>( JH_E8 +  520, 0x48BCF8DE0544320D );
	store<i64>( JH_E8 +  528, 0x39D3BB5332FCAE3B ); store<i64>( JH_E8 +  536, 0xA08B29E0C1C39F45 );
	store<i64>( JH_E8 +  544, 0x0F09AEF7FD05C9E5 ); store<i64>( JH_E8 +  552, 0x34F1904212347094 );
	store<i64>( JH_E8 +  560, 0x95ED44E301B771A2 ); store<i64>( JH_E8 +  568, 0x4A982F4F368E3BE9 );
	store<i64>( JH_E8 +  576, 0x15F66CA0631D4088 ); store<i64>( JH_E8 +  584, 0xFFAF52874B44C147 );
	store<i64>( JH_E8 +  592, 0x30C60AE2F14ABB7E ); store<i64>( JH_E8 +  600, 0xE68C6ECCC5B67046 );
	store<i64>( JH_E8 +  608, 0x00CA4FBD56A4D5A4 ); store<i64>( JH_E8 +  616, 0xAE183EC84B849DDA );
	store<i64>( JH_E8 +  624, 0xADD1643045CE5773 ); store<i64>( JH_E8 +  632, 0x67255C1468CEA6E8 );
	store<i64>( JH_E8 +  640, 0x16E10ECBF28CDAA3 ); store<i64>( JH_E8 +  648, 0x9A99949A5806E933 );
	store<i64>( JH_E8 +  656, 0x7B846FC220B2601F ); store<i64>( JH_E8 +  664, 0x1885D1A07FACCED1 );
	store<i64>( JH_E8 +  672, 0xD319DD8DA15B5932 ); store<i64>( JH_E8 +  680, 0x46B4A5AAC01C9A50 );
	store<i64>( JH_E8 +  688, 0xBA6B04E467633D9F ); store<i64>( JH_E8 +  696, 0x7EEE560BAB19CAF6 );
	store<i64>( JH_E8 +  704, 0x742128A9EA79B11F ); store<i64>( JH_E8 +  712, 0xEE51363B35F7BDE9 );
	store<i64>( JH_E8 +  720, 0x76D350755AAC571D ); store<i64>( JH_E8 +  728, 0x01707DA3FEC2463A );
	store<i64>( JH_E8 +  736, 0x42D8A498AFC135F7 ); store<i64>( JH_E8 +  744, 0x79676B9E20ECED78 );
	store<i64>( JH_E8 +  752, 0xA8DB3AEA15638341 ); store<i64>( JH_E8 +  760, 0x832C83324D3BC3FA );
	store<i64>( JH_E8 +  768, 0xF347271C1F3B40A7 ); store<i64>( JH_E8 +  776, 0x9A762DB734F04059 );
	store<i64>( JH_E8 +  784, 0xFD4F21D26C4E3EE7 ); store<i64>( JH_E8 +  792, 0xEF5957DC398DFDB8 );
	store<i64>( JH_E8 +  800, 0xDAEB492B490C9B8D ); store<i64>( JH_E8 +  808, 0x0D70F36849D7A25B );
	store<i64>( JH_E8 +  816, 0x84558D7AD0AE3B7D ); store<i64>( JH_E8 +  824, 0x658EF8E4F0E9A5F5 );
	store<i64>( JH_E8 +  832, 0x533B1036F4A2B8A0 ); store<i64>( JH_E8 +  840, 0x5AEC3E759E07A80C );
	store<i64>( JH_E8 +  848, 0x4F88E85692946891 ); store<i64>( JH_E8 +  856, 0x4CBCBAF8555CB05B );
	store<i64>( JH_E8 +  864, 0x7B9487F3993BBBE3 ); store<i64>( JH_E8 +  872, 0x5D1C6B72D6F4DA75 );
	store<i64>( JH_E8 +  880, 0x6DB334DC28ACAE64 ); store<i64>( JH_E8 +  888, 0x71DB28B850A5346C );
	store<i64>( JH_E8 +  896, 0x2A518D10F2E261F8 ); store<i64>( JH_E8 +  904, 0xFC75DD593364DBE3 );
	store<i64>( JH_E8 +  912, 0xA23FCE43F1BCAC1C ); store<i64>( JH_E8 +  920, 0xB043E8023CD1BB67 );
	store<i64>( JH_E8 +  928, 0x75A12988CA5B0A33 ); store<i64>( JH_E8 +  936, 0x5C5316B44D19347F );
	store<i64>( JH_E8 +  944, 0x1E4D790EC3943B92 ); store<i64>( JH_E8 +  952, 0x3FAFEEB6D7757479 );
	store<i64>( JH_E8 +  960, 0x21391ABEF7D4A8EA ); store<i64>( JH_E8 +  968, 0x5127234C097EF45C );
	store<i64>( JH_E8 +  976, 0xD23C32BA5324A326 ); store<i64>( JH_E8 +  984, 0xADD5A66D4A17A344 );
	store<i64>( JH_E8 +  992, 0x08C9F2AFA63E1DB5 ); store<i64>( JH_E8 + 1000, 0x563C6B91983D5983 );
	store<i64>( JH_E8 + 1008, 0x4D608672A17CF84C ); store<i64>( JH_E8 + 1016, 0xF6C76E08CC3EE246 );
	store<i64>( JH_E8 + 1024, 0x5E76BCB1B333982F ); store<i64>( JH_E8 + 1032, 0x2AE6C4EFA566D62B );
	store<i64>( JH_E8 + 1040, 0x36D4C1BEE8B6F406 ); store<i64>( JH_E8 + 1048, 0x6321EFBC1582EE74 );
	store<i64>( JH_E8 + 1056, 0x69C953F40D4EC1FD ); store<i64>( JH_E8 + 1064, 0x26585806C45A7DA7 );
	store<i64>( JH_E8 + 1072, 0x16FAE0061614C17E ); store<i64>( JH_E8 + 1080, 0x3F9D63283DAF907E );
	store<i64>( JH_E8 + 1088, 0x0CD29B00E3F2C9D2 ); store<i64>( JH_E8 + 1096, 0x300CD4B730CEAA5F );
	store<i64>( JH_E8 + 1104, 0x9832E0F216512A74 ); store<i64>( JH_E8 + 1112, 0x9AF8CEE3D830EB0D );
	store<i64>( JH_E8 + 1120, 0x9279F1B57B9EC54B ); store<i64>( JH_E8 + 1128, 0xD36886046EE651FF );
	store<i64>( JH_E8 + 1136, 0x316796E6574D239B ); store<i64>( JH_E8 + 1144, 0x05750A17F3A6E6CC );
	store<i64>( JH_E8 + 1152, 0xCE6C3213D98176B1 ); store<i64>( JH_E8 + 1160, 0x62A205F88452173C );
	store<i64>( JH_E8 + 1168, 0x47154778B3CB2BF4 ); store<i64>( JH_E8 + 1176, 0x486A9323825446FF );
	store<i64>( JH_E8 + 1184, 0x65655E4E0758DF38 ); store<i64>( JH_E8 + 1192, 0x8E5086FC897CFCF2 );
	store<i64>( JH_E8 + 1200, 0x86CA0BD0442E7031 ); store<i64>( JH_E8 + 1208, 0x4E477830A20940F0 );
	store<i64>( JH_E8 + 1216, 0x8338F7D139EEA065 ); store<i64>( JH_E8 + 1224, 0xBD3A2CE437E95EF7 );
	store<i64>( JH_E8 + 1232, 0x6FF8130126B29721 ); store<i64>( JH_E8 + 1240, 0xE7DE9FEFD1ED44A3 );
	store<i64>( JH_E8 + 1248, 0xD992257615DFA08B ); store<i64>( JH_E8 + 1256, 0xBE42DC12F6F7853C );
	store<i64>( JH_E8 + 1264, 0x7EB027AB7CECA7D8 ); store<i64>( JH_E8 + 1272, 0xDEA83EAADA7D8D53 );
	store<i64>( JH_E8 + 1280, 0xD86902BD93CE25AA ); store<i64>( JH_E8 + 1288, 0xF908731AFD43F65A );
	store<i64>( JH_E8 + 1296, 0xA5194A17DAEF5FC0 ); store<i64>( JH_E8 + 1304, 0x6A21FD4C33664D97 );
	store<i64>( JH_E8 + 1312, 0x701541DB3198B435 ); store<i64>( JH_E8 + 1320, 0x9B54CDEDBB0F1EEA );
	store<i64>( JH_E8 + 1328, 0x72409751A163D09A ); store<i64>( JH_E8 + 1336, 0xE26F4791BF9D75F6 );

	// compute jh swap
	store<i64>( JH_SWAP +   0, 0x5555555555555555 ); store<i64>( JH_SWAP +   8, 0xAAAAAAAAAAAAAAAA ); //  1
	store<i64>( JH_SWAP +  16, 0x3333333333333333 ); store<i64>( JH_SWAP +  24, 0xCCCCCCCCCCCCCCCC ); //  2
	store<i64>( JH_SWAP +  32, 0x0F0F0F0F0F0F0F0F ); store<i64>( JH_SWAP +  40, 0xF0F0F0F0F0F0F0F0 ); //  4
	store<i64>( JH_SWAP +  48, 0x00FF00FF00FF00FF ); store<i64>( JH_SWAP +  56, 0xFF00FF00FF00FF00 ); //  8
	store<i64>( JH_SWAP +  64, 0x0000FFFF0000FFFF ); store<i64>( JH_SWAP +  72, 0xFFFF0000FFFF0000 ); // 16
	store<i64>( JH_SWAP +  80, 0xFFFFFFFFFFFFFFFF ); store<i64>( JH_SWAP +  88, 0xFFFFFFFFFFFFFFFF ); // 32
	store<i64>( JH_SWAP +  96, 0xFFFFFFFFFFFFFFFF ); store<i64>( JH_SWAP + 104, 0xFFFFFFFFFFFFFFFF ); // 64

	// compute grostl table
	store<i64>( GROSTL_T0 +    0, 0xC6A597F4A5F432C6 ); store<i64>( GROSTL_T0 +    8, 0xF884EB9784976FF8 );
	store<i64>( GROSTL_T0 +   16, 0xEE99C7B099B05EEE ); store<i64>( GROSTL_T0 +   24, 0xF68DF78C8D8C7AF6 );
	store<i64>( GROSTL_T0 +   32, 0xFF0DE5170D17E8FF ); store<i64>( GROSTL_T0 +   40, 0xD6BDB7DCBDDC0AD6 );
	store<i64>( GROSTL_T0 +   48, 0xDEB1A7C8B1C816DE ); store<i64>( GROSTL_T0 +   56, 0x915439FC54FC6D91 );
	store<i64>( GROSTL_T0 +   64, 0x6050C0F050F09060 ); store<i64>( GROSTL_T0 +   72, 0x0203040503050702 );
	store<i64>( GROSTL_T0 +   80, 0xCEA987E0A9E02ECE ); store<i64>( GROSTL_T0 +   88, 0x567DAC877D87D156 );
	store<i64>( GROSTL_T0 +   96, 0xE719D52B192BCCE7 ); store<i64>( GROSTL_T0 +  104, 0xB56271A662A613B5 );
	store<i64>( GROSTL_T0 +  112, 0x4DE69A31E6317C4D ); store<i64>( GROSTL_T0 +  120, 0xEC9AC3B59AB559EC );
	store<i64>( GROSTL_T0 +  128, 0x8F4505CF45CF408F ); store<i64>( GROSTL_T0 +  136, 0x1F9D3EBC9DBCA31F );
	store<i64>( GROSTL_T0 +  144, 0x894009C040C04989 ); store<i64>( GROSTL_T0 +  152, 0xFA87EF92879268FA );
	store<i64>( GROSTL_T0 +  160, 0xEF15C53F153FD0EF ); store<i64>( GROSTL_T0 +  168, 0xB2EB7F26EB2694B2 );
	store<i64>( GROSTL_T0 +  176, 0x8EC90740C940CE8E ); store<i64>( GROSTL_T0 +  184, 0xFB0BED1D0B1DE6FB );
	store<i64>( GROSTL_T0 +  192, 0x41EC822FEC2F6E41 ); store<i64>( GROSTL_T0 +  200, 0xB3677DA967A91AB3 );
	store<i64>( GROSTL_T0 +  208, 0x5FFDBE1CFD1C435F ); store<i64>( GROSTL_T0 +  216, 0x45EA8A25EA256045 );
	store<i64>( GROSTL_T0 +  224, 0x23BF46DABFDAF923 ); store<i64>( GROSTL_T0 +  232, 0x53F7A602F7025153 );
	store<i64>( GROSTL_T0 +  240, 0xE496D3A196A145E4 ); store<i64>( GROSTL_T0 +  248, 0x9B5B2DED5BED769B );
	store<i64>( GROSTL_T0 +  256, 0x75C2EA5DC25D2875 ); store<i64>( GROSTL_T0 +  264, 0xE11CD9241C24C5E1 );
	store<i64>( GROSTL_T0 +  272, 0x3DAE7AE9AEE9D43D ); store<i64>( GROSTL_T0 +  280, 0x4C6A98BE6ABEF24C );
	store<i64>( GROSTL_T0 +  288, 0x6C5AD8EE5AEE826C ); store<i64>( GROSTL_T0 +  296, 0x7E41FCC341C3BD7E );
	store<i64>( GROSTL_T0 +  304, 0xF502F1060206F3F5 ); store<i64>( GROSTL_T0 +  312, 0x834F1DD14FD15283 );
	store<i64>( GROSTL_T0 +  320, 0x685CD0E45CE48C68 ); store<i64>( GROSTL_T0 +  328, 0x51F4A207F4075651 );
	store<i64>( GROSTL_T0 +  336, 0xD134B95C345C8DD1 ); store<i64>( GROSTL_T0 +  344, 0xF908E9180818E1F9 );
	store<i64>( GROSTL_T0 +  352, 0xE293DFAE93AE4CE2 ); store<i64>( GROSTL_T0 +  360, 0xAB734D9573953EAB );
	store<i64>( GROSTL_T0 +  368, 0x6253C4F553F59762 ); store<i64>( GROSTL_T0 +  376, 0x2A3F54413F416B2A );
	store<i64>( GROSTL_T0 +  384, 0x080C10140C141C08 ); store<i64>( GROSTL_T0 +  392, 0x955231F652F66395 );
	store<i64>( GROSTL_T0 +  400, 0x46658CAF65AFE946 ); store<i64>( GROSTL_T0 +  408, 0x9D5E21E25EE27F9D );
	store<i64>( GROSTL_T0 +  416, 0x3028607828784830 ); store<i64>( GROSTL_T0 +  424, 0x37A16EF8A1F8CF37 );
	store<i64>( GROSTL_T0 +  432, 0x0A0F14110F111B0A ); store<i64>( GROSTL_T0 +  440, 0x2FB55EC4B5C4EB2F );
	store<i64>( GROSTL_T0 +  448, 0x0E091C1B091B150E ); store<i64>( GROSTL_T0 +  456, 0x2436485A365A7E24 );
	store<i64>( GROSTL_T0 +  464, 0x1B9B36B69BB6AD1B ); store<i64>( GROSTL_T0 +  472, 0xDF3DA5473D4798DF );
	store<i64>( GROSTL_T0 +  480, 0xCD26816A266AA7CD ); store<i64>( GROSTL_T0 +  488, 0x4E699CBB69BBF54E );
	store<i64>( GROSTL_T0 +  496, 0x7FCDFE4CCD4C337F ); store<i64>( GROSTL_T0 +  504, 0xEA9FCFBA9FBA50EA );
	store<i64>( GROSTL_T0 +  512, 0x121B242D1B2D3F12 ); store<i64>( GROSTL_T0 +  520, 0x1D9E3AB99EB9A41D );
	store<i64>( GROSTL_T0 +  528, 0x5874B09C749CC458 ); store<i64>( GROSTL_T0 +  536, 0x342E68722E724634 );
	store<i64>( GROSTL_T0 +  544, 0x362D6C772D774136 ); store<i64>( GROSTL_T0 +  552, 0xDCB2A3CDB2CD11DC );
	store<i64>( GROSTL_T0 +  560, 0xB4EE7329EE299DB4 ); store<i64>( GROSTL_T0 +  568, 0x5BFBB616FB164D5B );
	store<i64>( GROSTL_T0 +  576, 0xA4F65301F601A5A4 ); store<i64>( GROSTL_T0 +  584, 0x764DECD74DD7A176 );
	store<i64>( GROSTL_T0 +  592, 0xB76175A361A314B7 ); store<i64>( GROSTL_T0 +  600, 0x7DCEFA49CE49347D );
	store<i64>( GROSTL_T0 +  608, 0x527BA48D7B8DDF52 ); store<i64>( GROSTL_T0 +  616, 0xDD3EA1423E429FDD );
	store<i64>( GROSTL_T0 +  624, 0x5E71BC937193CD5E ); store<i64>( GROSTL_T0 +  632, 0x139726A297A2B113 );
	store<i64>( GROSTL_T0 +  640, 0xA6F55704F504A2A6 ); store<i64>( GROSTL_T0 +  648, 0xB96869B868B801B9 );
	store<i64>( GROSTL_T0 +  656, 0x0000000000000000 ); store<i64>( GROSTL_T0 +  664, 0xC12C99742C74B5C1 );
	store<i64>( GROSTL_T0 +  672, 0x406080A060A0E040 ); store<i64>( GROSTL_T0 +  680, 0xE31FDD211F21C2E3 );
	store<i64>( GROSTL_T0 +  688, 0x79C8F243C8433A79 ); store<i64>( GROSTL_T0 +  696, 0xB6ED772CED2C9AB6 );
	store<i64>( GROSTL_T0 +  704, 0xD4BEB3D9BED90DD4 ); store<i64>( GROSTL_T0 +  712, 0x8D4601CA46CA478D );
	store<i64>( GROSTL_T0 +  720, 0x67D9CE70D9701767 ); store<i64>( GROSTL_T0 +  728, 0x724BE4DD4BDDAF72 );
	store<i64>( GROSTL_T0 +  736, 0x94DE3379DE79ED94 ); store<i64>( GROSTL_T0 +  744, 0x98D42B67D467FF98 );
	store<i64>( GROSTL_T0 +  752, 0xB0E87B23E82393B0 ); store<i64>( GROSTL_T0 +  760, 0x854A11DE4ADE5B85 );
	store<i64>( GROSTL_T0 +  768, 0xBB6B6DBD6BBD06BB ); store<i64>( GROSTL_T0 +  776, 0xC52A917E2A7EBBC5 );
	store<i64>( GROSTL_T0 +  784, 0x4FE59E34E5347B4F ); store<i64>( GROSTL_T0 +  792, 0xED16C13A163AD7ED );
	store<i64>( GROSTL_T0 +  800, 0x86C51754C554D286 ); store<i64>( GROSTL_T0 +  808, 0x9AD72F62D762F89A );
	store<i64>( GROSTL_T0 +  816, 0x6655CCFF55FF9966 ); store<i64>( GROSTL_T0 +  824, 0x119422A794A7B611 );
	store<i64>( GROSTL_T0 +  832, 0x8ACF0F4ACF4AC08A ); store<i64>( GROSTL_T0 +  840, 0xE910C9301030D9E9 );
	store<i64>( GROSTL_T0 +  848, 0x0406080A060A0E04 ); store<i64>( GROSTL_T0 +  856, 0xFE81E798819866FE );
	store<i64>( GROSTL_T0 +  864, 0xA0F05B0BF00BABA0 ); store<i64>( GROSTL_T0 +  872, 0x7844F0CC44CCB478 );
	store<i64>( GROSTL_T0 +  880, 0x25BA4AD5BAD5F025 ); store<i64>( GROSTL_T0 +  888, 0x4BE3963EE33E754B );
	store<i64>( GROSTL_T0 +  896, 0xA2F35F0EF30EACA2 ); store<i64>( GROSTL_T0 +  904, 0x5DFEBA19FE19445D );
	store<i64>( GROSTL_T0 +  912, 0x80C01B5BC05BDB80 ); store<i64>( GROSTL_T0 +  920, 0x058A0A858A858005 );
	store<i64>( GROSTL_T0 +  928, 0x3FAD7EECADECD33F ); store<i64>( GROSTL_T0 +  936, 0x21BC42DFBCDFFE21 );
	store<i64>( GROSTL_T0 +  944, 0x7048E0D848D8A870 ); store<i64>( GROSTL_T0 +  952, 0xF104F90C040CFDF1 );
	store<i64>( GROSTL_T0 +  960, 0x63DFC67ADF7A1963 ); store<i64>( GROSTL_T0 +  968, 0x77C1EE58C1582F77 );
	store<i64>( GROSTL_T0 +  976, 0xAF75459F759F30AF ); store<i64>( GROSTL_T0 +  984, 0x426384A563A5E742 );
	store<i64>( GROSTL_T0 +  992, 0x2030405030507020 ); store<i64>( GROSTL_T0 + 1000, 0xE51AD12E1A2ECBE5 );
	store<i64>( GROSTL_T0 + 1008, 0xFD0EE1120E12EFFD ); store<i64>( GROSTL_T0 + 1016, 0xBF6D65B76DB708BF );
	store<i64>( GROSTL_T0 + 1024, 0x814C19D44CD45581 ); store<i64>( GROSTL_T0 + 1032, 0x1814303C143C2418 );
	store<i64>( GROSTL_T0 + 1040, 0x26354C5F355F7926 ); store<i64>( GROSTL_T0 + 1048, 0xC32F9D712F71B2C3 );
	store<i64>( GROSTL_T0 + 1056, 0xBEE16738E13886BE ); store<i64>( GROSTL_T0 + 1064, 0x35A26AFDA2FDC835 );
	store<i64>( GROSTL_T0 + 1072, 0x88CC0B4FCC4FC788 ); store<i64>( GROSTL_T0 + 1080, 0x2E395C4B394B652E );
	store<i64>( GROSTL_T0 + 1088, 0x93573DF957F96A93 ); store<i64>( GROSTL_T0 + 1096, 0x55F2AA0DF20D5855 );
	store<i64>( GROSTL_T0 + 1104, 0xFC82E39D829D61FC ); store<i64>( GROSTL_T0 + 1112, 0x7A47F4C947C9B37A );
	store<i64>( GROSTL_T0 + 1120, 0xC8AC8BEFACEF27C8 ); store<i64>( GROSTL_T0 + 1128, 0xBAE76F32E73288BA );
	store<i64>( GROSTL_T0 + 1136, 0x322B647D2B7D4F32 ); store<i64>( GROSTL_T0 + 1144, 0xE695D7A495A442E6 );
	store<i64>( GROSTL_T0 + 1152, 0xC0A09BFBA0FB3BC0 ); store<i64>( GROSTL_T0 + 1160, 0x199832B398B3AA19 );
	store<i64>( GROSTL_T0 + 1168, 0x9ED12768D168F69E ); store<i64>( GROSTL_T0 + 1176, 0xA37F5D817F8122A3 );
	store<i64>( GROSTL_T0 + 1184, 0x446688AA66AAEE44 ); store<i64>( GROSTL_T0 + 1192, 0x547EA8827E82D654 );
	store<i64>( GROSTL_T0 + 1200, 0x3BAB76E6ABE6DD3B ); store<i64>( GROSTL_T0 + 1208, 0x0B83169E839E950B );
	store<i64>( GROSTL_T0 + 1216, 0x8CCA0345CA45C98C ); store<i64>( GROSTL_T0 + 1224, 0xC729957B297BBCC7 );
	store<i64>( GROSTL_T0 + 1232, 0x6BD3D66ED36E056B ); store<i64>( GROSTL_T0 + 1240, 0x283C50443C446C28 );
	store<i64>( GROSTL_T0 + 1248, 0xA779558B798B2CA7 ); store<i64>( GROSTL_T0 + 1256, 0xBCE2633DE23D81BC );
	store<i64>( GROSTL_T0 + 1264, 0x161D2C271D273116 ); store<i64>( GROSTL_T0 + 1272, 0xAD76419A769A37AD );
	store<i64>( GROSTL_T0 + 1280, 0xDB3BAD4D3B4D96DB ); store<i64>( GROSTL_T0 + 1288, 0x6456C8FA56FA9E64 );
	store<i64>( GROSTL_T0 + 1296, 0x744EE8D24ED2A674 ); store<i64>( GROSTL_T0 + 1304, 0x141E28221E223614 );
	store<i64>( GROSTL_T0 + 1312, 0x92DB3F76DB76E492 ); store<i64>( GROSTL_T0 + 1320, 0x0C0A181E0A1E120C );
	store<i64>( GROSTL_T0 + 1328, 0x486C90B46CB4FC48 ); store<i64>( GROSTL_T0 + 1336, 0xB8E46B37E4378FB8 );
	store<i64>( GROSTL_T0 + 1344, 0x9F5D25E75DE7789F ); store<i64>( GROSTL_T0 + 1352, 0xBD6E61B26EB20FBD );
	store<i64>( GROSTL_T0 + 1360, 0x43EF862AEF2A6943 ); store<i64>( GROSTL_T0 + 1368, 0xC4A693F1A6F135C4 );
	store<i64>( GROSTL_T0 + 1376, 0x39A872E3A8E3DA39 ); store<i64>( GROSTL_T0 + 1384, 0x31A462F7A4F7C631 );
	store<i64>( GROSTL_T0 + 1392, 0xD337BD5937598AD3 ); store<i64>( GROSTL_T0 + 1400, 0xF28BFF868B8674F2 );
	store<i64>( GROSTL_T0 + 1408, 0xD532B156325683D5 ); store<i64>( GROSTL_T0 + 1416, 0x8B430DC543C54E8B );
	store<i64>( GROSTL_T0 + 1424, 0x6E59DCEB59EB856E ); store<i64>( GROSTL_T0 + 1432, 0xDAB7AFC2B7C218DA );
	store<i64>( GROSTL_T0 + 1440, 0x018C028F8C8F8E01 ); store<i64>( GROSTL_T0 + 1448, 0xB16479AC64AC1DB1 );
	store<i64>( GROSTL_T0 + 1456, 0x9CD2236DD26DF19C ); store<i64>( GROSTL_T0 + 1464, 0x49E0923BE03B7249 );
	store<i64>( GROSTL_T0 + 1472, 0xD8B4ABC7B4C71FD8 ); store<i64>( GROSTL_T0 + 1480, 0xACFA4315FA15B9AC );
	store<i64>( GROSTL_T0 + 1488, 0xF307FD090709FAF3 ); store<i64>( GROSTL_T0 + 1496, 0xCF25856F256FA0CF );
	store<i64>( GROSTL_T0 + 1504, 0xCAAF8FEAAFEA20CA ); store<i64>( GROSTL_T0 + 1512, 0xF48EF3898E897DF4 );
	store<i64>( GROSTL_T0 + 1520, 0x47E98E20E9206747 ); store<i64>( GROSTL_T0 + 1528, 0x1018202818283810 );
	store<i64>( GROSTL_T0 + 1536, 0x6FD5DE64D5640B6F ); store<i64>( GROSTL_T0 + 1544, 0xF088FB83888373F0 );
	store<i64>( GROSTL_T0 + 1552, 0x4A6F94B16FB1FB4A ); store<i64>( GROSTL_T0 + 1560, 0x5C72B8967296CA5C );
	store<i64>( GROSTL_T0 + 1568, 0x3824706C246C5438 ); store<i64>( GROSTL_T0 + 1576, 0x57F1AE08F1085F57 );
	store<i64>( GROSTL_T0 + 1584, 0x73C7E652C7522173 ); store<i64>( GROSTL_T0 + 1592, 0x975135F351F36497 );
	store<i64>( GROSTL_T0 + 1600, 0xCB238D652365AECB ); store<i64>( GROSTL_T0 + 1608, 0xA17C59847C8425A1 );
	store<i64>( GROSTL_T0 + 1616, 0xE89CCBBF9CBF57E8 ); store<i64>( GROSTL_T0 + 1624, 0x3E217C6321635D3E );
	store<i64>( GROSTL_T0 + 1632, 0x96DD377CDD7CEA96 ); store<i64>( GROSTL_T0 + 1640, 0x61DCC27FDC7F1E61 );
	store<i64>( GROSTL_T0 + 1648, 0x0D861A9186919C0D ); store<i64>( GROSTL_T0 + 1656, 0x0F851E9485949B0F );
	store<i64>( GROSTL_T0 + 1664, 0xE090DBAB90AB4BE0 ); store<i64>( GROSTL_T0 + 1672, 0x7C42F8C642C6BA7C );
	store<i64>( GROSTL_T0 + 1680, 0x71C4E257C4572671 ); store<i64>( GROSTL_T0 + 1688, 0xCCAA83E5AAE529CC );
	store<i64>( GROSTL_T0 + 1696, 0x90D83B73D873E390 ); store<i64>( GROSTL_T0 + 1704, 0x06050C0F050F0906 );
	store<i64>( GROSTL_T0 + 1712, 0xF701F5030103F4F7 ); store<i64>( GROSTL_T0 + 1720, 0x1C12383612362A1C );
	store<i64>( GROSTL_T0 + 1728, 0xC2A39FFEA3FE3CC2 ); store<i64>( GROSTL_T0 + 1736, 0x6A5FD4E15FE18B6A );
	store<i64>( GROSTL_T0 + 1744, 0xAEF94710F910BEAE ); store<i64>( GROSTL_T0 + 1752, 0x69D0D26BD06B0269 );
	store<i64>( GROSTL_T0 + 1760, 0x17912EA891A8BF17 ); store<i64>( GROSTL_T0 + 1768, 0x995829E858E87199 );
	store<i64>( GROSTL_T0 + 1776, 0x3A2774692769533A ); store<i64>( GROSTL_T0 + 1784, 0x27B94ED0B9D0F727 );
	store<i64>( GROSTL_T0 + 1792, 0xD938A948384891D9 ); store<i64>( GROSTL_T0 + 1800, 0xEB13CD351335DEEB );
	store<i64>( GROSTL_T0 + 1808, 0x2BB356CEB3CEE52B ); store<i64>( GROSTL_T0 + 1816, 0x2233445533557722 );
	store<i64>( GROSTL_T0 + 1824, 0xD2BBBFD6BBD604D2 ); store<i64>( GROSTL_T0 + 1832, 0xA9704990709039A9 );
	store<i64>( GROSTL_T0 + 1840, 0x07890E8089808707 ); store<i64>( GROSTL_T0 + 1848, 0x33A766F2A7F2C133 );
	store<i64>( GROSTL_T0 + 1856, 0x2DB65AC1B6C1EC2D ); store<i64>( GROSTL_T0 + 1864, 0x3C22786622665A3C );
	store<i64>( GROSTL_T0 + 1872, 0x15922AAD92ADB815 ); store<i64>( GROSTL_T0 + 1880, 0xC92089602060A9C9 );
	store<i64>( GROSTL_T0 + 1888, 0x874915DB49DB5C87 ); store<i64>( GROSTL_T0 + 1896, 0xAAFF4F1AFF1AB0AA );
	store<i64>( GROSTL_T0 + 1904, 0x5078A0887888D850 ); store<i64>( GROSTL_T0 + 1912, 0xA57A518E7A8E2BA5 );
	store<i64>( GROSTL_T0 + 1920, 0x038F068A8F8A8903 ); store<i64>( GROSTL_T0 + 1928, 0x59F8B213F8134A59 );
	store<i64>( GROSTL_T0 + 1936, 0x0980129B809B9209 ); store<i64>( GROSTL_T0 + 1944, 0x1A1734391739231A );
	store<i64>( GROSTL_T0 + 1952, 0x65DACA75DA751065 ); store<i64>( GROSTL_T0 + 1960, 0xD731B553315384D7 );
	store<i64>( GROSTL_T0 + 1968, 0x84C61351C651D584 ); store<i64>( GROSTL_T0 + 1976, 0xD0B8BBD3B8D303D0 );
	store<i64>( GROSTL_T0 + 1984, 0x82C31F5EC35EDC82 ); store<i64>( GROSTL_T0 + 1992, 0x29B052CBB0CBE229 );
	store<i64>( GROSTL_T0 + 2000, 0x5A77B4997799C35A ); store<i64>( GROSTL_T0 + 2008, 0x1E113C3311332D1E );
	store<i64>( GROSTL_T0 + 2016, 0x7BCBF646CB463D7B ); store<i64>( GROSTL_T0 + 2024, 0xA8FC4B1FFC1FB7A8 );
	store<i64>( GROSTL_T0 + 2032, 0x6DD6DA61D6610C6D ); store<i64>( GROSTL_T0 + 2040, 0x2C3A584E3A4E622C );

	i = 0;
	do {

		v = load<i64>( i, GROSTL_T0 );

		store<i64>( i, ( v <<  8 ) | ( v >>> 56 ), GROSTL_T1 );
		store<i64>( i, ( v << 16 ) | ( v >>> 48 ), GROSTL_T2 );
		store<i64>( i, ( v << 24 ) | ( v >>> 40 ), GROSTL_T3 );
		store<i64>( i, ( v << 32 ) | ( v >>> 32 ), GROSTL_T4 );
		store<i64>( i, ( v << 40 ) | ( v >>> 24 ), GROSTL_T5 );
		store<i64>( i, ( v << 48 ) | ( v >>> 16 ), GROSTL_T6 );
		store<i64>( i, ( v << 56 ) | ( v >>>  8 ), GROSTL_T7 );

	} while ( ( i += 8 ) < 2048 );

}

export function offset():i32 {
	return DATA;
}

export function hash(len:i32, variant:i32=0):void {

	var nonce:i64;

	var i:i32;
	var j:i32;
	var k:i32;
	var t:i32;

	var s00:i64;
	var s01:i64;
	var s02:i64;
	var s03:i64;
	var s04:i64;
	var s05:i64;
	var s06:i64;
	var s07:i64;
	var s08:i64;
	var s09:i64;
	var s10:i64;
	var s11:i64;
	var s12:i64;
	var s13:i64;
	var s14:i64;
	var s15:i64;
	var s16:i64;
	var s17:i64;
	var s18:i64;
	var s19:i64;
	var s20:i64;
	var s21:i64;
	var s22:i64;
	var s23:i64;
	var s24:i64;

	var	b00:i64;
	var b01:i64;
	var b02:i64;
	var b03:i64;
	var b04:i64;
	var b05:i64;
	var b06:i64;
	var b07:i64;
	var b08:i64;
	var b09:i64;
	var b10:i64;
	var b11:i64;
	var b12:i64;
	var b13:i64;
	var b14:i64;
	var b15:i64;
	var b16:i64;
	var b17:i64;
	var b18:i64;
	var b19:i64;
	var b20:i64;
	var b21:i64;
	var b22:i64;
	var b23:i64;
	var b24:i64;

	var ut:i64;

	var a0:u64;
	var a1:u64;
	var b0:u64;
	var b1:u64;
	var c0:u64;
	var c1:u64;

	var a:u64;
	var b:u64;
	var c:u64;
	var d:u64;
	var ad:u64;
	var bd:u64;
	var adbc:u64;

	var aes00:i32;
	var aes01:i32;
	var aes02:i32;
	var aes03:i32;
	var aes04:i32;
	var aes05:i32;
	var aes06:i32;
	var aes07:i32;
	var aes08:i32;
	var aes09:i32;
	var aes10:i32;
	var aes11:i32;
	var aes12:i32;
	var aes13:i32;
	var aes14:i32;
	var aes15:i32;
	var aes16:i32;
	var aes17:i32;
	var aes18:i32;
	var aes19:i32;
	var aes20:i32;
	var aes21:i32;
	var aes22:i32;
	var aes23:i32;
	var aes24:i32;
	var aes25:i32;
	var aes26:i32;
	var aes27:i32;
	var aes28:i32;
	var aes29:i32;
	var aes30:i32;
	var aes31:i32;
	var aes32:i32;
	var aes33:i32;
	var aes34:i32;
	var aes35:i32;
	var aes36:i32;
	var aes37:i32;
	var aes38:i32;
	var aes39:i32;

	var src0:i32;
	var src1:i32;
	var src2:i32;
	var src3:i32;

	var tmp0:i32;
	var tmp1:i32;
	var tmp2:i32;
	var tmp3:i32;

	/*
	 * CryptoNight Step 1:  Use Keccak to initialize buffers from the data.
	 */

	// --------
	// calc keccak
	// --------

	if ( len < 43 ) variant = 0;

	// calc blocks and padding
	store<i8>( len, 1, DATA );
	i = len + 1;
	len += 136 - ( len % 136 );
	if ( i & 1 ) {
		store<i8>( i, 0, DATA );
		i++;
	}
	if ( i & 2 ) {
		store<i16>( i, 0, DATA );
		i += 2;
	}
	if ( i & 4 ) {
		store<i32>( i, 0, DATA );
		i += 4;
	}
	while ( i < len ) {
		store<i64>( i, 0, DATA );
		i += 8;
	}
	--i;
	store<i8>( i, ( ( load<i8>( i, DATA ) as i32 ) | 0x80 ) as i8, DATA );

	s00 = 0;
	s01 = 0;
	s02 = 0;
	s03 = 0;
	s04 = 0;
	s05 = 0;
	s06 = 0;
	s07 = 0;
	s08 = 0;
	s09 = 0;
	s10 = 0;
	s11 = 0;
	s12 = 0;
	s13 = 0;
	s14 = 0;
	s15 = 0;
	s16 = 0;
	s17 = 0;
	s18 = 0;
	s19 = 0;
	s20 = 0;
	s21 = 0;
	s22 = 0;
	s23 = 0;
	s24 = 0;

	i = 0;
	do {

		// keccakf

		s00 ^= load<i64>( i, DATA +   0 );
		s01 ^= load<i64>( i, DATA +   8 );
		s02 ^= load<i64>( i, DATA +  16 );
		s03 ^= load<i64>( i, DATA +  24 );
		s04 ^= load<i64>( i, DATA +  32 );
		s05 ^= load<i64>( i, DATA +  40 );
		s06 ^= load<i64>( i, DATA +  48 );
		s07 ^= load<i64>( i, DATA +  56 );
		s08 ^= load<i64>( i, DATA +  64 );
		s09 ^= load<i64>( i, DATA +  72 );
		s10 ^= load<i64>( i, DATA +  80 );
		s11 ^= load<i64>( i, DATA +  88 );
		s12 ^= load<i64>( i, DATA +  96 );
		s13 ^= load<i64>( i, DATA + 104 );
		s14 ^= load<i64>( i, DATA + 112 );
		s15 ^= load<i64>( i, DATA + 120 );
		s16 ^= load<i64>( i, DATA + 128 );

		j = 0;
		do {

			// theta

			b00 = s00 ^ s05 ^ s10 ^ s15 ^ s20;
			b01 = s01 ^ s06 ^ s11 ^ s16 ^ s21;
			b02 = s02 ^ s07 ^ s12 ^ s17 ^ s22;
			b03 = s03 ^ s08 ^ s13 ^ s18 ^ s23;
			b04 = s04 ^ s09 ^ s14 ^ s19 ^ s24;

			ut = b04 ^ ( ( b01 << 1 ) | ( b01 >>> 63 ) );
			s00 ^= ut;
			s05 ^= ut;
			s10 ^= ut;
			s15 ^= ut;
			s20 ^= ut;

			ut = b00 ^ ( ( b02 << 1 ) | ( b02 >>> 63 ) );
			s01 ^= ut;
			s06 ^= ut;
			s11 ^= ut;
			s16 ^= ut;
			s21 ^= ut;

			ut = b01 ^ ( ( b03 << 1 ) | ( b03 >>> 63 ) );
			s02 ^= ut;
			s07 ^= ut;
			s12 ^= ut;
			s17 ^= ut;
			s22 ^= ut;

			ut = b02 ^ ( ( b04 << 1 ) | ( b04 >>> 63 ) );
			s03 ^= ut;
			s08 ^= ut;
			s13 ^= ut;
			s18 ^= ut;
			s23 ^= ut;

			ut = b03 ^ ( ( b00 << 1 ) | ( b00 >>> 63 ) );
			s04 ^= ut;
			s09 ^= ut;
			s14 ^= ut;
			s19 ^= ut;
			s24 ^= ut;

			// rho pi

			b00 = s00;
			b01 = ( s06 << 44 ) | ( s06 >>> 20 );
			b02 = ( s12 << 43 ) | ( s12 >>> 21 );
			b03 = ( s18 << 21 ) | ( s18 >>> 43 );
			b04 = ( s24 << 14 ) | ( s24 >>> 50 );
			b05 = ( s03 << 28 ) | ( s03 >>> 36 );
			b06 = ( s09 << 20 ) | ( s09 >>> 44 );
			b07 = ( s10 <<  3 ) | ( s10 >>> 61 );
			b08 = ( s16 << 45 ) | ( s16 >>> 19 );
			b09 = ( s22 << 61 ) | ( s22 >>>  3 );
			b10 = ( s01 <<  1 ) | ( s01 >>> 63 );
			b11 = ( s07 <<  6 ) | ( s07 >>> 58 );
			b12 = ( s13 << 25 ) | ( s13 >>> 39 );
			b13 = ( s19 <<  8 ) | ( s19 >>> 56 );
			b14 = ( s20 << 18 ) | ( s20 >>> 46 );
			b15 = ( s04 << 27 ) | ( s04 >>> 37 );
			b16 = ( s05 << 36 ) | ( s05 >>> 28 );
			b17 = ( s11 << 10 ) | ( s11 >>> 54 );
			b18 = ( s17 << 15 ) | ( s17 >>> 49 );
			b19 = ( s23 << 56 ) | ( s23 >>>  8 );
			b20 = ( s02 << 62 ) | ( s02 >>>  2 );
			b21 = ( s08 << 55 ) | ( s08 >>>  9 );
			b22 = ( s14 << 39 ) | ( s14 >>> 25 );
			b23 = ( s15 << 41 ) | ( s15 >>> 23 );
			b24 = ( s21 <<  2 ) | ( s21 >>> 62 );

			// chi & iota

			s00 = b00 ^ ( ~b01 & b02 ) ^ load<i64>( j, KECCAK_RNDC );
			s01 = b01 ^ ( ~b02 & b03 );
			s02 = b02 ^ ( ~b03 & b04 );
			s03 = b03 ^ ( ~b04 & b00 );
			s04 = b04 ^ ( ~b00 & b01 );
			s05 = b05 ^ ( ~b06 & b07 );
			s06 = b06 ^ ( ~b07 & b08 );
			s07 = b07 ^ ( ~b08 & b09 );
			s08 = b08 ^ ( ~b09 & b05 );
			s09 = b09 ^ ( ~b05 & b06 );
			s10 = b10 ^ ( ~b11 & b12 );
			s11 = b11 ^ ( ~b12 & b13 );
			s12 = b12 ^ ( ~b13 & b14 );
			s13 = b13 ^ ( ~b14 & b10 );
			s14 = b14 ^ ( ~b10 & b11 );
			s15 = b15 ^ ( ~b16 & b17 );
			s16 = b16 ^ ( ~b17 & b18 );
			s17 = b17 ^ ( ~b18 & b19 );
			s18 = b18 ^ ( ~b19 & b15 );
			s19 = b19 ^ ( ~b15 & b16 );
			s20 = b20 ^ ( ~b21 & b22 );
			s21 = b21 ^ ( ~b22 & b23 );
			s22 = b22 ^ ( ~b23 & b24 );
			s23 = b23 ^ ( ~b24 & b20 );
			s24 = b24 ^ ( ~b20 & b21 );

		} while ( ( j += 8 ) < 192 );

	} while ( ( i += 136 ) < len );

	if ( variant > 0 ) {
		nonce = s24 ^ load<i64>( DATA + 35 );
		store<i64>( 0, nonce );
		block( 0, 8 );
	}

	/*
	 * CryptoNight Step 2:  Iteratively encrypt the results from Keccak to fill
	 * the 2MB large random access buffer.
	 */

	// --------
	// oaes
	// --------

	store<i64>( AES_KEY +  0, s00 );
	store<i64>( AES_KEY +  8, s01 );
	store<i64>( AES_KEY + 16, s02 );
	store<i64>( AES_KEY + 24, s03 );

	i = 8;
	do {

		j = i << 2;

		if ( ( i & 7 ) == 0 ) {

			// rot, sub, mix
			t = ( 1 << ( ( i >>> 3 ) - 1  ) ) ^ (
					( ( load<u8>( load<u8>( j, AES_KEY - 4 ), AES_SUB_BOX ) as i32 ) << 24 ) |
					( ( load<u8>( load<u8>( j, AES_KEY - 1 ), AES_SUB_BOX ) as i32 ) << 16 ) |
					( ( load<u8>( load<u8>( j, AES_KEY - 2 ), AES_SUB_BOX ) as i32 ) <<  8 ) |
					( ( load<u8>( load<u8>( j, AES_KEY - 3 ), AES_SUB_BOX ) as i32 )       )
				);

		} else if ( ( i & 7 ) == 4 ) {

			// sub
			t =		( ( load<u8>( load<u8>( j, AES_KEY - 1 ), AES_SUB_BOX ) as i32 ) << 24 ) |
					( ( load<u8>( load<u8>( j, AES_KEY - 2 ), AES_SUB_BOX ) as i32 ) << 16 ) |
					( ( load<u8>( load<u8>( j, AES_KEY - 3 ), AES_SUB_BOX ) as i32 ) <<  8 ) |
					( ( load<u8>( load<u8>( j, AES_KEY - 4 ), AES_SUB_BOX ) as i32 )       ) ;

		} else {

			t = load<i32>( j, AES_KEY - 4 );

		}

		store<i32>( j, load<i32>( j, AES_KEY - 32 ) ^ t, AES_KEY );

	} while ( ++i < 60 );

	// --------
	// aesb
	// --------

	aes00 = load<i32>( AES_KEY +   0 );
	aes01 = load<i32>( AES_KEY +   4 );
	aes02 = load<i32>( AES_KEY +   8 );
	aes03 = load<i32>( AES_KEY +  12 );
	aes04 = load<i32>( AES_KEY +  16 );
	aes05 = load<i32>( AES_KEY +  20 );
	aes06 = load<i32>( AES_KEY +  24 );
	aes07 = load<i32>( AES_KEY +  28 );
	aes08 = load<i32>( AES_KEY +  32 );
	aes09 = load<i32>( AES_KEY +  36 );
	aes10 = load<i32>( AES_KEY +  40 );
	aes11 = load<i32>( AES_KEY +  44 );
	aes12 = load<i32>( AES_KEY +  48 );
	aes13 = load<i32>( AES_KEY +  52 );
	aes14 = load<i32>( AES_KEY +  56 );
	aes15 = load<i32>( AES_KEY +  60 );
	aes16 = load<i32>( AES_KEY +  64 );
	aes17 = load<i32>( AES_KEY +  68 );
	aes18 = load<i32>( AES_KEY +  72 );
	aes19 = load<i32>( AES_KEY +  76 );
	aes20 = load<i32>( AES_KEY +  80 );
	aes21 = load<i32>( AES_KEY +  84 );
	aes22 = load<i32>( AES_KEY +  88 );
	aes23 = load<i32>( AES_KEY +  92 );
	aes24 = load<i32>( AES_KEY +  96 );
	aes25 = load<i32>( AES_KEY + 100 );
	aes26 = load<i32>( AES_KEY + 104 );
	aes27 = load<i32>( AES_KEY + 108 );
	aes28 = load<i32>( AES_KEY + 112 );
	aes29 = load<i32>( AES_KEY + 116 );
	aes30 = load<i32>( AES_KEY + 120 );
	aes31 = load<i32>( AES_KEY + 124 );
	aes32 = load<i32>( AES_KEY + 128 );
	aes33 = load<i32>( AES_KEY + 132 );
	aes34 = load<i32>( AES_KEY + 136 );
	aes35 = load<i32>( AES_KEY + 140 );
	aes36 = load<i32>( AES_KEY + 144 );
	aes37 = load<i32>( AES_KEY + 148 );
	aes38 = load<i32>( AES_KEY + 152 );
	aes39 = load<i32>( AES_KEY + 156 );

	store<i64>( TEXT_POS +   0, s08 );
	store<i64>( TEXT_POS +   8, s09 );
	store<i64>( TEXT_POS +  16, s10 );
	store<i64>( TEXT_POS +  24, s11 );
	store<i64>( TEXT_POS +  32, s12 );
	store<i64>( TEXT_POS +  40, s13 );
	store<i64>( TEXT_POS +  48, s14 );
	store<i64>( TEXT_POS +  56, s15 );
	store<i64>( TEXT_POS +  64, s16 );
	store<i64>( TEXT_POS +  72, s17 );
	store<i64>( TEXT_POS +  80, s18 );
	store<i64>( TEXT_POS +  88, s19 );
	store<i64>( TEXT_POS +  96, s20 );
	store<i64>( TEXT_POS + 104, s21 );
	store<i64>( TEXT_POS + 112, s22 );
	store<i64>( TEXT_POS + 120, s23 );

	i = 0;
	do {

		j = 0;
		do {

			// 0
			tmp0 = aes00 ^
				load<i32>( ( load<u8>( j, TEXT_POS +  0 ) as i32 ) << 2, AES_T1 ) ^
				load<i32>( ( load<u8>( j, TEXT_POS +  5 ) as i32 ) << 2, AES_T2 ) ^
				load<i32>( ( load<u8>( j, TEXT_POS + 10 ) as i32 ) << 2, AES_T3 ) ^
				load<i32>( ( load<u8>( j, TEXT_POS + 15 ) as i32 ) << 2, AES_T4 ) ;
			tmp1 = aes01 ^
				load<i32>( ( load<u8>( j, TEXT_POS +  4 ) as i32 ) << 2, AES_T1 ) ^
				load<i32>( ( load<u8>( j, TEXT_POS +  9 ) as i32 ) << 2, AES_T2 ) ^
				load<i32>( ( load<u8>( j, TEXT_POS + 14 ) as i32 ) << 2, AES_T3 ) ^
				load<i32>( ( load<u8>( j, TEXT_POS +  3 ) as i32 ) << 2, AES_T4 ) ;
			tmp2 = aes02 ^
				load<i32>( ( load<u8>( j, TEXT_POS +  8 ) as i32 ) << 2, AES_T1 ) ^
				load<i32>( ( load<u8>( j, TEXT_POS + 13 ) as i32 ) << 2, AES_T2 ) ^
				load<i32>( ( load<u8>( j, TEXT_POS +  2 ) as i32 ) << 2, AES_T3 ) ^
				load<i32>( ( load<u8>( j, TEXT_POS +  7 ) as i32 ) << 2, AES_T4 ) ;
			tmp3 = aes03 ^
				load<i32>( ( load<u8>( j, TEXT_POS + 12 ) as i32 ) << 2, AES_T1 ) ^
				load<i32>( ( load<u8>( j, TEXT_POS +  1 ) as i32 ) << 2, AES_T2 ) ^
				load<i32>( ( load<u8>( j, TEXT_POS +  6 ) as i32 ) << 2, AES_T3 ) ^
				load<i32>( ( load<u8>( j, TEXT_POS + 11 ) as i32 ) << 2, AES_T4 ) ;

			// 1
			src0 = aes04 ^
				load<i32>( ( tmp0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src1 = aes05 ^
				load<i32>( ( tmp1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src2 = aes06 ^
				load<i32>( ( tmp2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src3 = aes07 ^
				load<i32>( ( tmp3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 2
			tmp0 = aes08 ^
				load<i32>( ( src0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp1 = aes09 ^
				load<i32>( ( src1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp2 = aes10 ^
				load<i32>( ( src2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp3 = aes11 ^
				load<i32>( ( src3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 3
			src0 = aes12 ^
				load<i32>( ( tmp0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src1 = aes13 ^
				load<i32>( ( tmp1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src2 = aes14 ^
				load<i32>( ( tmp2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src3 = aes15 ^
				load<i32>( ( tmp3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 4
			tmp0 = aes16 ^
				load<i32>( ( src0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp1 = aes17 ^
				load<i32>( ( src1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp2 = aes18 ^
				load<i32>( ( src2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp3 = aes19 ^
				load<i32>( ( src3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 5
			src0 = aes20 ^
				load<i32>( ( tmp0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src1 = aes21 ^
				load<i32>( ( tmp1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src2 = aes22 ^
				load<i32>( ( tmp2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src3 = aes23 ^
				load<i32>( ( tmp3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 6
			tmp0 = aes24 ^
				load<i32>( ( src0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp1 = aes25 ^
				load<i32>( ( src1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp2 = aes26 ^
				load<i32>( ( src2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp3 = aes27 ^
				load<i32>( ( src3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 7
			src0 = aes28 ^
				load<i32>( ( tmp0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src1 = aes29 ^
				load<i32>( ( tmp1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src2 = aes30 ^
				load<i32>( ( tmp2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src3 = aes31 ^
				load<i32>( ( tmp3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 8
			tmp0 = aes32 ^
				load<i32>( ( src0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp1 = aes33 ^
				load<i32>( ( src1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp2 = aes34 ^
				load<i32>( ( src2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp3 = aes35 ^
				load<i32>( ( src3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 9
			src0 = aes36 ^
				load<i32>( ( tmp0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src1 = aes37 ^
				load<i32>( ( tmp1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src2 = aes38 ^
				load<i32>( ( tmp2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src3 = aes39 ^
				load<i32>( ( tmp3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			store<i32>( j, src0, TEXT_POS +  0 );
			store<i32>( j, src1, TEXT_POS +  4 );
			store<i32>( j, src2, TEXT_POS +  8 );
			store<i32>( j, src3, TEXT_POS + 12 );

			store<i32>( i, src0, LONG_TEXT_POS +  0 );
			store<i32>( i, src1, LONG_TEXT_POS +  4 );
			store<i32>( i, src2, LONG_TEXT_POS +  8 );
			store<i32>( i, src3, LONG_TEXT_POS + 12 );

		} while ( ( i += 16 ), ( j += 16 ) < 128 );

	} while ( i < ( 1 << 21 ) );

	/*
	 * CryptoNight Step 3:  Bounce randomly 1,048,576 times (1<<20) through the mixing buffer,
	 * using 524,288 iterations of the following mixing function. Each execution
	 * performs two reads and writes from the mixing buffer.
	 */

	a0 = s00 ^ s04;
	a1 = s01 ^ s05;
	b0 = s02 ^ s06;
	b1 = s03 ^ s07;

	i = 0;
	do {

		/*
		 * Dependency chain: address -> read value ------+
		 * written value <-+ hard function (AES or MUL) <+
		 * next address  <-+
		 */

		/* Iteration 1 */

		k = ( a0 as i32 ) & 0x001FFFF0;

		// aesb

		c0 = a0 ^ (
				load<u32>( ( load<u8>( k, LONG_TEXT_POS +  0 ) as i32 ) << 2, AES_T1 ) as u64 ^
				load<u32>( ( load<u8>( k, LONG_TEXT_POS +  5 ) as i32 ) << 2, AES_T2 ) as u64 ^
				load<u32>( ( load<u8>( k, LONG_TEXT_POS + 10 ) as i32 ) << 2, AES_T3 ) as u64 ^
				load<u32>( ( load<u8>( k, LONG_TEXT_POS + 15 ) as i32 ) << 2, AES_T4 ) as u64
			) ^ ( (
				load<u32>( ( load<u8>( k, LONG_TEXT_POS +  4 ) as i32 ) << 2, AES_T1 ) as u64 ^
				load<u32>( ( load<u8>( k, LONG_TEXT_POS +  9 ) as i32 ) << 2, AES_T2 ) as u64 ^
				load<u32>( ( load<u8>( k, LONG_TEXT_POS + 14 ) as i32 ) << 2, AES_T3 ) as u64 ^
				load<u32>( ( load<u8>( k, LONG_TEXT_POS +  3 ) as i32 ) << 2, AES_T4 ) as u64
			) << 32 );

		c1 = a1 ^ (
				load<u32>( ( load<u8>( k, LONG_TEXT_POS +  8 ) as i32 ) << 2, AES_T1 ) as u64 ^
				load<u32>( ( load<u8>( k, LONG_TEXT_POS + 13 ) as i32 ) << 2, AES_T2 ) as u64 ^
				load<u32>( ( load<u8>( k, LONG_TEXT_POS +  2 ) as i32 ) << 2, AES_T3 ) as u64 ^
				load<u32>( ( load<u8>( k, LONG_TEXT_POS +  7 ) as i32 ) << 2, AES_T4 ) as u64
			) ^ ( (
				load<u32>( ( load<u8>( k, LONG_TEXT_POS + 12 ) as i32 ) << 2, AES_T1 ) as u64 ^
				load<u32>( ( load<u8>( k, LONG_TEXT_POS +  1 ) as i32 ) << 2, AES_T2 ) as u64 ^
				load<u32>( ( load<u8>( k, LONG_TEXT_POS +  6 ) as i32 ) << 2, AES_T3 ) as u64 ^
				load<u32>( ( load<u8>( k, LONG_TEXT_POS + 11 ) as i32 ) << 2, AES_T4 ) as u64
			) << 32 );

		store<i64>( k, b0 ^ c0, LONG_TEXT_POS + 0 );
		store<i64>( k, b1 ^ c1, LONG_TEXT_POS + 8 );

		/* Iteration 2 */

		k = ( c0 as i32 ) & 0x001FFFF0;

		b0 = load<i64>( k, LONG_TEXT_POS + 0 );
		b1 = load<i64>( k, LONG_TEXT_POS + 8 );

		a = c0 >>> 32;
		b = c0 & 0xFFFFFFFF;
		c = b0 >>> 32;
		d = b0 & 0xFFFFFFFF;
		ad = a * d;
		bd = b * d;
		adbc = ad + b * c;

		d = c0 * b0; // d = bd + ( adbc << 32 );

		a0 += a * c + ( adbc >>> 32 ) + ( adbc < ad ? 1 << 32 : 0 ) + ( d < bd ? 1 : 0 );
		a1 += d;

		store<i64>( k, a0, LONG_TEXT_POS + 0 );
		store<i64>( k, a1, LONG_TEXT_POS + 8 );

		a0 ^= b0;
		a1 ^= b1;
		b0 = c0;
		b1 = c1;

	} while ( ++i < 524288 );

	/*
	 * CryptoNight Step 4:  Sequentially pass through the mixing buffer and use 10 rounds
	 * of AES encryption to mix the random data back into the 'text' buffer.  'text'
	 * was originally created with the output of Keccak1600.
	 */

	// --------
	// oaes
	// --------

	store<i64>( AES_KEY +  0, s04 );
	store<i64>( AES_KEY +  8, s05 );
	store<i64>( AES_KEY + 16, s06 );
	store<i64>( AES_KEY + 24, s07 );

	i = 8;
	do {

		j = i << 2;

		if ( ( i & 7 ) == 0 ) {

			// rot, sub, mix
			t = ( 1 << ( ( i >>> 3 ) - 1  ) ) ^ (
					( ( load<u8>( load<u8>( j, AES_KEY - 4 ), AES_SUB_BOX ) as i32 ) << 24 ) |
					( ( load<u8>( load<u8>( j, AES_KEY - 1 ), AES_SUB_BOX ) as i32 ) << 16 ) |
					( ( load<u8>( load<u8>( j, AES_KEY - 2 ), AES_SUB_BOX ) as i32 ) <<  8 ) |
					( ( load<u8>( load<u8>( j, AES_KEY - 3 ), AES_SUB_BOX ) as i32 )       )
				);

		} else if ( ( i & 7 ) == 4 ) {

			// sub
			t =		( ( load<u8>( load<u8>( j, AES_KEY - 1 ), AES_SUB_BOX ) as i32 ) << 24 ) |
					( ( load<u8>( load<u8>( j, AES_KEY - 2 ), AES_SUB_BOX ) as i32 ) << 16 ) |
					( ( load<u8>( load<u8>( j, AES_KEY - 3 ), AES_SUB_BOX ) as i32 ) <<  8 ) |
					( ( load<u8>( load<u8>( j, AES_KEY - 4 ), AES_SUB_BOX ) as i32 )       ) ;

		} else {

			t = load<i32>( j, AES_KEY - 4 );

		}

		store<i32>( j, load<i32>( j, AES_KEY - 32 ) ^ t, AES_KEY );

	} while ( ++i < 60 );

	// --------
	// aesb
	// --------

	aes00 = load<i32>( AES_KEY +   0 );
	aes01 = load<i32>( AES_KEY +   4 );
	aes02 = load<i32>( AES_KEY +   8 );
	aes03 = load<i32>( AES_KEY +  12 );
	aes04 = load<i32>( AES_KEY +  16 );
	aes05 = load<i32>( AES_KEY +  20 );
	aes06 = load<i32>( AES_KEY +  24 );
	aes07 = load<i32>( AES_KEY +  28 );
	aes08 = load<i32>( AES_KEY +  32 );
	aes09 = load<i32>( AES_KEY +  36 );
	aes10 = load<i32>( AES_KEY +  40 );
	aes11 = load<i32>( AES_KEY +  44 );
	aes12 = load<i32>( AES_KEY +  48 );
	aes13 = load<i32>( AES_KEY +  52 );
	aes14 = load<i32>( AES_KEY +  56 );
	aes15 = load<i32>( AES_KEY +  60 );
	aes16 = load<i32>( AES_KEY +  64 );
	aes17 = load<i32>( AES_KEY +  68 );
	aes18 = load<i32>( AES_KEY +  72 );
	aes19 = load<i32>( AES_KEY +  76 );
	aes20 = load<i32>( AES_KEY +  80 );
	aes21 = load<i32>( AES_KEY +  84 );
	aes22 = load<i32>( AES_KEY +  88 );
	aes23 = load<i32>( AES_KEY +  92 );
	aes24 = load<i32>( AES_KEY +  96 );
	aes25 = load<i32>( AES_KEY + 100 );
	aes26 = load<i32>( AES_KEY + 104 );
	aes27 = load<i32>( AES_KEY + 108 );
	aes28 = load<i32>( AES_KEY + 112 );
	aes29 = load<i32>( AES_KEY + 116 );
	aes30 = load<i32>( AES_KEY + 120 );
	aes31 = load<i32>( AES_KEY + 124 );
	aes32 = load<i32>( AES_KEY + 128 );
	aes33 = load<i32>( AES_KEY + 132 );
	aes34 = load<i32>( AES_KEY + 136 );
	aes35 = load<i32>( AES_KEY + 140 );
	aes36 = load<i32>( AES_KEY + 144 );
	aes37 = load<i32>( AES_KEY + 148 );
	aes38 = load<i32>( AES_KEY + 152 );
	aes39 = load<i32>( AES_KEY + 156 );

	store<i64>( TEXT_POS +   0, s08 );
	store<i64>( TEXT_POS +   8, s09 );
	store<i64>( TEXT_POS +  16, s10 );
	store<i64>( TEXT_POS +  24, s11 );
	store<i64>( TEXT_POS +  32, s12 );
	store<i64>( TEXT_POS +  40, s13 );
	store<i64>( TEXT_POS +  48, s14 );
	store<i64>( TEXT_POS +  56, s15 );
	store<i64>( TEXT_POS +  64, s16 );
	store<i64>( TEXT_POS +  72, s17 );
	store<i64>( TEXT_POS +  80, s18 );
	store<i64>( TEXT_POS +  88, s19 );
	store<i64>( TEXT_POS +  96, s20 );
	store<i64>( TEXT_POS + 104, s21 );
	store<i64>( TEXT_POS + 112, s22 );
	store<i64>( TEXT_POS + 120, s23 );

	i = 0;
	do {

		j = 0;
		do {

			src0 = load<i32>( j, TEXT_POS +  0 ) ^ load<i32>( i, LONG_TEXT_POS +  0 );
			src1 = load<i32>( j, TEXT_POS +  4 ) ^ load<i32>( i, LONG_TEXT_POS +  4 );
			src2 = load<i32>( j, TEXT_POS +  8 ) ^ load<i32>( i, LONG_TEXT_POS +  8 );
			src3 = load<i32>( j, TEXT_POS + 12 ) ^ load<i32>( i, LONG_TEXT_POS + 12 );

			// 0
			tmp0 = aes00 ^
				load<i32>( ( src0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp1 = aes01 ^
				load<i32>( ( src1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp2 = aes02 ^
				load<i32>( ( src2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp3 = aes03 ^
				load<i32>( ( src3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 1
			src0 = aes04 ^
				load<i32>( ( tmp0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src1 = aes05 ^
				load<i32>( ( tmp1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src2 = aes06 ^
				load<i32>( ( tmp2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src3 = aes07 ^
				load<i32>( ( tmp3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 2
			tmp0 = aes08 ^
				load<i32>( ( src0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp1 = aes09 ^
				load<i32>( ( src1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp2 = aes10 ^
				load<i32>( ( src2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp3 = aes11 ^
				load<i32>( ( src3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 3
			src0 = aes12 ^
				load<i32>( ( tmp0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src1 = aes13 ^
				load<i32>( ( tmp1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src2 = aes14 ^
				load<i32>( ( tmp2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src3 = aes15 ^
				load<i32>( ( tmp3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 4
			tmp0 = aes16 ^
				load<i32>( ( src0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp1 = aes17 ^
				load<i32>( ( src1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp2 = aes18 ^
				load<i32>( ( src2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp3 = aes19 ^
				load<i32>( ( src3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 5
			src0 = aes20 ^
				load<i32>( ( tmp0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src1 = aes21 ^
				load<i32>( ( tmp1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src2 = aes22 ^
				load<i32>( ( tmp2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src3 = aes23 ^
				load<i32>( ( tmp3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 6
			tmp0 = aes24 ^
				load<i32>( ( src0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp1 = aes25 ^
				load<i32>( ( src1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp2 = aes26 ^
				load<i32>( ( src2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp3 = aes27 ^
				load<i32>( ( src3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 7
			src0 = aes28 ^
				load<i32>( ( tmp0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src1 = aes29 ^
				load<i32>( ( tmp1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src2 = aes30 ^
				load<i32>( ( tmp2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			src3 = aes31 ^
				load<i32>( ( tmp3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 8
			tmp0 = aes32 ^
				load<i32>( ( src0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src3 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp1 = aes33 ^
				load<i32>( ( src1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src0 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp2 = aes34 ^
				load<i32>( ( src2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src1 >>> 22 ) & 0x3FC, AES_T4 ) ;
			tmp3 = aes35 ^
				load<i32>( ( src3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( src0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( src1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( src2 >>> 22 ) & 0x3FC, AES_T4 ) ;

			// 9
			store<i32>( j, aes36 ^
				load<i32>( ( tmp0  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp1 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp2 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp3 >>> 22 ) & 0x3FC, AES_T4 ) ,
			TEXT_POS + 0 );
			store<i32>( j, aes37 ^
				load<i32>( ( tmp1  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp2 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp3 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp0 >>> 22 ) & 0x3FC, AES_T4 ) ,
			TEXT_POS + 4 );
			store<i32>( j, aes38 ^
				load<i32>( ( tmp2  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp3 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp0 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp1 >>> 22 ) & 0x3FC, AES_T4 ) ,
			TEXT_POS + 8 );
			store<i32>( j, aes39 ^
				load<i32>( ( tmp3  <<  2 ) & 0x3FC, AES_T1 ) ^
				load<i32>( ( tmp0 >>>  6 ) & 0x3FC, AES_T2 ) ^
				load<i32>( ( tmp1 >>> 14 ) & 0x3FC, AES_T3 ) ^
				load<i32>( ( tmp2 >>> 22 ) & 0x3FC, AES_T4 ) ,
			TEXT_POS + 12 );

		} while ( ( i += 16 ), ( j += 16 ) < 128 );

	} while ( i < ( 1 << 21 ) );

	/*
	 * CryptoNight Step 5:  Apply Keccak to the state again, and then
	 * use the resulting data to select which of four finalizer
	 * hash functions to apply to the data (Blake, Groestl, JH, or Skein).
	 * Use this hash to squeeze the state array down
	 * to the final 256 bit hash output.
	 */

	// --------
	// keccakf
	// --------

	s08 = load<i64>( TEXT_POS +   0 );
	s09 = load<i64>( TEXT_POS +   8 );
	s10 = load<i64>( TEXT_POS +  16 );
	s11 = load<i64>( TEXT_POS +  24 );
	s12 = load<i64>( TEXT_POS +  32 );
	s13 = load<i64>( TEXT_POS +  40 );
	s14 = load<i64>( TEXT_POS +  48 );
	s15 = load<i64>( TEXT_POS +  56 );
	s16 = load<i64>( TEXT_POS +  64 );
	s17 = load<i64>( TEXT_POS +  72 );
	s18 = load<i64>( TEXT_POS +  80 );
	s19 = load<i64>( TEXT_POS +  88 );
	s20 = load<i64>( TEXT_POS +  96 );
	s21 = load<i64>( TEXT_POS + 104 );
	s22 = load<i64>( TEXT_POS + 112 );
	s23 = load<i64>( TEXT_POS + 120 );

	j = 0;
	do {

		// theta

		b00 = s00 ^ s05 ^ s10 ^ s15 ^ s20;
		b01 = s01 ^ s06 ^ s11 ^ s16 ^ s21;
		b02 = s02 ^ s07 ^ s12 ^ s17 ^ s22;
		b03 = s03 ^ s08 ^ s13 ^ s18 ^ s23;
		b04 = s04 ^ s09 ^ s14 ^ s19 ^ s24;

		ut = b04 ^ ( ( b01 << 1 ) | ( b01 >>> 63 ) );
		s00 ^= ut;
		s05 ^= ut;
		s10 ^= ut;
		s15 ^= ut;
		s20 ^= ut;

		ut = b00 ^ ( ( b02 << 1 ) | ( b02 >>> 63 ) );
		s01 ^= ut;
		s06 ^= ut;
		s11 ^= ut;
		s16 ^= ut;
		s21 ^= ut;

		ut = b01 ^ ( ( b03 << 1 ) | ( b03 >>> 63 ) );
		s02 ^= ut;
		s07 ^= ut;
		s12 ^= ut;
		s17 ^= ut;
		s22 ^= ut;

		ut = b02 ^ ( ( b04 << 1 ) | ( b04 >>> 63 ) );
		s03 ^= ut;
		s08 ^= ut;
		s13 ^= ut;
		s18 ^= ut;
		s23 ^= ut;

		ut = b03 ^ ( ( b00 << 1 ) | ( b00 >>> 63 ) );
		s04 ^= ut;
		s09 ^= ut;
		s14 ^= ut;
		s19 ^= ut;
		s24 ^= ut;

		// rho pi

		b00 = s00;
		b01 = ( s06 << 44 ) | ( s06 >>> 20 );
		b02 = ( s12 << 43 ) | ( s12 >>> 21 );
		b03 = ( s18 << 21 ) | ( s18 >>> 43 );
		b04 = ( s24 << 14 ) | ( s24 >>> 50 );
		b05 = ( s03 << 28 ) | ( s03 >>> 36 );
		b06 = ( s09 << 20 ) | ( s09 >>> 44 );
		b07 = ( s10 <<  3 ) | ( s10 >>> 61 );
		b08 = ( s16 << 45 ) | ( s16 >>> 19 );
		b09 = ( s22 << 61 ) | ( s22 >>>  3 );
		b10 = ( s01 <<  1 ) | ( s01 >>> 63 );
		b11 = ( s07 <<  6 ) | ( s07 >>> 58 );
		b12 = ( s13 << 25 ) | ( s13 >>> 39 );
		b13 = ( s19 <<  8 ) | ( s19 >>> 56 );
		b14 = ( s20 << 18 ) | ( s20 >>> 46 );
		b15 = ( s04 << 27 ) | ( s04 >>> 37 );
		b16 = ( s05 << 36 ) | ( s05 >>> 28 );
		b17 = ( s11 << 10 ) | ( s11 >>> 54 );
		b18 = ( s17 << 15 ) | ( s17 >>> 49 );
		b19 = ( s23 << 56 ) | ( s23 >>>  8 );
		b20 = ( s02 << 62 ) | ( s02 >>>  2 );
		b21 = ( s08 << 55 ) | ( s08 >>>  9 );
		b22 = ( s14 << 39 ) | ( s14 >>> 25 );
		b23 = ( s15 << 41 ) | ( s15 >>> 23 );
		b24 = ( s21 <<  2 ) | ( s21 >>> 62 );

		// chi & iota

		s00 = b00 ^ ( ~b01 & b02 ) ^ load<i64>( j, KECCAK_RNDC );
		s01 = b01 ^ ( ~b02 & b03 );
		s02 = b02 ^ ( ~b03 & b04 );
		s03 = b03 ^ ( ~b04 & b00 );
		s04 = b04 ^ ( ~b00 & b01 );
		s05 = b05 ^ ( ~b06 & b07 );
		s06 = b06 ^ ( ~b07 & b08 );
		s07 = b07 ^ ( ~b08 & b09 );
		s08 = b08 ^ ( ~b09 & b05 );
		s09 = b09 ^ ( ~b05 & b06 );
		s10 = b10 ^ ( ~b11 & b12 );
		s11 = b11 ^ ( ~b12 & b13 );
		s12 = b12 ^ ( ~b13 & b14 );
		s13 = b13 ^ ( ~b14 & b10 );
		s14 = b14 ^ ( ~b10 & b11 );
		s15 = b15 ^ ( ~b16 & b17 );
		s16 = b16 ^ ( ~b17 & b18 );
		s17 = b17 ^ ( ~b18 & b19 );
		s18 = b18 ^ ( ~b19 & b15 );
		s19 = b19 ^ ( ~b15 & b16 );
		s20 = b20 ^ ( ~b21 & b22 );
		s21 = b21 ^ ( ~b22 & b23 );
		s22 = b22 ^ ( ~b23 & b24 );
		s23 = b23 ^ ( ~b24 & b20 );
		s24 = b24 ^ ( ~b20 & b21 );

	} while ( ( j += 8 ) < 192 );

	store<i64>( TEXT_POS +   0, s00 );
	store<i64>( TEXT_POS +   8, s01 );
	store<i64>( TEXT_POS +  16, s02 );
	store<i64>( TEXT_POS +  24, s03 );
	store<i64>( TEXT_POS +  32, s04 );
	store<i64>( TEXT_POS +  40, s05 );
	store<i64>( TEXT_POS +  48, s06 );
	store<i64>( TEXT_POS +  56, s07 );
	store<i64>( TEXT_POS +  64, s08 );
	store<i64>( TEXT_POS +  72, s09 );
	store<i64>( TEXT_POS +  80, s10 );
	store<i64>( TEXT_POS +  88, s11 );
	store<i64>( TEXT_POS +  96, s12 );
	store<i64>( TEXT_POS + 104, s13 );
	store<i64>( TEXT_POS + 112, s14 );
	store<i64>( TEXT_POS + 120, s15 );
	store<i64>( TEXT_POS + 128, s16 );
	store<i64>( TEXT_POS + 136, s17 );
	store<i64>( TEXT_POS + 144, s18 );
	store<i64>( TEXT_POS + 152, s19 );
	store<i64>( TEXT_POS + 160, s20 );
	store<i64>( TEXT_POS + 168, s21 );
	store<i64>( TEXT_POS + 176, s22 );
	store<i64>( TEXT_POS + 184, s23 );
	store<i64>( TEXT_POS + 192, s24 );

	k = ( load<u8>( TEXT_POS ) as i32 ) & 3;

	// ========
	// BLAKE
	// --------
	if ( k == 0 ) {

		// padding

		store<i64>( TEXT_KEC +  0, 0x0000000000000080 );
		store<i64>( TEXT_KEC +  8, 0x0000000000000000 );
		store<i64>( TEXT_KEC + 16, 0x0000000000000000 );
		store<i64>( TEXT_KEC + 24, 0x0000000000000000 );
		store<i64>( TEXT_KEC + 32, 0x0000000000000000 );
		store<i64>( TEXT_KEC + 40, 0x0100000000000000 );
		store<i64>( TEXT_KEC + 48, 0x4006000000000000 );

		// compress

		let h0:u32 = 0x6A09E667;
		let h1:u32 = 0xBB67AE85;
		let h2:u32 = 0x3C6EF372;
		let h3:u32 = 0xA54FF53A;
		let h4:u32 = 0x510E527F;
		let h5:u32 = 0x9B05688C;
		let h6:u32 = 0x1F83D9AB;
		let h7:u32 = 0x5BE0CD19;

		let v00:u32;
		let v01:u32;
		let v02:u32;
		let v03:u32;
		let v04:u32;
		let v05:u32;
		let v06:u32;
		let v07:u32;
		let v08:u32;
		let v09:u32;
		let v10:u32;
		let v11:u32;
		let v12:u32;
		let v13:u32;
		let v14:u32;
		let v15:u32;

		let sg0:i32;
		let sg1:i32;

		t = 0;
		i = 0;
		do {

			t += 512; if ( t > 1600 ) t = 1600;

			j = 0;
			do {
				store<i8>( j, load<i8>( i, TEXT_POS + 3 ), BLAKE_M + 0 );
				store<i8>( j, load<i8>( i, TEXT_POS + 2 ), BLAKE_M + 1 );
				store<i8>( j, load<i8>( i, TEXT_POS + 1 ), BLAKE_M + 2 );
				store<i8>( j, load<i8>( i, TEXT_POS + 0 ), BLAKE_M + 3 );
			} while ( ( i += 4 ), ( j += 4 ) < 64 );

			v00 = h0;
			v01 = h1;
			v02 = h2;
			v03 = h3;
			v04 = h4;
			v05 = h5;
			v06 = h6;
			v07 = h7;
			v08 = 0x243F6A88;
			v09 = 0x85A308D3;
			v10 = 0x13198A2E;
			v11 = 0x03707344;
			v12 = 0xA4093822 ^ t;
			v13 = 0x299F31D0 ^ t;
			v14 = 0x082EFA98;
			v15 = 0xEC4E6C89;

			j = 0;
			do {

				// 0, 4, 8, 12, 0

				sg0 = load<u8>( j, BLAKE_SIGMA + 0 ) as i32;
				sg1 = load<u8>( j, BLAKE_SIGMA + 1 ) as i32;

				v00 += ( load<u32>( sg0, BLAKE_M ) ^ load<u32>( sg1, BLAKE_CST ) ) + v04;
				v12 ^= v00;
				v12 = ( v12 << 16 ) | ( v12 >>> 16 );
				v08 += v12;
				v04 ^= v08;
				v04 = ( v04 << 20 ) | ( v04 >>> 12 );
				v00 += ( load<u32>( sg1, BLAKE_M ) ^ load<u32>( sg0, BLAKE_CST ) ) + v04;
				v12 ^= v00;
				v12 = ( v12 << 24 ) | ( v12 >>> 8 );
				v08 += v12;
				v04 ^= v08;
				v04 = ( v04 << 25 ) | ( v04 >>> 7 );

				// 1, 5, 9, 13, 2

				sg0 = load<u8>( j, BLAKE_SIGMA + 2 ) as i32;
				sg1 = load<u8>( j, BLAKE_SIGMA + 3 ) as i32;

				v01 += ( load<u32>( sg0, BLAKE_M ) ^ load<u32>( sg1, BLAKE_CST ) ) + v05;
				v13 ^= v01;
				v13 = ( v13 << 16 ) | ( v13 >>> 16 );
				v09 += v13;
				v05 ^= v09;
				v05 = ( v05 << 20 ) | ( v05 >>> 12 );
				v01 += ( load<u32>( sg1, BLAKE_M ) ^ load<u32>( sg0, BLAKE_CST ) ) + v05;
				v13 ^= v01;
				v13 = ( v13 << 24 ) | ( v13 >>> 8 );
				v09 += v13;
				v05 ^= v09;
				v05 = ( v05 << 25 ) | ( v05 >>> 7 );

				//  2, 6, 10, 14, 4

				sg0 = load<u8>( j, BLAKE_SIGMA + 4 ) as i32;
				sg1 = load<u8>( j, BLAKE_SIGMA + 5 ) as i32;

				v02 += ( load<u32>( sg0, BLAKE_M ) ^ load<u32>( sg1, BLAKE_CST ) ) + v06;
				v14 ^= v02;
				v14 = ( v14 << 16 ) | ( v14 >>> 16 );
				v10 += v14;
				v06 ^= v10;
				v06 = ( v06 << 20 ) | ( v06 >>> 12 );
				v02 += ( load<u32>( sg1, BLAKE_M ) ^ load<u32>( sg0, BLAKE_CST ) ) + v06;
				v14 ^= v02;
				v14 = ( v14 << 24 ) | ( v14 >>> 8 );
				v10 += v14;
				v06 ^= v10;
				v06 = ( v06 << 25 ) | ( v06 >>> 7 );

				// 3, 7, 11, 15, 6

				sg0 = load<u8>( j, BLAKE_SIGMA + 6 ) as i32;
				sg1 = load<u8>( j, BLAKE_SIGMA + 7 ) as i32;

				v03 += ( load<u32>( sg0, BLAKE_M ) ^ load<u32>( sg1, BLAKE_CST ) ) + v07;
				v15 ^= v03;
				v15 = ( v15 << 16 ) | ( v15 >>> 16 );
				v11 += v15;
				v07 ^= v11;
				v07 = ( v07 << 20 ) | ( v07 >>> 12 );
				v03 += ( load<u32>( sg1, BLAKE_M ) ^ load<u32>( sg0, BLAKE_CST ) ) + v07;
				v15 ^= v03;
				v15 = ( v15 << 24 ) | ( v15 >>> 8 );
				v11 += v15;
				v07 ^= v11;
				v07 = ( v07 << 25 ) | ( v07 >>> 7 );

				// 3, 4,  9, 14, 14

				sg0 = load<u8>( j, BLAKE_SIGMA + 14 ) as i32;
				sg1 = load<u8>( j, BLAKE_SIGMA + 15 ) as i32;

				v03 += ( load<u32>( sg0, BLAKE_M ) ^ load<u32>( sg1, BLAKE_CST ) ) + v04;
				v14 ^= v03;
				v14 = ( v14 << 16 ) | ( v14 >>> 16 );
				v09 += v14;
				v04 ^= v09;
				v04 = ( v04 << 20 ) | ( v04 >>> 12 );
				v03 += ( load<u32>( sg1, BLAKE_M ) ^ load<u32>( sg0, BLAKE_CST ) ) + v04;
				v14 ^= v03;
				v14 = ( v14 << 24 ) | ( v14 >>> 8 );
				v09 += v14;
				v04 ^= v09;
				v04 = ( v04 << 25 ) | ( v04 >>> 7 );

				// 2, 7, 8, 13, 12

				sg0 = load<u8>( j, BLAKE_SIGMA + 12 ) as i32;
				sg1 = load<u8>( j, BLAKE_SIGMA + 13 ) as i32;

				v02 += ( load<u32>( sg0, BLAKE_M ) ^ load<u32>( sg1, BLAKE_CST ) ) + v07;
				v13 ^= v02;
				v13 = ( v13 << 16 ) | ( v13 >>> 16 );
				v08 += v13;
				v07 ^= v08;
				v07 = ( v07 << 20 ) | ( v07 >>> 12 );
				v02 += ( load<u32>( sg1, BLAKE_M ) ^ load<u32>( sg0, BLAKE_CST ) ) + v07;
				v13 ^= v02;
				v13 = ( v13 << 24 ) | ( v13 >>> 8 );
				v08 += v13;
				v07 ^= v08;
				v07 = ( v07 << 25 ) | ( v07 >>> 7 );

				// 0, 5, 10, 15, 8

				sg0 = load<u8>( j, BLAKE_SIGMA + 8 ) as i32;
				sg1 = load<u8>( j, BLAKE_SIGMA + 9 ) as i32;

				v00 += ( load<u32>( sg0, BLAKE_M ) ^ load<u32>( sg1, BLAKE_CST ) ) + v05;
				v15 ^= v00;
				v15 = ( v15 << 16 ) | ( v15 >>> 16 );
				v10 += v15;
				v05 ^= v10;
				v05 = ( v05 << 20 ) | ( v05 >>> 12 );
				v00 += ( load<u32>( sg1, BLAKE_M ) ^ load<u32>( sg0, BLAKE_CST ) ) + v05;
				v15 ^= v00;
				v15 = ( v15 << 24 ) | ( v15 >>> 8 );
				v10 += v15;
				v05 ^= v10;
				v05 = ( v05 << 25 ) | ( v05 >>> 7 );

				// 1, 6, 11, 12, 10

				sg0 = load<u8>( j, BLAKE_SIGMA + 10 ) as i32;
				sg1 = load<u8>( j, BLAKE_SIGMA + 11 ) as i32;

				v01 += ( load<u32>( sg0, BLAKE_M ) ^ load<u32>( sg1, BLAKE_CST ) ) + v06;
				v12 ^= v01;
				v12 = ( v12 << 16 ) | ( v12 >>> 16 );
				v11 += v12;
				v06 ^= v11;
				v06 = ( v06 << 20 ) | ( v06 >>> 12 );
				v01 += ( load<u32>( sg1, BLAKE_M ) ^ load<u32>( sg0, BLAKE_CST ) ) + v06;
				v12 ^= v01;
				v12 = ( v12 << 24 ) | ( v12 >>> 8 );
				v11 += v12;
				v06 ^= v11;
				v06 = ( v06 << 25 ) | ( v06 >>> 7 );

			} while ( ( j += 16 ) < 224 );

			h0 ^= v00 ^ v08;
			h1 ^= v01 ^ v09;
			h2 ^= v02 ^ v10;
			h3 ^= v03 ^ v11;
			h4 ^= v04 ^ v12;
			h5 ^= v05 ^ v13;
			h6 ^= v06 ^ v14;
			h7 ^= v07 ^ v15;

		} while ( i < 256 );

		store<u32>( BLAKE_M +  0, h0 );
		store<u32>( BLAKE_M +  4, h1 );
		store<u32>( BLAKE_M +  8, h2 );
		store<u32>( BLAKE_M + 12, h3 );
		store<u32>( BLAKE_M + 16, h4 );
		store<u32>( BLAKE_M + 20, h5 );
		store<u32>( BLAKE_M + 24, h6 );
		store<u32>( BLAKE_M + 28, h7 );

		j = 0;
		do {
			store<i8>( j, load<i8>( j, BLAKE_M + 3 ), DATA + 0 );
			store<i8>( j, load<i8>( j, BLAKE_M + 2 ), DATA + 1 );
			store<i8>( j, load<i8>( j, BLAKE_M + 1 ), DATA + 2 );
			store<i8>( j, load<i8>( j, BLAKE_M + 0 ), DATA + 3 );
		} while ( ( j += 4 ) < 32 );

	}

	// ========
	// GROESTL
	// --------
	else if ( k == 1 ) {

		// padding

		store<i64>( TEXT_KEC +  0, 0x0000000000000080 );
		store<i64>( TEXT_KEC +  8, 0x0000000000000000 );
		store<i64>( TEXT_KEC + 16, 0x0000000000000000 );
		store<i64>( TEXT_KEC + 24, 0x0000000000000000 );
		store<i64>( TEXT_KEC + 32, 0x0000000000000000 );
		store<i64>( TEXT_KEC + 40, 0x0000000000000000 );
		store<i64>( TEXT_KEC + 48, 0x0400000000000000 );

		// compress

		let c0:i64 = 0;
		let c1:i64 = 0;
		let c2:i64 = 0;
		let c3:i64 = 0;
		let c4:i64 = 0;
		let c5:i64 = 0;
		let c6:i64 = 0;
		let c7:i64 = 0x0001000000000000;

		let q0:i64;
		let q1:i64;
		let q2:i64;
		let q3:i64;
		let q4:i64;
		let q5:i64;
		let q6:i64;
		let q7:i64;

		let p0:i64;
		let p1:i64;
		let p2:i64;
		let p3:i64;
		let p4:i64;
		let p5:i64;
		let p6:i64;
		let p7:i64;

		let x0:i64;
		let x1:i64;
		let x2:i64;
		let x3:i64;
		let x4:i64;
		let x5:i64;
		let x6:i64;
		let x7:i64;

		i = 0;
		do {

			q0 = load<i64>( i, TEXT_POS +  0 );
			q1 = load<i64>( i, TEXT_POS +  8 );
			q2 = load<i64>( i, TEXT_POS + 16 );
			q3 = load<i64>( i, TEXT_POS + 24 );
			q4 = load<i64>( i, TEXT_POS + 32 );
			q5 = load<i64>( i, TEXT_POS + 40 );
			q6 = load<i64>( i, TEXT_POS + 48 );
			q7 = load<i64>( i, TEXT_POS + 56 );

			p0 = c0 ^ q0;
			p1 = c1 ^ q1;
			p2 = c2 ^ q2;
			p3 = c3 ^ q3;
			p4 = c4 ^ q4;
			p5 = c5 ^ q5;
			p6 = c6 ^ q6;
			p7 = c7 ^ q7;

			// compute Q
			ut = 0x0000000000000000;
			do {

				q0 ^= ~0x0000000000000000 ^ ut;
				q1 ^= ~0x1000000000000000 ^ ut;
				q2 ^= ~0x2000000000000000 ^ ut;
				q3 ^= ~0x3000000000000000 ^ ut;
				q4 ^= ~0x4000000000000000 ^ ut;
				q5 ^= ~0x5000000000000000 ^ ut;
				q6 ^= ~0x6000000000000000 ^ ut;
				q7 ^= ~0x7000000000000000 ^ ut;

				x0 =
					load<i64>( ( ( q1  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( q3 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( q5 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( q7 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( q0 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( q2 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( q4 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( q6 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				x1 =
					load<i64>( ( ( q2  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( q4 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( q6 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( q0 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( q1 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( q3 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( q5 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( q7 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				x2 =
					load<i64>( ( ( q3  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( q5 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( q7 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( q1 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( q2 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( q4 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( q6 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( q0 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				x3 =
					load<i64>( ( ( q4  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( q6 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( q0 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( q2 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( q3 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( q5 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( q7 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( q1 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				x4 =
					load<i64>( ( ( q5  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( q7 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( q1 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( q3 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( q4 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( q6 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( q0 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( q2 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				x5 =
					load<i64>( ( ( q6  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( q0 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( q2 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( q4 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( q5 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( q7 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( q1 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( q3 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				x6 =
					load<i64>( ( ( q7  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( q1 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( q3 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( q5 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( q6 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( q0 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( q2 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( q4 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				x7 =
					load<i64>( ( ( q0  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( q2 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( q4 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( q6 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( q7 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( q1 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( q3 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( q5 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				q0 = x0;
				q1 = x1;
				q2 = x2;
				q3 = x3;
				q4 = x4;
				q5 = x5;
				q6 = x6;
				q7 = x7;

			} while ( ( ut += 0x0100000000000000 ) < 0x0A00000000000000 );

			// compute P
			ut = 0x0000000000000000;
			do {

				p0 ^= 0x0000000000000000 ^ ut;
				p1 ^= 0x0000000000000010 ^ ut;
				p2 ^= 0x0000000000000020 ^ ut;
				p3 ^= 0x0000000000000030 ^ ut;
				p4 ^= 0x0000000000000040 ^ ut;
				p5 ^= 0x0000000000000050 ^ ut;
				p6 ^= 0x0000000000000060 ^ ut;
				p7 ^= 0x0000000000000070 ^ ut;

				x0 =
					load<i64>( ( ( p0  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( p1 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( p2 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( p3 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( p4 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( p5 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( p6 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( p7 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				x1 =
					load<i64>( ( ( p1  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( p2 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( p3 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( p4 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( p5 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( p6 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( p7 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( p0 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				x2 =
					load<i64>( ( ( p2  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( p3 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( p4 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( p5 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( p6 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( p7 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( p0 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( p1 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				x3 =
					load<i64>( ( ( p3  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( p4 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( p5 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( p6 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( p7 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( p0 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( p1 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( p2 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				x4 =
					load<i64>( ( ( p4  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( p5 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( p6 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( p7 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( p0 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( p1 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( p2 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( p3 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				x5 =
					load<i64>( ( ( p5  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( p6 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( p7 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( p0 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( p1 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( p2 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( p3 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( p4 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				x6 =
					load<i64>( ( ( p6  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( p7 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( p0 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( p1 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( p2 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( p3 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( p4 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( p5 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				x7 =
					load<i64>( ( ( p7  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
					load<i64>( ( ( p0 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
					load<i64>( ( ( p1 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
					load<i64>( ( ( p2 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
					load<i64>( ( ( p3 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
					load<i64>( ( ( p4 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
					load<i64>( ( ( p5 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
					load<i64>( ( ( p6 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

				p0 = x0;
				p1 = x1;
				p2 = x2;
				p3 = x3;
				p4 = x4;
				p5 = x5;
				p6 = x6;
				p7 = x7;

			} while ( ( ut += 0x0000000000000001 ) < 0x000000000000000A );

			// compute P + Q + C
			c0 ^= p0 ^ q0;
			c1 ^= p1 ^ q1;
			c2 ^= p2 ^ q2;
			c3 ^= p3 ^ q3;
			c4 ^= p4 ^ q4;
			c5 ^= p5 ^ q5;
			c6 ^= p6 ^ q6;
			c7 ^= p7 ^ q7;

		} while ( ( i += 64 ) < 256 );

		p0 = c0;
		p1 = c1;
		p2 = c2;
		p3 = c3;
		p4 = c4;
		p5 = c5;
		p6 = c6;
		p7 = c7;

		// compute P
		ut = 0x0000000000000000;
		do {

			p0 ^= 0x0000000000000000 ^ ut;
			p1 ^= 0x0000000000000010 ^ ut;
			p2 ^= 0x0000000000000020 ^ ut;
			p3 ^= 0x0000000000000030 ^ ut;
			p4 ^= 0x0000000000000040 ^ ut;
			p5 ^= 0x0000000000000050 ^ ut;
			p6 ^= 0x0000000000000060 ^ ut;
			p7 ^= 0x0000000000000070 ^ ut;

			x0 =
				load<i64>( ( ( p0  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
				load<i64>( ( ( p1 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
				load<i64>( ( ( p2 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
				load<i64>( ( ( p3 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
				load<i64>( ( ( p4 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
				load<i64>( ( ( p5 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
				load<i64>( ( ( p6 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
				load<i64>( ( ( p7 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

			x1 =
				load<i64>( ( ( p1  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
				load<i64>( ( ( p2 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
				load<i64>( ( ( p3 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
				load<i64>( ( ( p4 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
				load<i64>( ( ( p5 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
				load<i64>( ( ( p6 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
				load<i64>( ( ( p7 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
				load<i64>( ( ( p0 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

			x2 =
				load<i64>( ( ( p2  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
				load<i64>( ( ( p3 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
				load<i64>( ( ( p4 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
				load<i64>( ( ( p5 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
				load<i64>( ( ( p6 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
				load<i64>( ( ( p7 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
				load<i64>( ( ( p0 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
				load<i64>( ( ( p1 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

			x3 =
				load<i64>( ( ( p3  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
				load<i64>( ( ( p4 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
				load<i64>( ( ( p5 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
				load<i64>( ( ( p6 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
				load<i64>( ( ( p7 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
				load<i64>( ( ( p0 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
				load<i64>( ( ( p1 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
				load<i64>( ( ( p2 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

			x4 =
				load<i64>( ( ( p4  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
				load<i64>( ( ( p5 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
				load<i64>( ( ( p6 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
				load<i64>( ( ( p7 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
				load<i64>( ( ( p0 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
				load<i64>( ( ( p1 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
				load<i64>( ( ( p2 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
				load<i64>( ( ( p3 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

			x5 =
				load<i64>( ( ( p5  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
				load<i64>( ( ( p6 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
				load<i64>( ( ( p7 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
				load<i64>( ( ( p0 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
				load<i64>( ( ( p1 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
				load<i64>( ( ( p2 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
				load<i64>( ( ( p3 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
				load<i64>( ( ( p4 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

			x6 =
				load<i64>( ( ( p6  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
				load<i64>( ( ( p7 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
				load<i64>( ( ( p0 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
				load<i64>( ( ( p1 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
				load<i64>( ( ( p2 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
				load<i64>( ( ( p3 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
				load<i64>( ( ( p4 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
				load<i64>( ( ( p5 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

			x7 =
				load<i64>( ( ( p7  <<  3 ) as u32 ) & 0x7F8, GROSTL_T0 ) ^
				load<i64>( ( ( p0 >>>  5 ) as u32 ) & 0x7F8, GROSTL_T1 ) ^
				load<i64>( ( ( p1 >>> 13 ) as u32 ) & 0x7F8, GROSTL_T2 ) ^
				load<i64>( ( ( p2 >>> 21 ) as u32 ) & 0x7F8, GROSTL_T3 ) ^
				load<i64>( ( ( p3 >>> 29 ) as u32 ) & 0x7F8, GROSTL_T4 ) ^
				load<i64>( ( ( p4 >>> 37 ) as u32 ) & 0x7F8, GROSTL_T5 ) ^
				load<i64>( ( ( p5 >>> 45 ) as u32 ) & 0x7F8, GROSTL_T6 ) ^
				load<i64>( ( ( p6 >>> 53 ) as u32 ) & 0x7F8, GROSTL_T7 ) ;

			p0 = x0;
			p1 = x1;
			p2 = x2;
			p3 = x3;
			p4 = x4;
			p5 = x5;
			p6 = x6;
			p7 = x7;

		} while ( ( ut += 0x0000000000000001 ) < 0x000000000000000A );

		store<i64>( DATA +  0, c4 ^ p4 );
		store<i64>( DATA +  8, c5 ^ p5 );
		store<i64>( DATA + 16, c6 ^ p6 );
		store<i64>( DATA + 24, c7 ^ p7 );

	}

	// ========
	// JH
	// --------
	else if ( k == 2 ) {

		// padding

		store<i64>( TEXT_KEC +   0, 0x0000000000000080 );
		store<i64>( TEXT_KEC +   8, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  16, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  24, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  32, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  40, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  48, 0x0000000000000000 );

		store<i64>( TEXT_KEC +  56, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  64, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  72, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  80, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  88, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  96, 0x0000000000000000 );
		store<i64>( TEXT_KEC + 104, 0x0000000000000000 );
		store<i64>( TEXT_KEC + 112, 0x4006000000000000 );

		// compress

		let s0:i64;
		let s1:i64;

		let x00:i64 = 0xEBD3202C41A398EB;
		let x01:i64 = 0xC145B29C7BBECD92;
		let x10:i64 = 0xFAC7D4609151931C;
		let x11:i64 = 0x038A507ED6820026;
		let x20:i64 = 0x45B92677269E23A4;
		let x21:i64 = 0x77941AD4481AFBE0;
		let x30:i64 = 0x7A176B0226ABB5CD;
		let x31:i64 = 0xA82FFF0F4224F056;
		let x40:i64 = 0x754D2E7F8996A371;
		let x41:i64 = 0x62E27DF70849141D;
		let x50:i64 = 0x948F2476F7957627;
		let x51:i64 = 0x6C29804757B6D587;
		let x60:i64 = 0x6C0D8EAC2D275E5C;
		let x61:i64 = 0x0F7A0557C6508451;
		let x70:i64 = 0xEA12247067D3E47B;
		let x71:i64 = 0x69D71CD313ABE389;

		let b0:i64;
		let b1:i64;
		let b2:i64;
		let b3:i64;
		let b4:i64;
		let b5:i64;
		let b6:i64;
		let b7:i64;

		let cc0:i64;
		let cc1:i64;
		let tt0:i64;
		let tt1:i64;

		i = 0;
		do {

			b0 = load<i64>( i, TEXT_POS +  0 );
			b1 = load<i64>( i, TEXT_POS +  8 );
			b2 = load<i64>( i, TEXT_POS + 16 );
			b3 = load<i64>( i, TEXT_POS + 24 );
			b4 = load<i64>( i, TEXT_POS + 32 );
			b5 = load<i64>( i, TEXT_POS + 40 );
			b6 = load<i64>( i, TEXT_POS + 48 );
			b7 = load<i64>( i, TEXT_POS + 56 );

			// xor the 512-bit message with the fist half of the 1024-bit hash state
			x00 ^= b0;
			x01 ^= b1;
			x10 ^= b2;
			x11 ^= b3;
			x20 ^= b4;
			x21 ^= b5;
			x30 ^= b6;
			x31 ^= b7;

			// the bijective function E8
			j = 0;
			do {

				// round 7*roundnumber+k: Sbox, MDS and Swapping layers
				k = 0;
				do {

					t = ( k + j ) << 5;
					cc0 = load<i64>( t, JH_E8 +  0 );
					cc1 = load<i64>( t, JH_E8 + 16 );
					x60 = ~x60;
					x70 = ~x70;
					x00 ^= ~x40 & cc0;
					x10 ^= ~x50 & cc1;
					tt0 = cc0 ^ ( x00 & x20 );
					tt1 = cc1 ^ ( x10 & x30 );
					x00 ^= x40 & x60;
					x10 ^= x50 & x70;
					x60 ^= ~x20 & x40;
					x70 ^= ~x30 & x50;
					x20 ^= x00 & x40;
					x30 ^= x10 & x50;
					x40 ^= x00 & ~x60;
					x50 ^= x10 & ~x70;
					x00 ^= x20 | x60;
					x10 ^= x30 | x70;
					x60 ^= x20 & x40;
					x70 ^= x30 & x50;
					x20 ^= tt0 & x00;
					x30 ^= tt1 & x10;
					x40 ^= tt0;
					x50 ^= tt1;
					cc0 = load<i64>( t, JH_E8 +  8 );
					cc1 = load<i64>( t, JH_E8 + 24 );
					x61 = ~x61;
					x71 = ~x71;
					x01 ^= ~x41 & cc0;
					x11 ^= ~x51 & cc1;
					tt0 = cc0 ^ ( x01 & x21 );
					tt1 = cc1 ^ ( x11 & x31 );
					x01 ^= x41 & x61;
					x11 ^= x51 & x71;
					x61 ^= ~x21 & x41;
					x71 ^= ~x31 & x51;
					x21 ^= x01 & x41;
					x31 ^= x11 & x51;
					x41 ^= x01 & ~x61;
					x51 ^= x11 & ~x71;
					x01 ^= x21 | x61;
					x11 ^= x31 | x71;
					x61 ^= x21 & x41;
					x71 ^= x31 & x51;
					x21 ^= tt0 & x01;
					x31 ^= tt1 & x11;
					x41 ^= tt0;
					x51 ^= tt1;

					x10 ^= x20;
					x30 ^= x40;
					x50 ^= x00 ^ x60;
					x70 ^= x00;
					x00 ^= x30;
					x20 ^= x50;
					x40 ^= x10 ^ x70;
					x60 ^= x10;
					x11 ^= x21;
					x31 ^= x41;
					x51 ^= x01 ^ x61;
					x71 ^= x01;
					x01 ^= x31;
					x21 ^= x51;
					x41 ^= x11 ^ x71;
					x61 ^= x11;

					t = k << 4;
					s0 = load<i64>( t, JH_SWAP + 0 );
					s1 = load<i64>( t, JH_SWAP + 8 );
					t = 1 << k;
					x10 = ( ( x10 & s0 ) << t ) | ( ( x10 & s1 ) >>> t );
					x30 = ( ( x30 & s0 ) << t ) | ( ( x30 & s1 ) >>> t );
					x50 = ( ( x50 & s0 ) << t ) | ( ( x50 & s1 ) >>> t );
					x70 = ( ( x70 & s0 ) << t ) | ( ( x70 & s1 ) >>> t );
					x11 = ( ( x11 & s0 ) << t ) | ( ( x11 & s1 ) >>> t );
					x31 = ( ( x31 & s0 ) << t ) | ( ( x31 & s1 ) >>> t );
					x51 = ( ( x51 & s0 ) << t ) | ( ( x51 & s1 ) >>> t );
					x71 = ( ( x71 & s0 ) << t ) | ( ( x71 & s1 ) >>> t );

				} while ( ++k < 7 );

				// round 7*roundnumber+6: swapping layer
				tt0 = x10; x10 = x11; x11 = tt0;
				tt0 = x30; x30 = x31; x31 = tt0;
				tt0 = x50; x50 = x51; x51 = tt0;
				tt0 = x70; x70 = x71; x71 = tt0;

			} while ( ( j += 7 ) < 42 );

			// xor the 512-bit message with the second half of the 1024-bit hash state
			x40 ^= b0;
			x41 ^= b1;
			x50 ^= b2;
			x51 ^= b3;
			x60 ^= b4;
			x61 ^= b5;
			x70 ^= b6;
			x71 ^= b7;

		} while ( ( i += 64 ) < 320 );

		store<i64>( DATA +  0, x60 );
		store<i64>( DATA +  8, x61 );
		store<i64>( DATA + 16, x70 );
		store<i64>( DATA + 24, x71 );

	}

	// ========
	// SKEIN
	// --------
	else if ( k == 3 ) {

		// padding

		store<i64>( TEXT_KEC +   0, 0x0000000000000000 );
		store<i64>( TEXT_KEC +   8, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  16, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  24, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  32, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  40, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  48, 0x0000000000000000 );

		store<i64>( TEXT_KEC +  56, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  64, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  72, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  80, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  88, 0x0000000000000000 );
		store<i64>( TEXT_KEC +  96, 0x0000000000000000 );
		store<i64>( TEXT_KEC + 104, 0x0000000000000000 );
		store<i64>( TEXT_KEC + 112, 0x0000000000000000 );

		// compress

		let t0:u64;
		let t1:u64;

		let kt0:u64 = 0;
		let kt1:u64 = ( 1 << 62 ) | ( 48 << 56 );
		let kt2:u64;

		let x0:u64 = 0xCCD044A12FDB3E13;
		let x1:u64 = 0xE83590301A79A9EB;
		let x2:u64 = 0x55AEA0614F816E6F;
		let x3:u64 = 0x2A2767A4AE9B94DB;
		let x4:u64 = 0xEC06025E74DD7683;
		let x5:u64 = 0xE7A436CDC4746251;
		let x6:u64 = 0xC36FBAF9393AD185;
		let x7:u64 = 0x3EEDBA1833EDFC13;

		let kx0:u64;
		let kx1:u64;
		let kx2:u64;
		let kx3:u64;
		let kx4:u64;
		let kx5:u64;
		let kx6:u64;
		let kx7:u64;
		let kx8:u64;

		let w0:u64;
		let w1:u64;
		let w2:u64;
		let w3:u64;
		let w4:u64;
		let w5:u64;
		let w6:u64;
		let w7:u64;

		i = 0;
		do {

			if ( kt0 < 192 ) {
				kt0 += 64;
			} else if ( kt0 < 200 ) {
				kt0 += 8;
				kt1 |= ( 1 << 63 );
			} else {
				kt0 = 8;
				kt1 = ( 1 << 62 ) | ( 63 << 56 ) | ( 1 << 63 );
			}

			kt2 = kt0 ^ kt1;

			kx0 = x0;
			kx1 = x1;
			kx2 = x2;
			kx3 = x3;
			kx4 = x4;
			kx5 = x5;
			kx6 = x6;
			kx7 = x7;
			kx8 = kx0 ^ kx1 ^ kx2 ^ kx3 ^ kx4 ^ kx5 ^ kx6 ^ kx7 ^ 0x1BD11BDAA9FC1A22;

			w0 = load<i64>( i, TEXT_POS +  0 );
			w1 = load<i64>( i, TEXT_POS +  8 );
			w2 = load<i64>( i, TEXT_POS + 16 );
			w3 = load<i64>( i, TEXT_POS + 24 );
			w4 = load<i64>( i, TEXT_POS + 32 );
			w5 = load<i64>( i, TEXT_POS + 40 );
			w6 = load<i64>( i, TEXT_POS + 48 );
			w7 = load<i64>( i, TEXT_POS + 56 );

			x0 += w0;
			x1 += w1;
			x2 += w2;
			x3 += w3;
			x4 += w4;
			x5 += w5 + kt0;
			x6 += w6 + kt1;
			x7 += w7;

			j = 1;
			do { // do rounds

				x0 += x1; x1 = ( ( x1 << 46 ) | ( x1 >>> 18 ) ) ^ x0;
				x2 += x3; x3 = ( ( x3 << 36 ) | ( x3 >>> 28 ) ) ^ x2;
				x4 += x5; x5 = ( ( x5 << 19 ) | ( x5 >>> 45 ) ) ^ x4;
				x6 += x7; x7 = ( ( x7 << 37 ) | ( x7 >>> 27 ) ) ^ x6;
				x2 += x1; x1 = ( ( x1 << 33 ) | ( x1 >>> 31 ) ) ^ x2;
				x4 += x7; x7 = ( ( x7 << 27 ) | ( x7 >>> 37 ) ) ^ x4;
				x6 += x5; x5 = ( ( x5 << 14 ) | ( x5 >>> 50 ) ) ^ x6;
				x0 += x3; x3 = ( ( x3 << 42 ) | ( x3 >>> 22 ) ) ^ x0;
				x4 += x1; x1 = ( ( x1 << 17 ) | ( x1 >>> 47 ) ) ^ x4;
				x6 += x3; x3 = ( ( x3 << 49 ) | ( x3 >>> 15 ) ) ^ x6;
				x0 += x5; x5 = ( ( x5 << 36 ) | ( x5 >>> 28 ) ) ^ x0;
				x2 += x7; x7 = ( ( x7 << 39 ) | ( x7 >>> 25 ) ) ^ x2;
				x6 += x1; x1 = ( ( x1 << 44 ) | ( x1 >>> 20 ) ) ^ x6;
				x0 += x7; x7 = ( ( x7 <<  9 ) | ( x7 >>> 55 ) ) ^ x0;
				x2 += x5; x5 = ( ( x5 << 54 ) | ( x5 >>> 10 ) ) ^ x2;
				x4 += x3; x3 = ( ( x3 << 56 ) | ( x3 >>>  8 ) ) ^ x4;

				x0 += kx1;
				x1 += kx2;
				x2 += kx3;
				x3 += kx4;
				x4 += kx5;
				x5 += kx6 + kt1;
				x6 += kx7 + kt2;
				x7 += kx8 + j;

				x0 += x1; x1 = ( ( x1 << 39 ) | ( x1 >>> 25 ) ) ^ x0;
				x2 += x3; x3 = ( ( x3 << 30 ) | ( x3 >>> 34 ) ) ^ x2;
				x4 += x5; x5 = ( ( x5 << 34 ) | ( x5 >>> 30 ) ) ^ x4;
				x6 += x7; x7 = ( ( x7 << 24 ) | ( x7 >>> 40 ) ) ^ x6;
				x2 += x1; x1 = ( ( x1 << 13 ) | ( x1 >>> 51 ) ) ^ x2;
				x4 += x7; x7 = ( ( x7 << 50 ) | ( x7 >>> 14 ) ) ^ x4;
				x6 += x5; x5 = ( ( x5 << 10 ) | ( x5 >>> 54 ) ) ^ x6;
				x0 += x3; x3 = ( ( x3 << 17 ) | ( x3 >>> 47 ) ) ^ x0;
				x4 += x1; x1 = ( ( x1 << 25 ) | ( x1 >>> 39 ) ) ^ x4;
				x6 += x3; x3 = ( ( x3 << 29 ) | ( x3 >>> 35 ) ) ^ x6;
				x0 += x5; x5 = ( ( x5 << 39 ) | ( x5 >>> 25 ) ) ^ x0;
				x2 += x7; x7 = ( ( x7 << 43 ) | ( x7 >>> 21 ) ) ^ x2;
				x6 += x1; x1 = ( ( x1 <<  8 ) | ( x1 >>> 56 ) ) ^ x6;
				x0 += x7; x7 = ( ( x7 << 35 ) | ( x7 >>> 29 ) ) ^ x0;
				x2 += x5; x5 = ( ( x5 << 56 ) | ( x5 >>>  8 ) ) ^ x2;
				x4 += x3; x3 = ( ( x3 << 22 ) | ( x3 >>> 42 ) ) ^ x4;

				x0 += kx2;
				x1 += kx3;
				x2 += kx4;
				x3 += kx5;
				x4 += kx6;
				x5 += kx7 + kt2;
				x6 += kx8 + kt0;
				x7 += kx0 + j + 1;

				t0 = kt0;
				kt0 = kt2;
				kt2 = kt1;
				kt1 = t0;

				t0 = kx0;
				t1 = kx1;
				kx0 = kx2;
				kx1 = kx3;
				kx2 = kx4;
				kx3 = kx5;
				kx4 = kx6;
				kx5 = kx7;
				kx6 = kx8;
				kx7 = t0;
				kx8 = t1;

			} while ( ( j += 2 ) < 18 );

			x0 ^= w0;
			x1 ^= w1;
			x2 ^= w2;
			x3 ^= w3;
			x4 ^= w4;
			x5 ^= w5;
			x6 ^= w6;
			x7 ^= w7;

			kt1 &= ~( 1 << 62 );

		} while ( ( i += 64 ) < 320 );

		store<u64>( DATA +  0, x0 );
		store<u64>( DATA +  8, x1 );
		store<u64>( DATA + 16, x2 );
		store<u64>( DATA + 24, x3 );

	}

}
