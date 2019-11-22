@contract class LovelockUsers {
  @view @state list = {}

  @view isAuthorized(who: string): boolean {
    return !!list[who]
  }

  @transaction adUser(who: string) {
    this.list[who] = true
  }
}