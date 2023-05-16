#include "WordCount.h"
#include "tddFuncs.h"

int main()
{
    WordCount w;
    
    // incrWordCount
    assertEquals(1, w.incrWordCount("hi"), "Error: w.incrWordCount() should return 1.", 11);
    //assertEquals(2, w.incrWordCount("Hi"), "Error: w.incrWordCount() should return 2.", 12);
    //assertEquals(3, w.incrWordCount("-H@I'"), "Error: w.incrWordCount() should return 3.", 13);

    // getTotalWords
    //assertEquals(3, w.getTotalWords(), "Error: w.getTotalWords() should return 3.", 16);

    // getNumUniqueWords
    //assertEquals(1, w.getNumUniqueWords(), "Error: w.getNumUniqueWords() should return 1.", 19);

    // decrWordCount
    //assertEquals(2, w.decrWordCount("HI"), "Error: w.decrWordCount() should return 2.", 22);
    //assertEquals(-1, w.decrWordCount("bye"), "Error: w.decrWordCount() should return -1.", 23);

    //assertEquals(2, w.getTotalWords(), "Error: w.getTotalWords() shoudl return 2.", 25);

    //assertEquals(1, w.getNumUniqueWords(), "Error: w.getNumUniqueWords() should return 1.", 27);

    return 0;
}
