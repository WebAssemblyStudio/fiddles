function findMinEdgeVertex(
  minimumWeightedEdgeByVertex: Int32Array,
  visitedList: Array<bool>
): i32 {
  let minWeight = I32.MAX_VALUE;
  let minVertexIndex: i32=0;
  for(let vertexIndex=0; vertexIndex < visitedList.length; vertexIndex++){  
  const visited = visitedList[vertexIndex];
    const isLess = (minimumWeightedEdgeByVertex[vertexIndex] < minWeight);
    if (!visited && isLess) {
      minVertexIndex = vertexIndex;
      minWeight = minimumWeightedEdgeByVertex[vertexIndex];
    }
  }
  return minVertexIndex;
}

export class MST{
  parent: i32;
  vertex: i32;
}
export function mst(graph: i32[][]): MST[] {
  const mstSet = new StaticArray<i32>(graph.length);
  const minimumWeightedEdgeByVertex = new Int32Array(graph.length).fill(
    I32.MAX_VALUE
  );
  const visited = new Array<bool>(graph.length).fill(false);

  minimumWeightedEdgeByVertex[0] = 0;
  mstSet[0] = -1; // starting vertex can't have parent per say

  for (let i = 0; i < graph.length - 1; i++) {
    const u = findMinEdgeVertex(minimumWeightedEdgeByVertex, visited);
    visited[u] = true;
    for (let v = 0; v < graph.length; v++) {
      if (
        graph[u][v] &&
        visited[v] === false &&
        graph[u][v] < minimumWeightedEdgeByVertex[v]
      ) {
        mstSet[v] = u;
        minimumWeightedEdgeByVertex[v] = graph[u][v];
      }
    }
  }

  return mstSet.slice(0)
         .map<MST>((parent: i32, vertex: i32, _: i32[]): MST=>({parent, vertex}));
}


export const MST_ID = idof<MST[]>();
export const EDGE_ID = idof<i32[]>();
export const VERTEX_ID = idof<i32[][]>();

