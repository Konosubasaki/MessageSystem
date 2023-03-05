#include "MessageSystem.h"

MessageSystem::MessageSystem() { }

MessageSystem::~MessageSystem() { }

void MessageSystem::commitAll()
{
    queue.commit();
}

void MessageSystem::clearAll()
{
    queue.clear();
}

///Prints all active messages from the start position to the end
void MessageSystem::printAllActiveMessages()
{
    queue.printAllActiveMessages();
}

///Prints all messages, both active and inactive
void MessageSystem::printAllMessages()
{
    queue.printAllMessages();
}

///Prints all active messages of the specified type
void MessageSystem::printAllActiveMessagesOfSameType(MessageType const type)
{
    return queue.printAllActiveMessagesOfSameType(type);
}

///Returns the message at the specified index
const std::shared_ptr<BaseMessage>& MessageSystem::getMessage(std::size_t const index)
{
    if (index < (queue.count()))
    {
        return queue.getMessage(index);
    }
    else
        return std::shared_ptr<BaseMessage>();
}

/// Returns the begin iterator over all messages
std::vector<std::shared_ptr<BaseMessage>>::const_iterator MessageSystem::begin() const
{
    return queue.begin();
}

/// Returns the end iterator over all messages
std::vector<std::shared_ptr<BaseMessage>>::const_iterator MessageSystem::end() const
{
    return queue.end();
}

/// Returns the number of active messages
std::size_t MessageSystem::count() const
{
    return queue.count();
}

/// Returns the number of active messages of the specified type
std::size_t MessageSystem::count(MessageType const type) const
{
    return queue.count(type);
}

/// Returns true if collection of messages is empty, false if is not.
bool MessageSystem::empty() const
{
    if (queue.count() > 0)
    {
        return false;
    }
    return true;
}

/// Returns true if collection of messages is empty for the given type, false if is not.
bool MessageSystem::empty(MessageType const type) const
{
    if (queue.count(type) > 0)
    {
        return false;
    }
    return true;
}

