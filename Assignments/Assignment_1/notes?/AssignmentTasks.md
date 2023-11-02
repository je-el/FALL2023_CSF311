Sure, let's break down the assignment requirements into a checklist:

1. **File and Class Structure**
    - [x] Class named “Player”.
    - [x] Implementation in files player.hpp and player.cpp.

2. **Data Members**
    - [x] A string holding a game player’s real name.
    - [x] A string holding the player’s username.
    - [x] A nonnegative integer for the number of games played.

3. **Special Member Functions (Automatically Generated)**
    - [x] Copy constructor.
    - [x] Move constructor.
    - [x] Copy assignment.
    - [x] Move assignment.
    - [x] Destructor.

4. **Other Constructors**
    - [x] Default constructor (with "UNKNOWN" and 0 initialization).
    - [x] 3-parameter constructor.

5. **Getter and Setter Functions**
    - [x] getRealName.
    - [x] getUsername.
    - [x] getGames.
    - [x] setRealName.
    - [x] setUsername.
    - [x] setGames.

6. **Additional Member Functions**
    - [x] `inactive` member function.
    - [x] `toString` member function.

7. **Operator Overloading**
    - [x] Equality (“==”) and inequality (“!=”).
    - [x] Pre- and post-increment operators (“++”).
    - [x] Pre- and post-decrement operators (“--”).
    - [x] Stream insertion (“<<”) operator.

8. **Type Handling**
    - [x] All strings using `std::string`.
    - [x] All numbers using type `int`.

9. **Assertions**
    - [x] Asserts to ensure the `games` value is non-negative in appropriate places (e.g., constructors, setters).
    - Note: There might be more assertions needed based on the specifics of the `player_test.cpp` test cases. 

10. **Code Quality**
    - [x] No unnecessary verbosity for bool values.
    - [x] Avoided unnecessary duplication of code.
    - [x] Comments for better understanding.

11. **Test Program**
    - [] Needs to be tested against the provided `player_test.cpp`. 
