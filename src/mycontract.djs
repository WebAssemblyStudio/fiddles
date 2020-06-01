@contract class MyContract {
  @state value = 0

@view getValue(){
  return this.value
}
@transaction setValue(value){
  this.value = value
}
}