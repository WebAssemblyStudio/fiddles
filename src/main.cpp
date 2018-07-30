#include <cstdlib>

#define WASM_EXPORT __attribute__((visibility("default")))

struct RenderInfoItem {
  double opacity, lng, lat;
  unsigned int tint;
  bool showParticle;
} __attribute__((packed));

struct Point {
  double lat, lng, time, offset;
} __attribute__((packed));

struct TrackPoint {
  double lat, lng, elevation;
} __attribute__((packed));

struct Track {
  unsigned int count;
  TrackPoint* data;
} __attribute__((packed));

struct PointArrayChunk {
  const static unsigned int capacity = 1024;
  unsigned int count = 0;
  Point* data;
  PointArrayChunk() {
    data = (Point*)malloc(sizeof(Point) * capacity);
  }
  ~PointArrayChunk() {
    free(data);
  }
} __attribute__((packed));

struct PointArray {
  unsigned int count = 0;
  unsigned int capacity = 0;
  PointArrayChunk* data;
  PointArray(unsigned int initial) {
    data = (PointArrayChunk*)malloc(sizeof(PointArrayChunk) * capacity);
    capacity = initial;
  }
  void push(Point p) {
    if (count + 1 >= capacity) {
      capacity += PointArrayChunk::capacity;
      data[capacity / PointArrayChunk::capacity] = PointArrayChunk();
      // ensure capacity
    }
    count++;
    data[count / PointArrayChunk::capacity].data[count % PointArrayChunk::capacity] = p;
  }
} __attribute__((packed));

struct RenderInfoBuffer {
  unsigned int count;
  RenderInfoItem* data;
  
  RenderInfoBuffer(unsigned int _count) {
    data = (RenderInfoItem*)malloc(sizeof(RenderInfoItem) * _count);
    count = _count;
  }
  ~RenderInfoBuffer() {
    free(data);
  }
} __attribute__((packed));

WASM_EXPORT
Point* createPoint (double lat, double lng, double time, double offset) {
  Point* record = (Point*)malloc(sizeof(Point));
  record->lat = lat;
  record->lng = lng;
  record->time = time;
  record->offset = offset;
  return record;
}

WASM_EXPORT
void deleteRecord (Point* record) {
  free(record);
}

WASM_EXPORT
int main(void) {

}