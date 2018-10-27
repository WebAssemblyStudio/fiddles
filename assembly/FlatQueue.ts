
export class FlatQueue {
  ids: f64[];
  values: f64[];
  length: i32;

  constructor() {
      this.ids = [];
      this.values = [];
      this.length = 0;
  }

  clear(): void {
      this.length = this.ids.length = this.values.length = 0;
  }

  push(id: f64, value: f64): void {
      this.ids.push(id);
      this.values.push(value);

      let pos = this.length++;
      while (pos > 0) {
          let parent = (pos - 1) >> 1;
          let parentValue = this.values[parent];
          if (value >= parentValue) break;
          this.ids[pos] = this.ids[parent];
          this.values[pos] = parentValue;
          pos = parent;
      }

      this.ids[pos] = id;
      this.values[pos] = value;
  }

  pop(): f64 {
      if (this.length === 0) return null;

      let top = this.ids[0];
      this.length--;

      if (this.length > 0) {
          let id = this.ids[0] = this.ids[this.length];
          let value = this.values[0] = this.values[this.length];
          let halfLength = this.length >> 1;
          let pos = 0;

          while (pos < halfLength) {
              let left = (pos << 1) + 1;
              let right = left + 1;
              let bestIndex = this.ids[left];
              let bestValue = this.values[left];
              let rightValue = this.values[right];

              if (right < this.length && rightValue < bestValue) {
                  left = right;
                  bestIndex = this.ids[right];
                  bestValue = rightValue;
              }
              if (bestValue >= value) break;

              this.ids[pos] = bestIndex;
              this.values[pos] = bestValue;
              pos = left;
          }

          this.ids[pos] = id;
          this.values[pos] = value;
      }

      this.ids.pop();
      this.values.pop();

      return top;
  }

  peek(): f64 {
      return this.ids[0];
  }

  peekValue(): f64 {
      return this.values[0];
  }
}