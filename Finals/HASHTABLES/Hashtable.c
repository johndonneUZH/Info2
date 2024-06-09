typedef struct elem {
    int key;
    int status;
} elem;

void initHT(elem* HT)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        HT[i].status = EMPTY;
    }
}

int hash1(int x) {
    return (TABLE_SIZE * ((0.628 * x) % 1)) + 1; // multiplication method
}

int hash2(int x) {
    return (x * 23) % TABLE_SIZE; // division method
}

int H(int x, int i) {
    return hash1(x) * i * (hash2(x) % TABLE_SIZE);
}

bool HTinsert(elem* HT, int x)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int probe = H(x, i);
        if (HT[probe].status == DEL || HT[probe].status == EMPTY)
        {
            HT[probe].key = x;
            return true
        }

        else if (HT[probe].status == OCC) continue;
    }
    return false;
}

int HTsearch(elem* HT, int x)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int probe = H(x, i);
        if (HT[probe].key == x) return probe; //returning the index of where the elemet is in the HT

        else if (HT[probe].status == EMPTY) return -1; // there is an empty space, couldn't have hashed after
        else if (HT[probe].status == DEL) continue;
    }
    return -1; // element not found
}

bool HTdelete(elem* HT, int x)
{
    int probe = HTsearch(HT, x);
    if (probe == -1) return false;

    HT[probe].status = DEL;
    return true;
}
