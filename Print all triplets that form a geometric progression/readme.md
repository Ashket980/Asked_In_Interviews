## Print all triplets that form a geometric progression ##


**Given a sorted array of distinct positive integers, print all triplets that forms a geometric progression with an integral common ratio.**


**A geometric progression is a sequence of numbers where each term after the first is found by multiplying the previous one by a fixed, 
non-zero number called the common ratio. For example, sequence 2, 6, 18, 54,… is a geometric progression with a common ratio of 3.**

    For example,

        Input:  A[] = { 1, 2, 6, 10, 18, 54 }

        Output:
        2 6 18
        6 18 54


        Input:  A[] = { 2, 8, 10, 15, 16, 30, 32, 64 }

        Output:
        2 8 32
        8 16 32
        16 32 64


        Input:  A[] = { 1, 2, 6, 18, 36, 54 }

        Output:
        2 6 18
        1 6 36
        6 18 54


        Input:  A[] = { 1, 2, 4, 16 }

        Output:
        1 2 4
        1 4 16


        Input:  A[] = {1, 2, 3, 6, 18, 22};

        Output:
        2 6 18
