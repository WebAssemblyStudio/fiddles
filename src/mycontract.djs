@contract class SimpleStore {
  @view @state value: number = 0
  @transaction setValue(value: number) {
    this.value.value(value)
  }
}
