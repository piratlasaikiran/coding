/*
std::lock(m1, m2, m3)..
1. all arguments are locked via sequence of calls to lock(), try_lock() or unlock()
2. order of locking is not defined

Example1 No deadlock

Thread1                          Thread2
std::lock(m1, m2);               std::lock(m1, m2);
---------------------------------------------------

Example2 No deadlock

Thread1                          Thread2
std::lock(m1, m2);               std::lock(m2, m1);
---------------------------------------------------

Example3 No deadlock

Thread1                          Thread2
std::lock(m1, m2, m3, m4);       std::lock(m3, m4);
                                 std::lock(m2, m1);
---------------------------------------------------

Example3 Deadlock

Thread1                          Thread2
std::lock(m1, m2)                std::lock(m3, m4);
std::lock(m3, m4);               std::lock(m2, m1);