#include <stdio.h>

int main()
{

    int num,cubic;

    for (int nua = 1; nua < 10; ++nua)
    {
        for (int nub = 0; nub < 10; ++nub)
        {
            for (int nuc =0;nuc<10; ++nuc)
            {
                num = 100 * nua + 10 * nub + nuc;
                cubic = nua * nua * nua + nub * nub * nub + nuc * nuc * nuc;
                if (num == cubic)
                    printf("%d ", num);
            }
        }
    }

    return 0;
}
