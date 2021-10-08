#include <stdio.h>
#include <stdlib.h>

#define MaxLenght 100
typedef char ElementType;
typedef struct
{
    ElementType Elements[MaxLenght];
    int Front, Rear;
} Queue;

void makenullQueue(Queue *pQ)
{
    pQ->Front = -1;
    pQ->Rear = -1;
}

int emptyQueue(Queue Q)
{
    return Q.Front == -1;
}

int fullQueue(Queue Q)
{
    return ((Q.Rear - Q.Front + 1) == MaxLenght);
}

ElementType front(Queue Q)
{
    return Q.Elements[Q.Front];
}

void deQueue(Queue *pQ)
{
    if (!emptyQueue(*pQ))
    {
        if (pQ->Front == pQ->Rear)
            makenullQueue(pQ);
        else
            pQ->Front = pQ->Front + 1;
    }
}

void enQueue(ElementType x, Queue *Q)
{
    int i;
    if (!fullQueue(*Q))
    {
        if (emptyQueue(*Q))
            Q->Front = 0;
        if (Q->Rear == MaxLenght - 1)
        {
            for (i = Q->Front; i <= Q->Rear; i++)
            {
                Q->Elements[i - Q->Front] = Q->Elements[i];
            }
            Q->Rear = MaxLenght - 1 - Q->Front;
            Q->Front = 0;
        }
        Q->Rear = Q->Rear + 1;
        Q->Elements[Q->Rear] = x;
    }
}

// int main()
// {
//     int n, x;
//     char cuphap;
//     scanf("%d%*c", &n);
//     Queue Q;
//     makenullQueue(&Q);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%c", &cuphap);
//         if (cuphap == 'E')
//         {
//             scanf("%d%*c", &x);
//             enQueue(x, &Q);
//             printf("%d\n", Q.Rear - Q.Front + 1);
//         }
//         else if (cuphap == 'D')
//         {
//             scanf("%*c");
//             printf("%d ", emptyQueue(Q) == 1 ? -1 : front(Q));
//             deQueue(&Q);
//             printf("%d\n", emptyQueue(Q) == 1 ? 0 : Q.Rear - Q.Front + 1);
//         }
//     }
//     return 0;
// }

// int main()
// {
//     int n, i, time=0;
//     int cv1, cv2;
//     Queue Q1, Q2;
//     makenullQueue(&Q1);
//     makenullQueue(&Q2);
//     scanf("%d", &n);
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &cv1);
//         enQueue(cv1, &Q1);
//     }

//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &cv2);
//         enQueue(cv2, &Q2);
//     }

//     while (!emptyQueue(Q1) && !emptyQueue(Q2))
//     {
//         if (front(Q1) != front(Q2))
//         {
//             enQueue(front(Q1), &Q1);
//             deQueue(&Q1);
//             time++;
//         }
//         else
//         {
//             deQueue(&Q1);
//             deQueue(&Q2);
//             time++;
//         }
//     }
//     printf("%d", time);
//     return 0;
// }
