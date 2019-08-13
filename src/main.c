char *get_state(char *key);
char *invoke(int argc, char *argv[]) {
  char *key = argv[0];
  return get_state(key);
}