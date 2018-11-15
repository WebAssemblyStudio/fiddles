
declare function getId():string

export class Bid{
  constructor(public bidder: string, public bid: u64){}
}

export class Auction {
  bids: Bid[];
  constructor (public ID: string){}

  public placeBid(bidder: string, bid: u64): void{
    this.bids.push(new Bid(bidder, bid));
  }

}

export function A(ID: string): Auction{
  return new Auction(ID);
}