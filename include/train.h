// train.h
#ifndef TRAIN_H
#define TRAIN_H

class Train {
private:
    struct Car {
        bool light;
        Car* next;
        Car* prev;
        Car(bool l) : light(l), next(nullptr), prev(nullptr) {}
    };

    Car* first;
    int countOp;

public:
    Train();
    ~Train();

    void addCar(bool light);
    int getLength();
    int getOpCount() const;
    void resetOpCount();
};

#endif
