#ifndef OBSERVER_H
#define OBSERVER_H


class Observer
{
public:
    Observer() {}

    virtual void update() = 0;
    virtual ~Observer() {}
};

#endif // OBSERVER_H
