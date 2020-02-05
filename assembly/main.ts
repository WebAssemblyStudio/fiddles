
export class Vector2D {
  constructor(
    public x: f32,
    public y: f32,
  ) {}

  magnitude_Mathf_sqrt(): f32 {
    return Mathf.sqrt(this.x * this.x + this.y * this.y);
  }

  magnitude_f32_sqrt(): f32 {
    return f32.sqrt(this.x * this.x + this.y * this.y);
  }
}