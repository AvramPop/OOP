#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int values[20];
    int length;
} array;

/**
 * Print sequence of vector starting from startIndex of length sequenceLength.
 * @param vector: given array
 * @param startIndex: the start index
 * @param sequenceLength: the sequence length
 */
void printSequence(array vector, int startIndex, int sequenceLength) {
    int i;
    printf("longest sequence: ");
    for(i = startIndex; i < startIndex + sequenceLength; ++i) {
        printf("%d ", vector.values[i]);
    }
}

/**
 * Return read integer, took from standard input after printed message.
 * @param message: message to ask for input
 * @return read int value
 */
int readInteger(char *message) {
     char sentenceToRead[20];
     int validNumber = 0;
     printf(message);
     scanf("%s", sentenceToRead);
     while(!sscanf(sentenceToRead, "%d", &validNumber)) {
         scanf("%s", sentenceToRead);
     }
     return validNumber;
}

/**
 * Check whether given number is prime.
 * @param number: given number
 * @return true if number is prime, false otherwise
 */
bool isPrime(int number) {
    if(number < 2) return false;
    if(number % 2 == 0 && number != 2) return false;
    int d;
    for(d = 2; d * d <= number; d++) {
        if(number % d == 0) return false;
    }
    return true;
}

/**
 * Find longest sequence of vector that has the difference between terms a prime number.
 * @param vector: given array to study
 * @param startIndex: the beginning of found sequence
 * @param sequenceLength: he length of found sequence
 */
void longestSequenceWithPrimeDifference(array vector, int* startIndex, int* sequenceLength) {
    int maximumLength = 1, maximumStart = 0;
    int actualLength, actualStart = 0;
    int i = 1;
    while(i < vector.length) {
        while(isPrime(vector.values[i] - vector.values[i - 1])) {
            i++;
        }
        actualLength = i - actualStart;
        if(actualLength > maximumLength) {
            maximumLength = actualLength;
            maximumStart = actualStart;
        }
        actualStart = i;
        i++;
    }
    if(isPrime(vector.values[i + 1] - vector.values[i])) {
        i++;
    }
    actualLength = i - actualStart;
    if(actualLength > maximumLength) {
        maximumLength = actualLength;
        maximumStart = actualStart;
    }
    *startIndex = maximumStart;
    *sequenceLength = maximumLength;
}

/**
 * Read length of array and then length of given length.
 * @return the read array (custom format)
 */
array readVector() {
    array vector;
    int length = readInteger("length = ");
    vector.length = length;
    printf("values: ");
    int currentNumber;
    for(int i = 0; i < vector.length; i++) {
        currentNumber = readInteger("");
        vector.values[i] = currentNumber;
    }
    return vector;
}

int main() {
    array vector;
    vector = readVector();
    int startIndex = -1, sequenceLength = -1;
    longestSequenceWithPrimeDifference(vector, &startIndex, &sequenceLength);
    printSequence(vector, startIndex, sequenceLength);
    return 0;
}
