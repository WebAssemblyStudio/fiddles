export class Test {
    public constructor() {
        const a = new Vertex();
        const b = new Vertex();
        const c = new Vertex();
        const d = new Vertex();

        const faces: Face[] = [];
        faces.push( this.createTriangle( a, c, b ) );
        faces.push( this.createTriangle( d, a, b ) );
        faces.push( this.createTriangle( d, b, c ) );
        faces.push( this.createTriangle( d, c, a ) );

        for ( let i = 0; i < 3; i++ ) {
            const k = ( i + 1 ) % 3;
            faces[ i + 1 ].getEdge( 0 ).setTwin( faces[ k + 1 ].getEdge( 1 ) );
            faces[ i + 1 ].getEdge( 2 ).setTwin( faces[ 0 ].getEdge( ( 3 - i ) % 3 ) );
        }

        const nextFace = faces[ 3 ];
        const nextVertex = new Vertex();
        const newFaces = this.buildFaces( nextVertex, [ nextFace.edge!, nextFace.edge!.next! ] );

        gc.collect();
        this.merge( newFaces[ 0 ], newFaces[ 0 ].edge! );
        gc.collect();
    }

    private merge( face: Face, edge: Edge ): void {
        const oppositeEdge = edge.twin!;
        const previousOppositeEdge = oppositeEdge.previous!;
        const nextOppositeEdge = oppositeEdge.next!;

        for ( let currentEdge = nextOppositeEdge; currentEdge !== previousOppositeEdge.next; currentEdge = currentEdge.next! ) {
            currentEdge.face = face;
        }
    }

    private buildFaces( eyeVertex: Vertex, horizon: Edge[] ): Face[] {
        const newFaces: Face[] = [];
        let hedgeSidePrevious: Edge|null = null;
        let hedgeSideBegin: Edge|null = null;

        for ( let i = 0; i < horizon.length; i++ ) {
            const edge = horizon[ i ];
            const newFace = this.createTriangle(
                eyeVertex,
                edge.getHead(),
                edge.getTail()
            );
            newFaces.push( newFace );
            newFace.getEdge( 2 ).setTwin( edge.twin! );

            const hedgeSide = newFace.edge!;
            if ( hedgeSidePrevious !== null ) {
                hedgeSide.next!.setTwin( hedgeSidePrevious );
            } else {
                hedgeSideBegin = hedgeSide;
            }

            hedgeSidePrevious = hedgeSide;
        }

        hedgeSideBegin!.next!.setTwin( hedgeSidePrevious! );

        return newFaces;
    }

    private createTriangle( a: Vertex, b: Vertex, c: Vertex ): Face {
        const face = new Face();
        const edgeAb = new Edge();
        edgeAb.tail = a;
        edgeAb.face = face;
        const edgeBc = new Edge();
        edgeBc.tail = b;
        edgeBc.face = face;
        const edgeCa = new Edge();
        edgeCa.tail = c;
        edgeCa.face = face;

        edgeAb.previous = edgeCa;
        edgeAb.next = edgeBc;
        edgeBc.previous = edgeAb;
        edgeBc.next = edgeCa;
        edgeCa.previous = edgeBc;
        edgeCa.next = edgeAb;

        face.edge = edgeAb;

        return face;
    }
}

export class Vertex {
}

export class Edge {
    public next: Edge|null = null;

    public previous: Edge|null = null;

    public twin: Edge|null = null;

    public tail: Vertex|null = null;

    public face: Face|null = null;

    public getHead(): Vertex {
        return this.twin!.tail!;
    }

    public getTail(): Vertex {
        return this.tail!;
    }

    public setTwin( twin: Edge ): void {
        this.twin = twin;
        twin.twin = this;
    }
}

export class Face {
    public edge: Edge|null = null;

    public getEdge( idx: i32 ): Edge {
        let result = this.edge!;
        while ( idx > 0 ) {
            result = result.next!;
            idx--;
        }

        return result;
    }
}

new Test();
