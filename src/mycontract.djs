const { expect } = require(';');

@contract class GLC20 {
  @state _balances = {};
  @state _allowances = {};

  @view @state totalSupply : number = 1000000000000000000;
  @view @state name : string = 'Grill Curry';
  @view @state symboll : string = 'GRC';
  @view @state decimal : number = 18;
  @view @state owner = 'tglc1tk5tsfhhrjvv37l9575qa6cjpae4urzc6jzlgk';

  @transaction INIT() {
    this._balances['tglc1tk5tsfhhrjvv37l9575qa6cjpae4urzc6jzlgk'] = this.totalSupply;
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
    this._approve(sender, msg.sender, currentAllowance - amount);
  }

  @transaction increaseAllowance(spender : string, addedValue : number) {
    let currentAllowance = this._allowances[msg.sender][spender];
    if (currentAllowance === undefined) currentAllowance = 0;
    _approve(msg.sender, spender, this._allowances[msg.sender][spender] + addedValue);
  }

  @transaction decreaseAllowance(spender : string, subtractedValue : number) {
    let currentAllowance = this._allowances[msg.sender][spender];
    if (currentAllowance === undefined) currentAllowance = 0;
    expect(currentAllowance >= subtractedValue);
    _approve(msg.sender, spender, currentAllowance - subtractedValue);
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