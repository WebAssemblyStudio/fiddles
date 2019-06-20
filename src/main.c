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
int fileLoad(int *buffer, int size)
{
  return read_Header(buffer).BitmapEntry;
}

static fileHeader read_Header(int *buffer){
  int n = 0;
  fileHeader header;
  header.TotalSize = convertToInt(buffer, n+=4);
  header.HeaderEntry = convertToInt(buffer, n+=4);
  header.LayerEntry = convertToInt(buffer, n+=4);
  header.LineTypeEntry = convertToInt(buffer, n+=4);
  header.CLineTypeEntry = convertToInt(buffer, n+=4);
  header.AttachEntry = convertToInt(buffer, n+=4);
  header.FontEntry = convertToInt(buffer, n+=4);
  header.ShapeEntry = convertToInt(buffer, n+=4);
  header.BitmapEntry = convertToInt(buffer, n+=4);
  header.BlockEntry = convertToInt(buffer, n+=4);
  header.ObjectEntry = convertToInt(buffer, n+=4);
  return header;
}

static int convertToInt(int *buffer, int start)
{
  return (buffer[start + 3] << 24) | (buffer[start + 2] << 16) | (buffer[start + 1] << 8) | buffer[start];
}