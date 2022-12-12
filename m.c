// #include <stdio.h>
// void rrb(int *stackb, int pbn)
// {
//     int m ;
//     int i = pbn;
//     int tmp[0];
//     tmp[0] = stackb[i - 1];
//     m = i - 1;
//     while(m > 0)
//     {
//         stackb[m] = stackb[m - 1];
//         m--;
//     }
//     stackb[0] = tmp[0];
//     stackb[i] = '\0';
// }

// int main()
// {
//     int stackb[4];
//     stackb[0] = 1;
//     stackb[1] = 2;
//     stackb[2] = 3;    
//     stackb[3] = 4;
//     rrb(stackb, 4);
//     printf("%d", stackb[0]);
//     printf("%d", stackb[1]);
//     printf("%d", stackb[2]);
//     printf("%d", stackb[3]);

// }