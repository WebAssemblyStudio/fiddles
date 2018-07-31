#define WASM_EXPORT __attribute__((visibility("default")))
using uint32_t = unsigned int;

extern "C" void* malloc(unsigned long);
extern "C" void free(void*);

void* realloc(void* ptr, unsigned long old_size, unsigned long new_size) {
  void* new_ptr = malloc(new_size);
  for (unsigned int i = 0; i < old_size; i++) {
    ((char*)new_ptr)[i] = ((char*)ptr)[i];
  }
  free(ptr);
  return new_ptr;
};

template<class T>
class vector {
public:
  uint32_t count = 0;
  uint32_t capacity = 0;
  T* data = 0;

  void ensure_capacity(uint32_t new_capacity) {
    data = (T*)realloc(data, sizeof(T) * capacity, sizeof(T) * new_capacity);
    capacity = new_capacity;
  }

  void push_back(T& item) {
    count++;
    if (count > capacity) {
      ensure_capacity(1.3 * capacity);
    }
    data[count - 1] = item;
  }

  void push_back(T item) {
    count++;
    if (count > capacity) {
      ensure_capacity(1.3 * capacity);
    }
    data[count - 1] = item;
  }

  T& back() {
    return data[count - 1];
  }

  T& operator[] (uint32_t i) {
    return data[i];
  }
};

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
};

struct PointArrayChunk {
  const static unsigned int capacity = 1024;
  unsigned int count = 0;
  Point* data = 0;

  PointArrayChunk() {
    data = (Point*)malloc(sizeof(Point) * capacity);
  }

  ~PointArrayChunk() {
    free(data);
  }

  void push_back(Point& p) {
    count++;
    data[count] = p;
  }
};

struct PointArray {
  vector<PointArrayChunk> data;

  PointArray() {
    data.push_back(PointArrayChunk());
  }

  void push_back(Point& p) {
    if (data.back().count + 1 >= PointArrayChunk::capacity) {
      data.push_back(PointArrayChunk());
    }
    data.back().push_back(p);
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
  PointArray pa;
  for (uint32_t i = 0; i < 2048; i++) {
    Point p = { 12, 12, static_cast<double>(i * 1000), -1 };
    pa.push_back(p);
  }
  return pa.data[1].data[2].lat;
}
