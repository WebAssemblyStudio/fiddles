typedef struct Coordinate{
  double X;
  double Y;
} coordinate;

typedef struct Envelope{
  coordinate Min;
  coordinate Max;
} envelope;

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
   envelope Bounds;
   int NumShapes;
} fileHeader;

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 0;
}

WASM_EXPORT
char * test() {
  return "Türkçe Fıstıkçı Şahap";
}

WASM_EXPORT
int fileLoad(int * buffer, int size)
{
  header file
  //return value.load(buffer, size);
  return 0;
}

fileHeader readHeader(int * buffer){
  fileHeader header = new fileHeader();
  header.TotalSize = convertToInt(buffer, 0);
  header.HeaderEntry = convertToInt(buffer, 4);
  header.LayerEntry = convertToInt(buffer, 8);
  header.LineTypeEntry = convertToInt(buffer, 8);
  header.CLineTypeEntry = convertToInt(buffer, 8);
  header.AttachEntry = convertToInt(buffer, 8);
  header.FontEntry = convertToInt(buffer, 8);
}

int convertToInt(int * buffer, int start)
{
  return (bytes[start + 3] << 24) | (bytes[start + 2] << 16) | (bytes[start + 1] << 8) | bytes[start];
}