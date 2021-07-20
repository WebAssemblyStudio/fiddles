#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

WASM_EXPORT
int create_file() {
  const char* file_name = "hello.txt";
	FILE *fp = NULL;

	fp = fopen(file_name, "wb");
	if (fp == NULL) {
		return -1;
	}
	fwrite("Hello", 5, 1, fp);
	fclose(fp);
	return 0;
}

// void show_file() {
// 	DIR *dir = NULL;
// 	struct dirent *ptr = NULL;
// 	struct stat st;
// 	int cnt = 0;

// 	if ((dir = opendir(".")) == NULL) {
// 		printf("open dir failed.\n");
// 		return;
// 	}
// 	while ((ptr = readdir(dir)) != NULL) {
// 		if (!(ptr->d_type & DT_REG)) {
// 			continue;
// 		}
// 		stat(ptr->d_name, &st);
// 		printf("%s, %lld bytes, use: get_file(\"%s\");\n", ptr->d_name, st.st_size, ptr->d_name);
// 		cnt++;
// 	}
// 	closedir(dir);
// 	printf("found %d files.\n", cnt);
// 	return;
// }

// int rm_file(const char *path) {
// 	return remove(path);
// }

// int mv_file(const char *oldpath, const char *newpath) {
// 	return rename(oldpath, newpath);
// }

WASM_EXPORT
int get_file() {
  const char *path;
  unsigned char **data;
  unsigned int *size;
	FILE *fp = NULL;

	fp = fopen(path, "rb");
	if (fp == NULL) {
		return -1;
	}
	fseek(fp, 0, SEEK_END);
	*size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	*data = (unsigned char *)malloc(*size);
	if (*data != NULL) {
    fread(*data, *size, 1, fp);
    fwrite(*data, *size, 1, stdout);
	}
	fclose(fp);
	return 0;
}

WASM_EXPORT
int main() {
  return 42;
}
