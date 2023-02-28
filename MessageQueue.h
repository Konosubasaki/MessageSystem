
#ifndef MESSAGEQUEUE_H_
#define MESSAGEQUEUE_H_

#include "Message.h"
#include <memory>
#include <vector>

/// A list of messages that can be iterated over.
class MessageQueue
{
public: 
    MessageQueue() : activeMessageStart_(0), activeMessageCount_(0)
    {
        //Determining the messages_ vector capacity
        messages_.reserve(5);
    }

    typedef std::size_t size_type;

    /// Copies the given message into the queue.
    template < class T >
    void enqueue(const std::shared_ptr<T>& message)
    {
        if (messages_.size() < messages_.capacity())
        {
            messages_.push_back(message);
        }
        else
        {
            overflowMessages_.push_back(message);
        }
    }

    /// Makes all pending messages active in addition to those that already were active before.
    void commit()
    {
        if (!overflowMessages_.empty())
        {
            messages_.insert(messages_.end(), overflowMessages_.begin(), overflowMessages_.end());
            overflowMessages_.clear();
        }
        activeMessageStart_ = 0;
        activeMessageCount_ = messages_.size();
    }

    /// Discards all messages.
    void clear()
    {
        messages_.clear();
        overflowMessages_.clear();
        activeMessageCount_ = 0;
    }

    /// Prints only active messages
    void printAllActiveMessages() const
    {
        for (const_iterator iter = begin(); iter != end(); ++iter) {
            (*iter)->printMessage(); // call a function on each message
        }
    }

    /// Prints all messages, both active and inactive
    void printAllMessages() const
    {
        for (const_iterator iter = messages_.begin(); iter != messages_.end(); ++iter) {
            (*iter)->printMessage(); // call a function on each message
        }
    }

    /// Prints all active messages of the specified type
    void printAllActiveMessagesOfSameType(MessageType const type) const {

        for (const_iterator iter = begin(); iter != end(); ++iter) {
            if ((*iter)->type() == type)
                (*iter)->printMessage();
        }
    }

    typedef  std::vector<std::shared_ptr<BaseMessage>> MessageList;
    typedef typename MessageList::iterator iterator;
    typedef typename MessageList::const_iterator const_iterator;

    iterator begin() { return messages_.begin() + activeMessageStart_; }
    iterator end() { return messages_.begin() + activeMessageCount_; }
    const_iterator begin() const { return messages_.begin() + activeMessageStart_; }
    const_iterator end() const { return messages_.begin() + activeMessageCount_; }

    /// Returns the message at the specified index
    std::shared_ptr<BaseMessage>& getMessage(std::size_t const index)
    {
            return messages_[activeMessageStart_ + index];
    }

    /// Returns the number of active messages that can be iterated over.
    std::size_t count(MessageType const type) const {

        std::size_t counter = 0;
        for (const_iterator iter = begin(); iter != end(); ++iter) {
            if ((*iter)->type() == type)
                counter++;
        }
        return counter;
    }

    /// Returns the number of active messages that can be iterated over.  
    std::size_t count() const {
        return activeMessageCount_ - activeMessageStart_;
    }

private:
    /// Holds all messages.
    MessageList messages_;

    /// Possibly holds any pending messages that, if they were appended to messages_,
    /// would have caused it to invalidate its iterators.
    MessageList overflowMessages_;

    /// Offset in messages_ that basically hides all messages at a lower position.
    std::size_t activeMessageStart_;

    /// Specifies how many messages (from the start) in messages_ are active.
    std::size_t activeMessageCount_;

};



#endif
