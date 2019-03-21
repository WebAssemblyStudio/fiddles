declare function init(): void;

init();

export function random(min: i32, max: i32): number {
  return Math.floor(Math.random()*(max-min+1)+min);
}