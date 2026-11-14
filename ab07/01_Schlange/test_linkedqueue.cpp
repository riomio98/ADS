#include "alltest.h"
#include "linkedqueue.h"
#include <string>

using namespace std;

TEST(LinkedQueue, InitEmpty) {
    linked_queue lq;
    lqueue_init(&lq);
    EXPECT_TRUE(lqueue_is_empty(&lq));
    EXPECT_EQ(lqueue_size(&lq), 0);
    lqueue_clear(&lq);
}

TEST(LinkedQueue, SingleElement) {
    linked_queue lq;
    lqueue_init(&lq);
    lqueue_enter(&lq, "hello");
    EXPECT_FALSE(lqueue_is_empty(&lq));
    EXPECT_EQ(lqueue_size(&lq), 1);
    EXPECT_EQ(lqueue_leave(&lq), "hello");
    EXPECT_TRUE(lqueue_is_empty(&lq));
    lqueue_clear(&lq);
}

TEST(LinkedQueue, FIFO) {
    linked_queue lq;
    lqueue_init(&lq);
    lqueue_enter(&lq, "eins");
    lqueue_enter(&lq, "zwei");
    lqueue_enter(&lq, "drei");
    EXPECT_EQ(lqueue_leave(&lq), "eins");
    EXPECT_EQ(lqueue_leave(&lq), "zwei");
    EXPECT_EQ(lqueue_leave(&lq), "drei");
    lqueue_clear(&lq);
}

TEST(LinkedQueue, SizeTracking) {
    linked_queue lq;
    lqueue_init(&lq);
    for (int i = 0; i < 5; ++i) {
        lqueue_enter(&lq, to_string(i));
        EXPECT_EQ(lqueue_size(&lq), i + 1);
    }
    for (int i = 5; i > 0; --i) {
        EXPECT_EQ(lqueue_size(&lq), i);
        lqueue_leave(&lq);
    }
    lqueue_clear(&lq);
}

TEST(LinkedQueue, EmptyAfterRemove) {
    // Typischer Fehler: last-Pointer nicht auf nullptr gesetzt
    linked_queue lq;
    lqueue_init(&lq);
    lqueue_enter(&lq, "x");
    lqueue_leave(&lq);
    EXPECT_TRUE(lqueue_is_empty(&lq));
    // Danach wieder einfügen muss funktionieren
    lqueue_enter(&lq, "y");
    EXPECT_EQ(lqueue_size(&lq), 1);
    EXPECT_EQ(lqueue_leave(&lq), "y");
    lqueue_clear(&lq);
}

TEST(LinkedQueue, RepeatedEmptyFill) {
    // Mehrfach leeren und füllen
    linked_queue lq;
    lqueue_init(&lq);
    for (int round = 0; round < 5; ++round) {
        for (int i = 0; i < 10; ++i) {
            lqueue_enter(&lq, to_string(i));
        }
        for (int i = 0; i < 10; ++i) {
            EXPECT_EQ(lqueue_leave(&lq), to_string(i));
        }
        EXPECT_TRUE(lqueue_is_empty(&lq));
    }
    lqueue_clear(&lq);
}

TEST(LinkedQueue, ManyElements) {
    linked_queue lq;
    lqueue_init(&lq);
    for (int i = 0; i < 1000; ++i) {
        lqueue_enter(&lq, to_string(i));
    }
    EXPECT_EQ(lqueue_size(&lq), 1000);
    for (int i = 0; i < 1000; ++i) {
        EXPECT_EQ(lqueue_leave(&lq), to_string(i));
    }
    lqueue_clear(&lq);
}

TEST(LinkedQueue, AlternatingEnterLeave) {
    // Abwechselnd einfügen und entfernen
    linked_queue lq;
    lqueue_init(&lq);
    for (int i = 0; i < 100; ++i) {
        lqueue_enter(&lq, to_string(i));
        EXPECT_EQ(lqueue_leave(&lq), to_string(i));
        EXPECT_TRUE(lqueue_is_empty(&lq));
    }
    lqueue_clear(&lq);
}

TEST(LinkedQueue, TwoElements) {
    // Typischer Fehler: Pointer-Update bei genau 2 Elementen
    linked_queue lq;
    lqueue_init(&lq);
    lqueue_enter(&lq, "a");
    lqueue_enter(&lq, "b");
    EXPECT_EQ(lqueue_leave(&lq), "a");
    EXPECT_EQ(lqueue_size(&lq), 1);
    EXPECT_EQ(lqueue_leave(&lq), "b");
    EXPECT_TRUE(lqueue_is_empty(&lq));
    lqueue_clear(&lq);
}

TEST(LinkedQueue, ClearNonEmpty) {
    // Clear bei nicht-leerer Queue
    linked_queue lq;
    lqueue_init(&lq);
    for (int i = 0; i < 10; ++i) {
        lqueue_enter(&lq, to_string(i));
    }
    lqueue_clear(&lq);
    // Nach clear wieder benutzbar
    lqueue_init(&lq);
    lqueue_enter(&lq, "neu");
    EXPECT_EQ(lqueue_leave(&lq), "neu");
    lqueue_clear(&lq);
}
