import { vec_c } from "./vec_c";

export class mat_c {
  public a: f64 = 0;
  public b: f64 = 0;
  public c: f64 = 0;
  public d: f64 = 0;
  public e: f64 = 0;
  public f: f64 = 0;

  @inline
  public static create(a: f64 = 1, b: f64 = 0, c: f64 = 0, d: f64 = 1, e: f64 = 0, f: f64 = 0): mat_c {
    var result = new mat_c();
    result.a = a;
    result.b = b;
    result.c = c;
    result.d = d;
    result.e = e;
    result.f = f;
    return result;
  }

  @inline
  public static create_from(mat: mat_c): mat_c {
    return mat_c.create(
      this.a,
      this.b,
      this.c,
      this.d,
      this.e,
      this.f,
    );
  }

  @inline
  public static identity(): mat_c {
    return mat_c.create();
  }

  @inline
  public scale_mut(x: f64, y: f64): mat_c {
    this.a *= x;
    this.b *= x;
    this.c *= y;
    this.d *= y;
    return this;
  }

  @inline
  public scale(x: f64, y: f64): mat_c {
    return mat_c.create(
      this.a * x,
      this.b * x,
      this.c * y,
      this.d * y,
      this.e,
      this.f,
    );
  }

  @inline
  public translate(x: f64, y: f64): mat_c {
    return mat_c.create(
      this.a,
      this.b,
      this.c,
      this.d,
      this.a * x + this.c * y + this.e,
      this.b * x + this.d * y + this.f,
    );
  }

  @inline
  public translate_mut(x: f64, y: f64): mat_c {
    this.e += this.a * x + this.c * y;
    this.f += this.b * x + this.d * y;
    return this;
  }

  @inline
  public rotate(angle: f64): mat_c {
    return mat_c
      .create_from(this)
      .rotate_mut(angle);
  }

  @inline
  public rotate_mut(angle: f64): mat_c {
    var cos: f64 = Math.cos(angle);
    var sin: f64 = Math.sin(angle);
    var a: f64 = this.a;
    var b: f64 = this.b;
    var c: f64 = this.c;
    var d: f64 = this.d;
    this.a = a * cos + c * sin;
    this.b = b * cos + d * sin;
    this.c = c * cos - a * sin;
    this.d = d * cos - b * sin;
  }

  @inline
  public transform(val: mat_c): mat_c {
    return mat_c.create(
      this.a * val.a + this.c * val.b,
      this.b * val.a + this.d * val.b,
      this.a * val.c + this.c * val.d,
      this.b * val.c + this.d * val.d,
      this.a * val.e + this.c * val.f + this.e,
      this.b * val.e + this.d * val.f + this.f,
    );
  }

  @inline
  public transform_mut(val: mat_c): mat_c {
    // props values
    var pa: f64 = val.a;
    var pb: f64 = val.b;
    var pc: f64 = val.c;
    var pd: f64 = val.d;
    var pe: f64 = val.e;
    var pf: f64 = val.f;

    // matrix values
    var ma: f64 = this.a;
    var mb: f64 = this.b;
    var mc: f64 = this.c;
    var md: f64 = this.d;
    var me: f64 = this.e;
    var mf: f64 = this.f;

    this.a = ma * pa + mc * pb;
    this.b = mb * pa + md * pb;
    this.c = ma * pc + mc * pd;
    this.d = mb * pc + md * pd;
    this.e = ma * pe + mc * pf + me;
    this.f = mb * pe + md * pf + mf;
  }

  @inline
  public inverse(): mat_c {
    var det: f64 = 1 / (this.a * this.d - this.c * this.b);
    return mat_c.create(
      this.d * det,
      -this.b * det,
      -this.c * det,
      this.a * det,
      (this.c * this.f - this.e * this.d) * det,
      (this.e * this.b - this.a * this.f) * det,
    );
  }

  @inline
  public inverse_mut(): mat_c {
    var a: f64 = this.a;
    var b: f64 = this.b;
    var c: f64 = this.c;
    var d: f64 = this.d;
    var e: f64 = this.e;
    var f: f64 = this.f;
    var det: f64 = 1 / (a * d - c * b);

    this.a = d * det;
    this.b = -b * det;
    this.c = -c * det;
    this.d = a * det;
    this.e = (c * f - e * d) * det;
    this.f = (e * b - a * f) * det;
    return this;
  }

  @inline
  public transform_point(val: vec_c): vec_c {
    return vec_c.create(
      this.a * val.x + this.c * val.y + this.e,
      this.b * val.x + this.d * val.y + this.f,
    );
  }

  @inline
  public transform_point_mut(val: vec_c): vec_c {
    var x: f64 = val.x;
    var y: f64 = val.y;
    val.x = this.a * x + this.c * y + this.e;
    val.y = this.b * x + this.d * y + this.f;
    return val;
  }

  @inline @operator("*")
  protected __transform(val: mat_c): mat_c {
    return this.transform(val);
  }

  protected constructor() {}
}