
#ifndef MESSAGE_H_
#define MESSAGE_H_
#include <iostream> 

/// Type of message type IDs.
typedef int MessageType;

class Message
{
public:
    Message() {}
};

/// Base class for all messages.
class BaseMessage : public Message
{
public:
    BaseMessage() {}
    virtual ~BaseMessage() {}
    virtual MessageType type() = 0;
    virtual void printMessage() = 0; 
 };

class DamageMessage : public BaseMessage 
{
public:
    DamageMessage() {}
    ~DamageMessage() {}
    void printMessage() override  {
        std::cout << "---I am damage message---"<< std::endl;
    }

    MessageType type() override
    {
        return typeId_;
    }

protected:
    static constexpr MessageType typeId_ = 1;
};

class HealingMessage : public BaseMessage 
{
public:
    HealingMessage() {}
    ~HealingMessage() {}
    void printMessage() override {
        std::cout << "---I am healing message---" << std::endl;
    }

    MessageType type() override
    {
        return typeId_;
    }

protected:
    static constexpr MessageType typeId_ = 2;
};


class MissionCompletedMessage : public BaseMessage
{
public:
    MissionCompletedMessage() {}
    ~MissionCompletedMessage() {}
    void printMessage() override {
        std::cout << "---I am mission completed message---" << std::endl;
    }

    MessageType type() override
    {
        return typeId_;
    }

protected:
    static constexpr MessageType typeId_ = 3;
};

#endif
