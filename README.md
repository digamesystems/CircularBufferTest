# CircularBufferTest
Example program on how to work with dynamically allocated Strings and the CircularBuffer.h library.

/* circularBufferTest 
 * ------------------
 *
 *  An example on how to manage dynamic memory, on the ESP32 using Roberto Lo Giacco's CircularBuffer library. 
 *  https://www.arduino.cc/reference/en/libraries/circularbuffer/
 *   
 *  Here I use the buffer to store references to a bunch of String objects. 
 *  https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/ 
 *   
 *  Roberto's library requires that you clean up dynamically loaded objects that are referenced in the buffer when 
 *  doing shift / pop operations to unload them from the buffer.
 *  
 *  I use the ESP32 on many of my projects which has nice functions for monitoring heap allocation. This can really 
 *  help root out memory leaks. 
 *  
 *  Below is an example for the Arduino IDE that dynamically allocates String classes where references to them are stored 
 *  in the buffer. The program keeps track of the heap before, during and after working with the buffer.
 *  
 *  Many folks using the String class and have strange memory problems from not cleaning up properly.
 *  
 *  Hopefully, this helps a bit.
 *  
 *  Written by John Price, Digame Systems (www.digamesystems.com)
 *  Free for any use. No warranty implied. Your milage may vary. 
 *  
 *  Comments / improvements / suggestions are welcomed.  
 *  
 *  :)
 *  
 */
