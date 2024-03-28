#define SIZE 50

struct queue{
    int begin, end;
    float nums[SIZE];
};

void create_queue(queue* queue){
    queue -> begin = 0;
    queue -> end = -1;
}


int push(queue* queue, float number){
    queue -> end = (queue -> end + 1) % SIZE;
    queue -> nums[queue -> end] = number;
    return 1;
}

int is_empty(queue queue){
    return queue.end == queue.begin - 1;
}

int is_full(queue queue){
    return queue.begin == queue.end;
}


float pop(queue* queue){
    float element = queue -> nums[queue -> begin];
    if(is_full(*queue)){
        queue -> begin = 0;
        queue -> end = -1;
    }
    else
        queue -> begin = (queue -> begin + 1) % SIZE;
    return element;
}



