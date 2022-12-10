// void sort(int *stack, int l)
// {
//     int i = 0;
//     int tmp[1];
//     int m = l;
//     while(m >= 0)
//     {
//         i = l - 1;
//         while(i > 0)
//         {
//             if(stack[i - 1] < stack[i])
//             {
//                 tmp[0] = stack[i];
//                 stack[i] = stack[i - 1];
//                 stack[i - 1] = tmp[0];
//             }
//             i--;
//         }
//         m--;
//     }
//     i = 0;
//     while (i < l)
//     {
//         ft_printf("%d ", stack[i]);
//         i++;
//     }
// }