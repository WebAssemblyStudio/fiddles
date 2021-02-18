#define WASM_EXPORT __attribute__((visibility("default")))

// Declare Armory API used in this module
// github.com/armory3d/armory/blob/master/Sources/armory/trait/internal/wasm_api.h
void notify_on_update(void* f);
int get_object(const char* name);
void set_transform(int object, float x, float y, float z,
	float rx, float ry, float rz, float sx, float sy, float sz);

WASM_EXPORT
void update() {
	static float rot = 0.0f;
	rot += 0.01f;
	set_transform(get_object("Cube"), 0, 0, 0, 0, 0, rot, 1, 1, 1); // Set cube rotation
}

// Include main function, Armory calls it when trait is instantiated
WASM_EXPORT
int main() {
	notify_on_update(update); // Register callback
	return 0;
}