int cuckooInsert(int k, int *HT1, int *HT2)
{
    bool turn1 = true;
    int index;
    int j = k;

    int MaxIteration = 50;

    while (MaxIteration >= 0)
    {
        if (turn1)
        {
            index = h1(j);
            if (HT1[index] != EMP)
            {
                int temp = HT1[index];
                HT1[index] = j;
                j = temp;
            }
            else
            {
                HT1[index] = j;
                break;
            }
            turn1 = false;
        }

        else if (!turn1)
        {
            index = h2(j);
            if (HT2[index] != EMP)
            {
                int temp = HT2[index];
                HT2[index] = j;
                j = temp;
            }
            else
            {
                HT2[index] = j;
                break;
            }
            turn1 = true; 
        }
        MaxIteration--;
    }
}
