// #include <stdio.h>
// int min_nbr(int *stack, int pbn, int *f)
// {
//     int i = 0;
//     int m = stack[0];
//     while(i < pbn)
//     {
//         if(stack[i] < m)
//         {
//             m = stack[i];
//             (*f) = i;
//         }
//         i++;
//     }
//     return(m);
// }
// int main()
// {
//     int stack[5];
//     stack[0] = 8;
//     stack[1] = 3;
//     stack[2] = 2;    
//     stack[3] = 8;
//     stack[4] = 1;
//     int f = 0;
//     printf("%d",min_nbr(stack, 5, &f));
//     printf("f = %d", f);
// }