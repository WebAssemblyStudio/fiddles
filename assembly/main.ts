class Container {
  public another: Another|null = null;
}

class Another {
  public prop: i32 = 0;
}

export function doStuff( container: Container ): void {
  if ( container.another !== null && container.another.prop > 1 ) {
    container.another.prop = 2;
  }
}