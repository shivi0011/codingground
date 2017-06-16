/*All you need is a 3-dimensional array to store the array of chunks, and modulo arithmetic plus integer division to insert into the appropriate column of the appropriate chunk:
*/
/* the variable-sized dimension of the `chunks' argument is w / chsz elements big
 * (it's the number of chunks)
 */
void split(int h, int w, int mat[h][w], int chsz, int chunks[][h][chsz])
{
    /* go through each row */
    for (int i = 0; i < h; i++) {
        /* and in each row, go through each column */
        for (int j = 0; j < w; j++) {
            /* and for each column, find which chunk it goes in
             * (that's j / chsz), and put it into the proper row
             * (which is j % chsz)
             */
            chunks[j / chsz][i][j % chsz] = mat[i][j];
        }
    }
}

Demonstration, a. k. a. how to call it:

int main(int agrc, char *argv[])
{
    const size_t w = 8;
    const size_t h = 3;
    const size_t c = 2;

    int mat[h][w] = {
        { 1, 2, 3, 4, 5, 6, 7, 8 },
        { 1, 2, 3, 4, 5, 6, 7, 8 },
        { 1, 2, 3, 4, 5, 6, 7, 8 }
    };

    int chunks[w / c][h][c];

    split(h, w, mat, c, chunks);

    for (int i = 0; i < w / c; i++) {
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < c; k++) {
                printf("%3d ", chunks[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }

    return 0;
}
