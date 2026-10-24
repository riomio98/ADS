#include "alltest.h"
#include "flexqueue.h"

TEST(FlexQueue, InitEmpty) {
    flexqueue q;
    fqueue_init(&q);
    EXPECT_TRUE(fqueue_is_empty(&q));
    EXPECT_EQ(fqueue_size(&q), 0);
    fqueue_clear(&q);
}

TEST(FlexQueue, SingleElement) {
    flexqueue q;
    fqueue_init(&q);
    fqueue_enter(&q, 42);
    EXPECT_FALSE(fqueue_is_empty(&q));
    EXPECT_EQ(fqueue_size(&q), 1);
    EXPECT_EQ(fqueue_front(&q), 42);
    EXPECT_EQ(fqueue_leave(&q), 42);
    EXPECT_TRUE(fqueue_is_empty(&q));
    fqueue_clear(&q);
}

TEST(FlexQueue, FIFO) {
    flexqueue q;
    fqueue_init(&q);
    fqueue_enter(&q, 1);
    fqueue_enter(&q, 2);
    fqueue_enter(&q, 3);
    EXPECT_EQ(fqueue_leave(&q), 1);
    EXPECT_EQ(fqueue_leave(&q), 2);
    EXPECT_EQ(fqueue_leave(&q), 3);
    fqueue_clear(&q);
}

TEST(FlexQueue, SizeTracking) {
    flexqueue q;
    fqueue_init(&q);
    for (int i = 0; i < 5; ++i) {
        fqueue_enter(&q, i);
        EXPECT_EQ(fqueue_size(&q), i + 1);
    }
    for (int i = 5; i > 0; --i) {
        EXPECT_EQ(fqueue_size(&q), i);
        fqueue_leave(&q);
    }
    fqueue_clear(&q);
}

TEST(FlexQueue, WrapAround) {
    // Teste Ringpuffer: erst füllen, teils leeren, wieder füllen
    flexqueue q;
    fqueue_init(&q);
    for (int i = 0; i < 5; ++i) {
        fqueue_enter(&q, i);
    }
    for (int i = 0; i < 3; ++i) {
        EXPECT_EQ(fqueue_leave(&q), i);
    }
    // Jetzt: head > 0, tail bei 5
    for (int i = 10; i < 15; ++i) {
        fqueue_enter(&q, i);
    }
    // Restliche Elemente prüfen
    EXPECT_EQ(fqueue_leave(&q), 3);
    EXPECT_EQ(fqueue_leave(&q), 4);
    for (int i = 10; i < 15; ++i) {
        EXPECT_EQ(fqueue_leave(&q), i);
    }
    fqueue_clear(&q);
}

TEST(FlexQueue, Expand) {
    flexqueue q;
    fqueue_init(&q);
    // Mehr als initiale Kapazität (8) einfügen
    for (int i = 0; i < 20; ++i) {
        fqueue_enter(&q, i);
    }
    EXPECT_EQ(fqueue_size(&q), 20);
    // FIFO muss erhalten bleiben
    for (int i = 0; i < 20; ++i) {
        EXPECT_EQ(fqueue_leave(&q), i);
    }
    fqueue_clear(&q);
}

TEST(FlexQueue, ExpandPreservesFIFO) {
    // Expand bei Wrap-Around: Reihenfolge muss stimmen
    flexqueue q;
    fqueue_init(&q);
    for (int i = 0; i < 6; ++i) {
        fqueue_enter(&q, i);
    }
    for (int i = 0; i < 4; ++i) {
        fqueue_leave(&q);
    }
    // head ist jetzt bei 4, tail bei 6
    for (int i = 100; i < 110; ++i) {
        fqueue_enter(&q, i);
    }
    // Expand muss Reihenfolge erhalten
    EXPECT_EQ(fqueue_leave(&q), 4);
    EXPECT_EQ(fqueue_leave(&q), 5);
    for (int i = 100; i < 110; ++i) {
        EXPECT_EQ(fqueue_leave(&q), i);
    }
    fqueue_clear(&q);
}

TEST(FlexQueue, Shrink) {
    flexqueue q;
    fqueue_init(&q);
    // Erst vergrößern
    for (int i = 0; i < 100; ++i) {
        fqueue_enter(&q, i);
    }
    // Fast alles entfernen -> sollte schrumpfen
    for (int i = 0; i < 95; ++i) {
        EXPECT_EQ(fqueue_leave(&q), i);
    }
    // Rest prüfen
    for (int i = 95; i < 100; ++i) {
        EXPECT_EQ(fqueue_leave(&q), i);
    }
    fqueue_clear(&q);
}

TEST(FlexQueue, MinimalCapacity) {
    flexqueue q;
    fqueue_init(&q);
    fqueue_enter(&q, 1);
    fqueue_leave(&q);
    // Kapazität darf nicht unter 8 sinken
    EXPECT_EQ(fqueue_size(&q), 0);
    // Sollte nicht abstürzen
    fqueue_enter(&q, 2);
    EXPECT_EQ(fqueue_leave(&q), 2);
    fqueue_clear(&q);
}

TEST(FlexQueue, ManyOperations) {
    flexqueue q;
    fqueue_init(&q);
    // Abwechselnd einfügen und entfernen
    for (int round = 0; round < 100; ++round) {
        for (int i = 0; i < 10; ++i) {
            fqueue_enter(&q, round * 10 + i);
        }
        for (int i = 0; i < 5; ++i) {
            EXPECT_EQ(fqueue_leave(&q), round * 5 + i);
        }
    }
    fqueue_clear(&q);
}
