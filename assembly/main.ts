import { Product, ProductTestHelper } from './ep';

export function add(x: i32, y: i32): i32 {
  // This won't work since we don't export the Product class
  // const product = new Product(123, 'abc');

  // This will work since we export the Product type
  const product: Product = ProductTestHelper.buildProduct(123, 'abc');

  return 0;
}
