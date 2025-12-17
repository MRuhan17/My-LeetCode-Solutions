int calPoints(char** operations, int operationsSize) {

    int* record = (int*)malloc(operationsSize * sizeof(int));
    int top = -1;

    for (int  i = 0; i < operationsSize; i++) {
        if (strcmp(operations[i], "+") == 0) {
            int newScore = record[top] + record[top - 1];
            record[++top] = newScore;
        }
        else if (strcmp(operations[i], "D") == 0){
            int newScore = 2 * record[top];
            record[++top] = newScore;
        }
        else if (strcmp(operations[i], "C") == 0){
            top--;
        }
        else{
            int num = atoi(operations[i]);
            record[++top] = num;
        }
    }

    int sum = 0;
    for(int i = 0; i <= top; i++){
        sum += record[i];
    }

    free(record);
    return sum;
}
