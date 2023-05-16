#include "WordCount.h"
#include "tddFuncs.h"

int main()
{
    WordCount w;
    
    // incrWordCount
    ASSERT_EQUALS(1, w.incrWordCount("hi"));
    ASSERT_EQUALS(2, w.incrWordCount("Hi"));
    ASSERT_EQUALS(3, w.incrWordCount("-H@I'"));

    // getTotalWords
    ASSERT_EQUALS(3, w.getTotalWords());

    // getNumUniqueWords
    ASSERT_EQUALS(1, w.getNumUniqueWords());

    // decrWordCount
    ASSERT_EQUALS(2, w.decrWordCount("HI"));
    ASSERT_EQUALS(-1, w.decrWordCount("bye"));

    ASSERT_EQUALS(2, w.getTotalWords());

    ASSERT_EQUALS(1, w.getNumUniqueWords());

    return 0;
}
