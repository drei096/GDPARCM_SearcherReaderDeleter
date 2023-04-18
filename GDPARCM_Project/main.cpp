/*
 * UNCOMMENT TO RUN ASSET LOADER
 *
#include <SFML/Graphics.hpp>
#include "Application.h"

int main()
{
    Application app;
    app.run();

    return 0;
}
*/



/*
 *  CODE FOR PRODUCER-CONSUMER IMPLEMENTATION USING SEMAPHORES, COMMENT IF YOU NEED TO RUN ASSET LOADER
 */
#include <iostream>
#include "ProducerThread.h"
#include "ConsumerThread.h"
#include "SharedDataBuffer.h"
#include "SemaphoreObject.h"
#include "ConsoleSynchronizer.h"

int main()
{
    // create data structures for threads
    std::vector<ProducerThread*> prodThreadList;
    std::vector<ConsumerThread*> consThreadList;
    ConsoleSynchronizer* csyncer = new ConsoleSynchronizer();


    int producerCount;
    int consumerCount;

    std::cin >> producerCount;
    std::cin >> consumerCount;

    // shared data buffer that contains the vector of ints, as well as the prod, cons, and mutex semaphores
    SharedDataBuffer* sharedData = new SharedDataBuffer(producerCount, consumerCount, csyncer);


    // create producers acc to user input
    for(int i = 0; i < producerCount; i++)
    {
        ProducerThread* prodThread = new ProducerThread(sharedData, i);
        prodThreadList.push_back(prodThread);
        prodThread->ScheduleThreadForExecution();
    }

    // create consumers acc to user input
    for (int i = 0; i < consumerCount; i++)
    {
        ConsumerThread* consThread = new ConsumerThread(sharedData, i);
        consThreadList.push_back(consThread);
        consThread->ScheduleThreadForExecution();
    }

    // forever wait
    while (true);


    return 0;
}