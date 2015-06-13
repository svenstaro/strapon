#ifndef STATE_HPP
#define STATE_HPP

class State {
public:
    virtual int init() = 0;
    virtual void update(double dt) = 0;
    virtual ~State() {};
};

#endif /* end of include guard: STATE_HPP */
