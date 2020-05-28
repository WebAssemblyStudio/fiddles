#define WASM_EXPORT __attribute__((visibility("default")))

const int something_you_want[] = {105114, 111258, 99994, 106138, 126618, 75418, 97946, 122522, 99994, 113306, 119450, 97946, 119450, 114330, 97946, 106138, 114330, 97946, 101018, 99994, 102042, 110234, 97946, 119450, 114330, 97946, 87706, 69274, 67226, 85658, 128666};

WASM_EXPORT
int validate_flag(int *arr, int len) {
  if (len != 31) return 0;
  int flag = 1;
  for(int i = 0; i < 31; i++) {
    if(arr[i] * 1024 + 666 != something_you_want[i]) {
      flag = 0;
      break;
    }
  }
  return flag;
}