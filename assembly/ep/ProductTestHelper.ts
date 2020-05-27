import { Product } from './Product';

export class ProductTestHelper {
  static buildProduct(id: u64, name: string): Product {
    return new Product(id, name);
  }
}