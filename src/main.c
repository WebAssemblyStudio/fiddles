#include <string.h>
#include <stdlib.h>

const int None = 0;
const int File = 1;
const int HeaderVersion1 = 2;
const int Scale = 3;
const int ViewPort = 4;
const int DBase = 5;
const int Layer = 6;
const int Limit = 7;
const int LineType = 8;
const int LineTypeCache = 9;
const int Attach = 10;
const int Fonts = 11;
const int Shapes = 12;
const int Blocks = 13;
const int Bitmap = 14;
const int BlockStart = 15;
const int BlockEnd = 16;
const int Float = 17;
const int Integer = 18;
const int Long = 19;
const int String = 20;
const int Object = 21;
const int ObjectWdb = 22;
const int ObjectStart = 23;
const int RefBitmap1 = 24;
const int Version = 25;
const int RefBitmap2 = 26;
const int Limit32 = 27;
const int UserDef = 28;
const int Limit33 = 29;
const int ComplexPolyStart = 30;
const int ComplexPolyEnd = 31;
const int CipperValue = 32;
const int Patch6 = 33;
const int Bitmap6 = 34;
const int Limit34 = 35;
const int Layer8 = 36;

typedef struct FileItem{
  int Tag;
  int Size;
} FileItem;

typedef struct Coordinate{
  double X;
  double Y;
} Coordinate;

typedef struct Envelope{
  Coordinate Min;
  Coordinate Max;
} Envelope;

typedef struct FileHeader {
   int TotalSize;
   int HeaderEntry;
   int LayerEntry;
   int LineTypeEntry;
   int CLineTypeEntry;
   int AttachEntry;
   int FontEntry;
   int ShapeEntry;
   int BitmapEntry;
   int BlockEntry;
   int ObjectEntry;
   Envelope Bounds;
   int NumShapes;
} FileHeader;

int * Buffer;
char * Json;
int Position;

FileItem Current;
FileHeader Header;

int readNext();
void readHeader();

int readByte();
int readShort();
int readInt();
double readDouble();
Coordinate readCoordinate();
Envelope readEnvelope();
int escape();

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT int main() {
  return 0;
}

WASM_EXPORT int load(int * buffer)
{
  FileItem item;
  Position = 0;
  Buffer = buffer;

  if(readNext() > 0){
    if(Current.Tag == 1) readHeader();
  }

  Json = "Çç-Ğğ-İı-Öö-Şş-Üü";
  return escape();
}

int readNext(){
  Current.Tag = readByte();
  Current.Size = readInt();
  return Current.Tag;
}

void readHeader(){
  Header.TotalSize = readInt();
  Header.HeaderEntry = readInt();
  Header.LayerEntry = readInt();
  Header.LineTypeEntry = readInt();
  Header.CLineTypeEntry = readInt();
  Header.AttachEntry = readInt();
  Header.FontEntry = readInt();
  Header.ShapeEntry = readInt();
  Header.BitmapEntry = readInt();
  Header.BlockEntry = readInt();
  Header.ObjectEntry = readInt();
  Header.Bounds = readEnvelope();
  Header.NumShapes = readInt();
}

inline int readByte()
{
  return Buffer[Position++];
}

int readShort()
{
  int r = (Buffer[Position + 1] << 8) | Buffer[Position];
  Position += 2;
  return r;
}

int readInt()
{
  int n0 = readShort();
  int n1 = readShort();
  return (n1 << 16) | n0;
}

double readDouble()
{
  int n0 = readInt();
  unsigned long long n1 = readInt();
  return (n1 << 32) | n0;
}

Coordinate readCoordinate(){
  Coordinate c;
  c.Y = readDouble();
  c.X = readDouble();
  return c;
}

Envelope readEnvelope(){
  Envelope e;
  e.Min = readCoordinate();
  e.Max = readCoordinate();
  return e;
}

int escape(){
  int n = 0;
  int len = strlen(Json);
  
  for(int i = 0; i < len - 1; i++){
    int c = Json[i];

    if(c < 0){
      int d = Json[++i];

      if( c == -61 && d == -121 ) c = 199;
      else if( c == -61 && d == -89 ) c = 231;
      else if( c == -60 && d == -98 ) c = 286;
      else if( c == -60 && d == -97 ) c = 287;
      else if( c == -60 && d == -80 ) c = 304;
      else if( c == -60 && d == -79 ) c = 305;
      else if( c == -61 && d == -106 ) c = 214;
      else if( c == -61 && d == -74 ) c = 246;
      else if( c == -59 && d == -59 ) c = 350;
      else if( c == -59 && d == -97 ) c = 351;
      else if( c == -61 && d == -100 ) c = 220;
      else if( c == -61 && d == -68 ) c = 252;

      c = 220;
    }

    Buffer[n++] = c;
  }

  return n;
}