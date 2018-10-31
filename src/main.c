#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

char str[] = "Hello World";

WASM_EXPORT
char* getStrOffset () {
  return &str[0];
}

typedef struct huffman_node_t
{
    int value;          /* character(s) represented by this entry */
    count_t count;      /* number of occurrences of value (probability) */

    char ignore;        /* TRUE -> already handled or no need to handle */
    int level;          /* depth in tree (root is 0) */

    /***********************************************************************
    *  pointer to children and parent.
    *  NOTE: parent is only useful if non-recursive methods are used to
    *        search the huffman tree.
    ***********************************************************************/
    struct huffman_node_t *left, *right, *parent;
} huffman_node_t;

typedef unsigned int count_t;       /* unsigned 32 bit for character counts */

/****************************************************************************
*   Function   : HuffmanDecodeFile
*   Description: This routine reads a Huffman coded file and writes out a
*                decoded version of that file.
*   Parameters : inFile - Open file pointer for file to decode
*                outFile - Open file pointer for file receiving decoded data
*   Effects    : Huffman encoded file is decoded
*   Returned   : 0 for success, -1 for failure.  errno will be set in the
*                event of a failure.  Either way, inFile and outFile will
*                be left open.
****************************************************************************/


WASM_EXPORT
int HuffmanDecodeFile(FILE *inFile, FILE *outFile)
{
    huffman_node_t *huffmanArray[NUM_CHARS];    /* array of all leaves */
    huffman_node_t *huffmanTree;
    huffman_node_t *currentNode;
    int i, c;

    while ((c = BitFileGetBit(bInFile)) != EOF)
    {
        /* traverse the tree finding matches for our characters */
        if (c != 0)
        {
            currentNode = currentNode->right;
        }
        else
        {
            currentNode = currentNode->left;
        }

        if (currentNode->value != COMPOSITE_NODE)
        {
            /* we've found a character */
            if (currentNode->value == EOF_CHAR)
            {
                /* we've just read the EOF */
                break;
            }

            fputc(currentNode->value, outFile); /* write out character */
            currentNode = huffmanTree;          /* back to top of tree */
        }
    }

    /* clean up */
    inFile = BitFileToFILE(bInFile);            /* make file normal again */
    FreeHuffmanTree(huffmanTree);     /* free allocated memory */

    return 0;
}
