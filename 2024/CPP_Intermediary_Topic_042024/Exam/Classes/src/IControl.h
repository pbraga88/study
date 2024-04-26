#pragma once

class IControl {
public:
    IControl(void);
    virtual ~IControl(void);

    virtual void Start()=0;
    virtual void Stop()=0;
    virtual bool IsStarted() const =0;
};