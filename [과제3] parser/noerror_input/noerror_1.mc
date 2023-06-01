int main()
{
    int i = 1;
    while (i <= 9) {
        int j = 1;
        while (j <= 9) {
            printf(i * j);
            j++;
        }
        i++;
    }

    return 0;
}
