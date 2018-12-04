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

  @inline @operator("+")
  protected __add(vec: vec_c): vec_c {
    return vec_c.create(
      this.x + vec.x,
      this.y + vec.y,
    );
  }

  @inline @operator("+=")
  protected __add_mut(vec: vec_c): vec_c {
    this.x += vec.x;
    this.y += vec.y;
    return this;
  }

  @inline @operator("*")
  protected __mul(vec: vec_c): vec_c {
    return vec_c.create(
      this.x * vec.x,
      this.y * vec.y,
    );
  }

  @inline @operator("*=")
  protected __mul_mut(vec: vec_c): vec_c {
    this.x *= vec.x;
    this.y *= vec.y;
    return this;
  }

  @inline @operator("<=")
  protected __set(vec: vec_c): vec_c {
    this.x = vec.x;
    this.y = vec.y;
    return this;
  }

  @inline @operator("*")
  protected __mul_mat_c(mat: mat_c): vec_c {
    return vec_c.create(
      mat.a * this.x + mat.c * this.y + mat.e,
      mat.b * this.x + mat.d * this.y + mat.f,
    );
  }

  @inline @operator("*=")
  protected __mul_mat_c_mut(mat: mat_c): vec_c {
    this.x += mat.a * this.x + mat.c * this.y;
    this.y += mat.b * this.x + mat.d * this.y;
    return this;
  }
}