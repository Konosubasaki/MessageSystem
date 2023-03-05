
#ifndef MESSAGESYSTEM_H_
#define MESSAGESYSTEM_H_
#include <MessageQueue.h>

/// A generic message handler that takes messages via send() and allows iteration over
/// all committed (see commitAll()) messages.
class MessageSystem
{
public:
    MessageSystem();
    ~MessageSystem();

    typedef std::size_t size_type;
    typedef std::vector<std::shared_ptr<BaseMessage>>::iterator iterator;
    typedef std::vector<std::shared_ptr<BaseMessage>>::const_iterator const_iterator;

    /// Send the given message.
    ///
    /// Note that it will only be activated when commitAll() is called.
    template < class T >
    void send(const std::shared_ptr<T>& e)
    {
        queue.enqueue(e);
    }

    template < class Begin, class End >
    void send(Begin& begin, End& end)
    {
        for (iterator iter = begin; iter != end; ++iter) {
            queue.enqueue((*iter));
        }
    }

    /// Activates all previously sent messages.
    void commitAll();

    /// Empties all message queues.
    void clearAll();

    /// Prints all active messages on the console from the start position to the end
    void printAllActiveMessages();

    /// Prints all messages, both active and inactive
    void printAllMessages();

    /// Prints all active messages of the specified type
    void printAllActiveMessagesOfSameType(MessageType const type);
     
    /// Returns the message at the specified index
    const std::shared_ptr<BaseMessage>& getMessage(std::size_t const index);

    /// Returns the begin iterator over all messages of the given type.
    const_iterator begin() const;

    /// Returns the end iterator over all messages of the given type.
    const_iterator end() const;

    /// Returns the number of active messages of any type.
    size_type count() const;

    /// Returns the number of active messages for the given type.
    size_type count(MessageType const type) const;

    /// Returns true if collection of messages is empty, false if is not.
    bool empty() const;

    /// Returns true if collection of messages is empty for the given type, false if is not.
    bool empty(MessageType const type) const;

private:
    /// Collection of all active/pending messages of any type.
    MessageQueue queue;
};

#endif
