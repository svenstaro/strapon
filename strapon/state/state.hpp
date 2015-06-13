#ifndef STATE_HPP
#define STATE_HPP

class State {
public:
    virtual int init() = 0;
    virtual void update(float dt) = 0;
    virtual ~State() = 0;
};

#endif /* end of include guard: STATE_HPP */
