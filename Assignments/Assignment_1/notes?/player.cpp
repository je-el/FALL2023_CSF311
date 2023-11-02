#include "player.hpp"
#include <cassert>

// Constructors
Player::Player() : realName("UNKNOWN"), username("UNKNOWN"), games(0) {}

Player::Player(const std::string& realName, const std::string& username, int gamesPlayed)
    : realName(realName), username(username), games(gamesPlayed) {
    assert(gamesPlayed >= 0);
}

// Getters
std::string Player::getRealName() const {
    return realName;
}

std::string Player::getUsername() const {
    return username;
}

int Player::getGames() const {
    return games;
}

// Setters
void Player::setRealName(const std::string& realName) {
    this->realName = realName;
}

void Player::setUsername(const std::string& username) {
    this->username = username;
}

void Player::setGames(int games) {
    assert(games >= 0); //serves as a defensive check to ensure that the geams member variable isn;t being improperly modified somewhere else to be negative
    this->games = games;
}

// Other member functions
bool Player::inactive() const {
    return games == 0;
}

std::string Player::toString() const {
    return realName + " (" + username + "): " + std::to_string(games);
}

// Operators
Player& Player::operator++() {
    ++games;
    return *this;
}

Player Player::operator++(int) {
    Player tmp(*this);
    ++(*this);
    return tmp;
}

Player& Player::operator--() {
    if (games > 0) --games;
    return *this;
}

Player Player::operator--(int) {
    Player tmp(*this);
    --(*this);
    return tmp;
}

bool operator==(const Player& lval, const Player& rval) {
    return lval.realName == rval.realName && lval.username == rval.username && lval.games == rval.games;
}

bool operator!=(const Player& lval, const Player& rval) {
    return !(lval == rval);
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << player.toString();
    return os;
}
