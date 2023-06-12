#include<iostream>
#include <string>
#include <ctype.h>
#include <assert.h>

namespace CB{
typedef struct {
    u_int8_t *buffer;
    size_t head;
    size_t tail;
    size_t max; // buffer maz size
    bool full;
} c_buffer;

typedef c_buffer *cbuf_handle_t;

/* Adding and removing data from a circular buffer requires manipulation of the head and tail pointers. 
 When adding data to the buffer, we insert the new value at the current head location, then we advance head.
 When we remove data from the buffer, we retrieve the value of the current tail pointer and then advance tail.
*/
static void advance_pointer(cbuf_handle_t me) {
    assert(me);
    if(me->full) {
        if(++(me->tail) == me->max) {
            me->tail = 0;
        }
    }

    if (++(me->head) == me->max) {
        me->head = 0;
    }
    me->full = (me->head == me->tail);
}

static void retreat_pointer(cbuf_handle_t me) {
    assert(me);

    me->full = false;
    if(++(me->tail) == me->max) {
        me->tail = 0;
    }
}

class CircularBuffer
{
private:
    /* data */
    size_t buffer_size;

public:
    CircularBuffer(/* args */);
    ~CircularBuffer();

    // Pass in a storage buffer and size 
    // Returns a circular buffer handle
    cbuf_handle_t circular_buf_init(u_int8_t* buffer, size_t size);

    // Free a circular buffer structure.
    // Does not free data buffer; owner is responsible for that
    void circular_buf_free(cbuf_handle_t me);

    /// Reset the circular buffer to empty, head == tail
    void circular_buf_reset(cbuf_handle_t me);

    /// Put version 1 continues to add data if the buffer is full
    /// Old data is overwritten
    void circular_buf_put(cbuf_handle_t me, u_int8_t data);

    /// Put Version 2 rejects new data if the buffer is full
    /// Returns 0 on success, -1 if buffer is full
    int circular_buf_put2(cbuf_handle_t me, u_int8_t data);

    /// Retrieve a value from the buffer
    /// Returns 0 on success, -1 if the buffer is empty
    int circular_buf_get(cbuf_handle_t me, u_int8_t *data);

    /// Returns true if the buffer is empty
    bool circular_buf_empty(cbuf_handle_t me);

    /// Returns true if the buffer is full
    bool circular_buf_full(cbuf_handle_t me);

    /// Returns the maximum capacity of the buffer
    size_t circular_buf_capacity(cbuf_handle_t me);

    /// Returns the current number of elements in the buffer
    size_t circular_buf_size(cbuf_handle_t me);

};

CircularBuffer::CircularBuffer(/* args */):buffer_size(0)
{
}

CircularBuffer::~CircularBuffer()
{
}

cbuf_handle_t CircularBuffer::circular_buf_init(u_int8_t *buffer, size_t size) {
    assert(buffer && size);

    cbuf_handle_t cbuf = new c_buffer;
    assert(cbuf);

    cbuf->buffer = buffer;
    cbuf->max = size;
    circular_buf_reset(cbuf); // Reset the circular buffer to empty, head == tail

    assert(circular_buf_empty(cbuf));
    
    return cbuf;
}

void CircularBuffer::circular_buf_reset(cbuf_handle_t me) {
    assert(me);

    me->head = 0;
    me->tail = 0;
    me->full = false;
}

void CircularBuffer::circular_buf_free(cbuf_handle_t me) {
    assert(me);
    delete me;
}

bool CircularBuffer::circular_buf_full(cbuf_handle_t me) {
    assert(me);
    
    return me->full;
}

bool CircularBuffer::circular_buf_empty(cbuf_handle_t me) {
    assert(me);

    return (!me->full &&(me->head == me->tail));
}

size_t CircularBuffer::circular_buf_capacity(cbuf_handle_t me) {
    assert(me);

    return me->max;
}

size_t CircularBuffer::circular_buf_size(cbuf_handle_t me) {
    assert(me);

    size_t size = me->max;

    if(!me->full) {
        if(me->head >= me->tail) {
            size = (me->head - me->tail);
        }
        else {
            size = ((me->max + me->head) - me->tail);
        }
    }
    return size;
}

void CircularBuffer::circular_buf_put(cbuf_handle_t me, uint8_t data) {
    assert(me && me->buffer);
    me->buffer[me->head] = data;
    advance_pointer(me);
}

int CircularBuffer::circular_buf_put2(cbuf_handle_t me, uint8_t data) {
    int r = -1; // Error code to be returned if buffer is full

    assert(me && me->buffer);

    if(!circular_buf_full(me)) {
        me->buffer[me->head] = data;
        advance_pointer(me);
        r = 0;
    }

    return r;
}

int CircularBuffer::circular_buf_get(cbuf_handle_t me, uint8_t *data) {
    int r = -1; // Error code to be returned in case buffer is empty

    assert(me && data && me->buffer);

    if(!circular_buf_empty(me)) {
        *data = me->buffer[me->tail];
        retreat_pointer(me);
        r = 0;
    }
    
    return r;
}


} // namespace end

#define SIZE 8

int main() {
    // Defined buffer
    uint8_t *buffer = new uint8_t[SIZE];
    
    // Create object
    CB::CircularBuffer static_size_buffer;

    // Init the handler
    CB::cbuf_handle_t me = static_size_buffer.circular_buf_init(buffer, SIZE);
    
    std::cout<<static_size_buffer.circular_buf_capacity(me)<<std::endl;

    // static_size_buffer.circular_buf_put(me, 'a');

    for (int i = 97; i < 105; i++) {
        static_size_buffer.circular_buf_put(me, i);
    }

    uint8_t *buf = new uint8_t;
    for (int i = 0; i < SIZE; i++) {
        if (!static_size_buffer.circular_buf_get(me, buf)) {
            std::cout<<*buf<<std::endl;
        }        
    }

    static_size_buffer.circular_buf_free(me);

    return 0;
}