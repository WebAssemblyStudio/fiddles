let totalSize: u32;

let leaderPtsX: u32[];
let leaderPtsY: u32[];
let leaderPtsType: u32[];

const VP_COUNT: u32 = 20;

export function init(size: u32): void {
  totalSize = size;
  createVoronoiPoints();
}

export function populate(): void {
  for (let i: u32 = 0; i < totalSize; i++) {
    for (let j: u32 = 0; j < totalSize; j++) {
      store<u32>((i + j * totalSize) << 2, getClosestNeighbourType(i,j));
    }
  }
}

function createVoronoiPoints(): void {
  leaderPtsX = new Array<u32>();
  leaderPtsY = new Array<u32>();
  leaderPtsType = new Array<u32>();
  for (let i: u32 = 0; i < VP_COUNT; i++) {
    let x = <u32>(Math.random() * totalSize);
    let y = <u32>(Math.random() * totalSize);
    leaderPtsType.push(Math.random() > 0.5 ? 0xffffffff : 0xff00ff00);
    leaderPtsX.push(x);
    leaderPtsY.push(y);
  }
}

function getClosestNeighbourType(x: u32, y: u32): u32 {
  let minDistance = 5000;
  let minDistanceType = -1;
  for (let i = 0; i < <i32>VP_COUNT; i++) {
    let dist =
      Math.abs(x - unchecked(leaderPtsX[i])) +
      Math.abs(y - unchecked(leaderPtsY[i]));
    if (dist < minDistance) {
      minDistance = <u32>dist;
      minDistanceType = unchecked(leaderPtsType[i]);
    }
  }
  return <u32>minDistanceType;
}
