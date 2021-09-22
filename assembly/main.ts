function freeFunction<T>(value: T): T {                                                                   
  return value;                                                                                           
}
                                                                                                          
// function freeFunctionI64(value: i64): i64 {                                                            
//   return freeFunction(value);                                                                                        
// }                                                                                                      
                                                                                                        
function bad<T>(value: T, func: (value: T) => T): T {                                                     
  return func(value);                                                                                     
}                                                                                                         
                                                                                                          
export function test(): i64 {                                                                             
  return bad<i64>(123, freeFunction);                                                                     
  // return bad<i64>(123, freeFunctionI64);                                                               
}