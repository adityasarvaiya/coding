We can not use binary search directly as it will only return if some element is present in a given array or not. There once we see the target element we return the true or its index.

In modified Binary search, we will not return anything immediately. Instead we will try to form a series of zeros followed by series of ones or series of ones followed by series of zeros. 

For finding the first occurrence of query Q, we will try to form a series of zeros followed by a series of ones. And similarly for finding the last occurrence, we will try to form a series of ones followed by a series of zeros. For example, given an array A = [1 2 2 2 3 4] and we need to find query Q = 2. For first occurrence we will form [0 1 1 1 1 1] and for last occurrence [1 1 1 1 0 0]. 



findFirstOccurrence (array) {

    while (high >= low) {

        Calculate mid

        if mid is equal to target and mid is the first element or mid - 1 is < target

            mid is the required answer. Return mid.

        else if mid is equal or larger than target, search left half

        else search right half

    }

    return -1

}

findLastOccurrence (array) {

    while (high >= low) {

        Calculate mid

        if mid is equal to target and mid is the last element of array or mid + 1 is > target

            mid is the required answer. Return mid.

        else if mid is equal or smaller than target, search right half

        else search left half

    }

    return -1

}


findElementInMatrix(matrix, target) {
    found = false
    If number of rows > number of columns, search column by column
    Else search row by row
    For each row or column {
        BinarySearch (row) or BinarySearch (column)
        if found return true
    }
    return false
}

binarySearchMatrix(matrix, target, row_search_flag, row_or_column_index) {       
        if row_search_flag is true {
            do row_search for row with specified index
            return true if found
        }
        else {
            do column_search for column with specified index
            return true if found
        }
        return false

        Note: Keep common binary search operations such as 'mid = high + low / 2' common
        and have if else as required in between the common sections.

}


swapBits (n) {
    Loop over 16 times, or have i from 0 to 32 and increment i by 2
    Use right shift and bitwise AND with 1 to isolate each of the 2 adjacent bits. 
    Use XOR to compare the 2 bits are same or different    
    if the 2 bits are different {
        Repeat below for each of the 2 bits
        Use 1 left shifted to the bit position and XOR with n
        Note: XOR with 1 will flip a bit. 0^1 = 1 and 1^1 = 0.
    }
}

swapBits (n) {

    Isolate even bit values by doing AND of input with 0xAAAAAAAA, 
    which has all even bits set to 1. Say odd bits

    Isolate odd bit values by doing AND of input with 0x55555555, 
    which has all odd bits set to 1. Say even bits   

    rightshift even bits by 1 position lets say updatedEven

    leftshift odd bits by 1 position lets say updatedOdd

    return bit wise or of updatedEven and updatedOdd
}




https://docs.google.com/document/d/170QgaAdoEh7ykaeZXKbiJTrq8Iu4Ks8L3RRPAf-enCU/edit?usp=sharing
https://docs.google.com/document/d/1obWwDskgtPVYbIlhT0iN7NKeg0TqGf5TA9awe7FtCpY/edit?usp=sharing



CountNumBitsToFlip (A, B) {
    Calculate the XOR of A and B. This result will only have set bits where A and B differ.
    Count the number of 1 bits in this XORed result.
    This is the required number. Return this.
}
