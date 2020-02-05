
export class Vector2D {
  constructor(
    public x: f32,
    public y: f32,
  ) {}

  magnitude(): f32 {
    return Mathf.sqrt(this.x * this.x + this.y * this.y);
  }
}