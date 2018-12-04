import { mat_c } from "./mat_c";

export class vec_c {
  public x: f64 = 0;
  public y: f64 = 0;

  @inline
  public static create(x: f64 = 0, y: f64 = 0): vec_c {
    var result = new vec_c();
    result.x = x;
    result.y = y;
    return result;
  }

  @inline
  public transform(val: mat_c): vec_c {
    return val.transform(this);
  }

  @inline
  public transform_mut(val: mat_c): vec_c {
    return val.transform_mut(this);
  }

  @inline @operator("+")
  protected __add(vec: vec_c): vec_c {
    return vec_c.create(
      this.x + vec.x,
      this.y + vec.y,
    );
  }

  @inline @operator("*")
  protected __mul(vec: vec_c): vec_c {
    return vec_c.create(
      this.x * vec.x,
      this.y * vec.y,
    );
  }

  @inline @operator("<<")
  protected __set(vec: vec_c): vec_c {
    this.x = vec.x;
    this.y = vec.y;
    return this;
  }

  @inline @operator(">>")
  protected __set_right(vec: vec_c): vec_c {
    vec.x = this.x;
    vec.y = this.y;
    return this;
  }
}