let leaderPtsX: u32[];
let leaderPtsY: u32[];
let leaderPtsType: u32[];

const totalSize = 512;
const VP_COUNT = totalSize * totalSize;

export function createPoints(): void {
  leaderPtsX = new Array<u32>();
  leaderPtsY = new Array<u32>();
  leaderPtsType = new Array<u32>();
  for (let i = 0; i < VP_COUNT; i++) {
    let x = <u32>(Math.random() * totalSize);
    let y = <u32>(Math.random() * totalSize);
    leaderPtsType.push(Math.random() > 0.5 ? 0xffffffff : 0xff00ff00);
    leaderPtsX.push(x);
    leaderPtsY.push(y);
  }
}

export function getClosestNeighbourType(x: u32, y: u32): u32 {
  let minDistance = u32.MAX_VALUE;
  let minDistanceType = -1;
  for (let i = 0; i < VP_COUNT; i++) {
    let dist =
      abs(x - unchecked(leaderPtsX[i])) +
      abs(y - unchecked(leaderPtsY[i]));
    if (dist < minDistance) {
      minDistance = dist;
      minDistanceType = unchecked(leaderPtsType[i]);
    }
  }
  return <u32>minDistanceType;
}

