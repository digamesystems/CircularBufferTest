
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

#include <CircularBuffer.h>   // Roberto's / Adafruit's library for handling circular buffers of data. 

CircularBuffer<String*, 50> msgBuffer;


void setup() {
  
  Serial.begin(115200);
  delay(1000);
  
  // put your setup code here, to run once:
  Serial.print("Free Heap: ");
  Serial.println(ESP.getFreeHeap()); // Before.

  
  Serial.print("msgBuffer.size(): ");
  Serial.println(msgBuffer.size());
  for (int i=0; i<50; i++){
    String * test = new String("hello " + String(i)); // Create a new String object.
    msgBuffer.push(test);  
  }

  Serial.print("msgBuffer.size(): ");
  Serial.println(msgBuffer.size());
  Serial.print("Free Heap: ");
  Serial.println(ESP.getFreeHeap());  // After allocation.

  for (int i=0; i<50; i++){
    Serial.println( msgBuffer[i]->c_str());
  }

  Serial.print("Free Heap: ");
  Serial.println(ESP.getFreeHeap());
  
  for (int i=0; i<50; i++){
    String * entry = msgBuffer.shift();
    delete entry; // Free the memory we allocated earlier for the String.
  }

  Serial.print("msgBuffer.size(): ");
  Serial.println(msgBuffer.size());
  
  Serial.print("Free Heap: ");
  Serial.println(ESP.getFreeHeap());  // After deallocation. (Should be the same as before.)
  
}

void loop() {
  // This never runs. All the action is in setup!
}
