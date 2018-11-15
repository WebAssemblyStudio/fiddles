declare function sayHello(): void;



sayHello();

declare function getId():string

export class Bid{
  constructor(public bidder: string, public bid: u64){}
}

export class Auction {
  bids: Bid[];
  constructor (public ID: string){}

  public placeBid(b: Bid){

  }

}