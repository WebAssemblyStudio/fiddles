@contract class LovelockUsers {
  @view @state list = {}

  @view isAuthorized(who: address): boolean {
    return !!list[who]
  }

  @transaction adUser(who: address) {
    this.list[who] = true
  }
}