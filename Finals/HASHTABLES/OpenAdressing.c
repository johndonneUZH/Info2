// a standard hash function
int hash1(int k) { return (k * 23) % 109; }

void linearCollision(int k)
    int probe = (hash(k) + i) % N; 
    return probe;
}
void quadraticCollision(int k, int i) {
    int probe = (hash(k) + i**2) % N;
    return probe;
}

// double hashing
int hash1(int k) { return (k * 23) % 109; }
int hash2(int k) { return (k * 34) % 63; }

doubleCollisionSearch(int k, int i) {
    int probe = (hash1(k) + i*(hash2(k) % N);  // we're jumping by a factor of delta buckets where delta is hash2(k) % N
    return probe;
}
