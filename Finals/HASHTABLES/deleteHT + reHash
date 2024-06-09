int HTdelete(int *T, int k) {
    int index = h(k, 0);     /* index */
    int indexActual = index; /* save original index */
    int c = 0;               /* counter */

    while (c < N && T[index] != -1 && T[index] != k) {
        c++;
        index = h(k, c); /* newfloat */
    }

    if (c >= N || T[index] == -1) /* not found */
        return -1;

    /* delete */
    T[index] = -1;

    /* reorder */
    int j = (index + 1) % N; /* next index to examine for potential rehashing */
    /* check until the entire sequence has been traversed or unttil empty slot
     * is encountered*/
    while (j != indexActual && T[j] != -1) {
        if (h(T[j], 0) != j) {
            /* if this element is not at the correct position */
            int tmpK = T[j]; /* aha: tmp because might end up at same place? */
            T[j] = -1;
            insertH(T, tmpK);
        }
        j = (j + 1) % N;
    }

    return index;
}
