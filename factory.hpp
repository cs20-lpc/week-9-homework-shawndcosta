#include "Queue.hpp"
#include "LinkedQueue.hpp"
#include "ArrayQueue.hpp"

class QueueFactory {
public:
    template <typename T>
    static Queue<T>* getQueue() {
        return new LinkedQueue<T>();
    }
    
    template <typename T>
    static Queue<T>* getQueue(int capacity) {
        return new ArrayQueue<T>(capacity);
    }
};

