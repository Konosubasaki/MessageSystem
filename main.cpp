#include "MessageSystem.h"

//Run this function in main() if you want to test MessageSystem class
void testingMessageSystem(MessageSystem& messageSystem)
{ 
    //Sending new messages.
    messageSystem.send(std::make_shared<DamageMessage>());
    messageSystem.send(std::make_shared<HealingMessage>());
    std::cout << "Are there any messages? " << (messageSystem.empty() ? "No, there are not." : "Yes, there are.") << std::endl;

    std::cout << "You should first commit all messages! ***Let's commit it!***" << std::endl;
    messageSystem.commitAll();

    std::cout << "Are there any messages? " << (messageSystem.empty() ? "No, there are not." : "Yes, there are. I will print it now.") << std::endl;
    //Printing all active messages from start position.
    messageSystem.printAllActiveMessages();
    std::cout << "___________________________________" << std::endl;

    std::cout << "*** Deleting all messages ***" << std::endl;
    messageSystem.clearAll();

    std::cout << "Are there any messages? " << (messageSystem.empty() ? "No, there are not." : "Yes, there are.") << std::endl;

    std::cout << "*** Sending and committing new messages again ***" << std::endl;
    //Sending new messages again.
    messageSystem.send(std::make_shared<DamageMessage>());
    messageSystem.send(std::make_shared<HealingMessage>());
    messageSystem.send(std::make_shared<HealingMessage>());
    messageSystem.commitAll();

    //Printing all active messages from start position.
    messageSystem.printAllActiveMessages();

    //How many messages are active?
    std::cout << "How many messages are active?" << std::endl;
    std::cout << messageSystem.count() << std::endl;

    //How many messages are active with typeID=1 aka type=DamageMessage?
    std::cout << "How many messages are active with typeID=1 aka type=DamageMessage?" << std::endl;
    std::cout << messageSystem.count(1) << std::endl;

    //How many messages are active with typeID=2 aka type=HealingMessage?
    std::cout << "How many messages are active with typeID=2 aka type=HealingMessage?" << std::endl;
    std::cout << messageSystem.count(2) << std::endl;

    //***Let's print now all active messages of same type where typeID=2 aka type=HealingMessage***
    std::cout << "*** Let's print now all active messages of same type where typeID=2 aka type=HealingMessage ***" << std::endl;
    messageSystem.printAllActiveMessagesOfSameType(2);

    //***Let's print message with index=0***
    std::cout << "*** Let's print message with index = 0 ***" << std::endl;
    messageSystem.getMessage(0)->printMessage();

    //Sending messages 
    MessageQueue multiMessageQueue;
    multiMessageQueue.enqueue(std::make_shared<MissionCompletedMessage>());
    multiMessageQueue.enqueue(std::make_shared<MissionCompletedMessage>());
    multiMessageQueue.enqueue(std::make_shared<MissionCompletedMessage>());
    multiMessageQueue.commit();
    std::cout << "--- Sending multiple messages at once from another queue: ---" << std::endl;
    messageSystem.send(multiMessageQueue.begin(), multiMessageQueue.end());
    messageSystem.commitAll();
    messageSystem.printAllActiveMessages();
}

int main(int argc, char** argv)
{

    MessageSystem messageSystem;
    testingMessageSystem(messageSystem);
 
    return 0;
}




