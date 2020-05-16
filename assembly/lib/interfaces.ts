/*
export interface input {
  id:i32,
  inputvalue:f32,
  inputNormalize:bool,
  out:f32,
  weights:weight[],
}

export interface layer {
  layerid:i32,
  p:perc[],
  ishidden:bool,
}


export interface perc {
  id:i32;
  inrow:i32;
  inputPool:Float32Array;
  actFunc:i8;
  paraX:f32;
  paraY:f32;
  inputNormalize:bool;
  out:f32;
  weights:weight[];
}
*/
export class weight {
  private _torow:i32;

  constructor() {
    this._torow = 0;
  }

  get torow():i32 {
    if(isDefined(this._torow) && this._torow > 0){
      return this._torow;
    }
    return 0;
  }

  set torow(row:i32) {
    this._torow  = row;
  }

  private _toid:i32;



  private _weight:f32;


}

