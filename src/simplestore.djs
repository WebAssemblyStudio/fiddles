const { expect } = require(';');

@contract class GLC20 {
  @state _balances = {};
  @state _allowances = {};

  @view @state _totalSupply : number = 1000000000000000000;
  @view @state _name : string = "Glitch";
  @view @state _symbol : string = "GLC";
  @view @state _decimal : number = 18;

  @transaction INIT() {
    this._balances[this.deployedBy] = this._totalSupply;
  }

  @view owner() : string {
    return (this.deployedBy);
  }

  @view balancesOf(user : string) : number {
    let money = this._balances[user];
    if (money === undefined) money = 0;
    return money;
  }

  @transaction transfer(recipient : string, amount : number) {
    this._transfer(msg.sender, recipient, amount);
  }

  @view allowance(owner : string, spender : string) {
    let a = this._allowances[owner][spender];
    if (a === undefined) {
      a = 0;
    }
    return a;
  }

  @transaction approve(spender : string, amount : number) {
    this._approve(msg.sender, spender, amount);
  }

  @transaction transferFrom(sender : string, recipient : string, amount : number) {
    this._transfer(sender, recipient, amount);

    let currentAllowance = this._allowances[sender][recipient];
    if (currentAllowance === undefined) {
      currentAllowance = 0;
    }
    expect(currentAllowance >= amount);
    this._approve(sender, recipient, currentAllowance - amount);
  }

  @transaction increaseAllowance(spender : string, addedValue : number) {
    let currentAllowance = this._allowances[msg.sender][spender]
    if (currentAllowance === undefined) {
      currentAllowance = 0
    }
    _approve(msg.sender, spender, currentAllowance + addedValue);
  }

  @transaction decreaseAllowance(spender : string, subtractedValue : number) {
    let currentAllowance = this._allowances[msg.sender][spender];
    if (currentAllowance === undefined) {
      currentAllowance = 0
    }
    expect(currentAllowance >= subtractedValue);
    _approve(_msgSender(), spender, currentAllowance - subtractedValue);
  }

  @transaction _transfer(sender : string, recipient : string, amount : number) {
    let senderBalance = this._balances[sender];
    if (senderBalance === undefined) senderBalance = 0;
    expect(senderBalance >= amount);
    this._balances[sender] = senderBalance - amount;

    if (this._balances[recipient] === undefined) {
      this._balances[recipient] = 0;
    }

    this._balances[recipient] += amount;
  }

  @transaction _approve(owner : string, spender : string, amount : number) {
    this._allowances[owner][spender] = amount;
  }

}