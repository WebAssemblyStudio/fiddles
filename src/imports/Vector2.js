var Vector2 = function(x,y)
{
  var pointer = Vector2.Vector2_new(x,y);
  this.x = () => {
    return Vector2.Vector2_get_x(pointer)
  }
  this.y = () => {
    return Vector2.Vector2_get_y(pointer);
  }
  this.destroy = () => {
    Vector2.Vector2_delete(pointer);
  }
}
Vector2.InicializeMethods = (exports) => {
  Vector2.Vector2_new = exports.Vector2_new;
  Vector2.Vector2_get_x = exports.Vector2_get_x;
  Vector2.Vector2_get_y = exports.Vector2_get_y;
  Vector2.Vector2_delete = exports.Vector2_delete;
}
module.exports = Vector2